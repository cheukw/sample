#include "net/inner_pre.h"

#include "net/libevent_headers.h"
#include "net/libevent_watcher.h"
#include "net/event_loop.h"
#include "net/invoke_timer.h"

EventLoop::EventLoop()
    : create_evbase_myself_(true), notified_(false), pending_functor_count_(0) {
#if LIBEVENT_VERSION_NUMBER >= 0x02001500
    struct event_config* cfg = event_config_new();
    if (cfg) {
        // Does not cache time to get a preciser timer
        event_config_set_flag(cfg, EVENT_BASE_FLAG_NO_CACHE_TIME);
        evbase_ = event_base_new_with_config(cfg);
        event_config_free(cfg);
    }
#else
    evbase_ = event_base_new();
#endif
    Init();
}

EventLoop::EventLoop(struct event_base* base)
    : evbase_(base)
	, create_evbase_myself_(false)
	, notified_(false)
	, pending_functor_count_(0) 
{
    Init();

    // When we build an EventLoop object from an existing event_base object
    // we won't call EventLoop::Run method.
    // So we need to do the initialization work of watcher_ here.
    InitEventWatcher();
}

void EventLoop::InitEventWatcher() {
    watcher_.reset(new PipeEventWatcher(this, std::bind(&EventLoop::DoPendingFunctors, this)));
    int rc = watcher_->Init();
    assert(rc);
    rc = rc && watcher_->AsyncWait();
    assert(rc);
    if (!rc) {
    }
}

EventLoop::~EventLoop() {
    if (!create_evbase_myself_) {
        assert(watcher_);
        watcher_.reset();
    }
    assert(!watcher_.get());

    if (evbase_ != nullptr && create_evbase_myself_) {
        event_base_free(evbase_);
        evbase_ = nullptr;
    }

    delete pending_functors_;
    pending_functors_ = nullptr;
}

void EventLoop::Init() {
    this->pending_functors_ = new std::vector<Functor>();
    running_ = false;
    tid_ = std::this_thread::get_id(); // The default thread id
}

void EventLoop::Run() {
    tid_ = std::this_thread::get_id(); // The actual thread id

    // Initialize it in the EventLoop thread
    InitEventWatcher();

    // After everything have initialized, mark this running_ flag to true
    running_ = true;

    int rc = event_base_dispatch(evbase_);
    if (rc == 1) {
    } else if (rc == -1) {
       
    }

    // Make sure watcher_ does construct,initialize and destruct in the same thread.
    watcher_.reset();
    running_ = false;
}


void EventLoop::Stop() {
    assert(running_);
    RunInLoop(std::bind(&EventLoop::StopInLoop, this));
}

void EventLoop::StopInLoop() {
    assert(running_);

    auto f = [this]() {
        for (;;) {
            DoPendingFunctors();
            std::lock_guard<std::mutex> lock(mutex_);
            if (pending_functors_->empty()) {
                break;
            }
        }
    };
    f();

#ifdef H_BENCHMARK_TESTING
    event_base_loopexit(evbase_, NULL);
#else
    timeval tv = Duration(0.5).TimeVal(); // Trick : delay 0.5 second
    event_base_loopexit(evbase_, &tv);
#endif
    f();
    running_ = false;
}

void EventLoop::AfterFork() {
    int rc = event_reinit(evbase_);
    assert(rc == 0);

    if (rc != 0) {
        fprintf(stderr, "event_reinit failed!\n");
        abort();
    }
}

InvokeTimerPtr EventLoop::RunAfter(double delay_ms, const Functor& f) {
    return RunAfter(Duration(delay_ms / 1000.0), f);
}

InvokeTimerPtr EventLoop::RunAfter(Duration delay, const Functor& f) {
    std::shared_ptr<InvokeTimer> t = InvokeTimer::Create(this, delay, f, false);
    t->Start();
    return t;
}

InvokeTimerPtr EventLoop::RunEvery(Duration interval, const Functor& f) {
    std::shared_ptr<InvokeTimer> t = InvokeTimer::Create(this, interval, f, true);
    t->Start();
    return t;
}

void EventLoop::RunInLoop(const Functor& functor) {
    if (IsInLoopThread()) {
        functor();
    } else {
        QueueInLoop(functor);
    }
}

void EventLoop::QueueInLoop(const Functor& cb) {
	{
        std::lock_guard<std::mutex> lock(mutex_);
        pending_functors_->emplace_back(cb);

    }
    ++pending_functor_count_;
    if (!notified_.load()) {
        watcher_->Notify();

        //TODO This will cause a bug : miss the notify event and make the functor will never be called.
        //TODO performance improvement.
        //notified_.store(true);
    } else {
        //LOG_INFO << "this=" << this << " tid=" << std::this_thread::get_id() << " No need to call watcher_->Nofity()";
    }
}

void EventLoop::QueueInLoop(Functor&& cb) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        pending_functors_->emplace_back(std::move(cb));
    }
    ++pending_functor_count_;
    if (!notified_.load()) {
        watcher_->Notify();
        //TODO This will cause a bug : miss the notify event and make the functor will never be called.
        //TODO performance improvement.
        //notified_.store(true);
    } else {
        
    }
}

InvokeTimerPtr EventLoop::RunAfter(double delay_ms, Functor&& f) {
    return RunAfter(Duration(delay_ms / 1000.0), std::move(f));
}

InvokeTimerPtr EventLoop::RunAfter(Duration delay, Functor&& f) {
    std::shared_ptr<InvokeTimer> t = InvokeTimer::Create(this, delay, std::move(f), false);
    t->Start();
    return t;
}

InvokeTimerPtr EventLoop::RunEvery(Duration interval, Functor&& f) {
    std::shared_ptr<InvokeTimer> t = InvokeTimer::Create(this, interval, std::move(f), true);
    t->Start();
    return t;
}

void EventLoop::RunInLoop(Functor&& functor) {
    if (IsInLoopThread()) {
        functor();
    } else {
        QueueInLoop(std::move(functor));
    }
}

void EventLoop::DoPendingFunctors() {
 
    std::vector<Functor> functors;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        notified_.store(false);
        pending_functors_->swap(functors);
    }
   
    for (size_t i = 0; i < functors.size(); ++i) {
        functors[i]();
        --pending_functor_count_;
    }
}

void EventLoop::AssertInLoopThread() const {
    assert(IsInLoopThread());
}
