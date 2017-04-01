# 1 "ev.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ev.c"
# 45 "ev.c"
# 1 "config.h" 1
# 46 "ev.c" 2
# 167 "ev.c"
# 168 "ev.h" 2





# 172 "ev.h"
struct ev_loop;
# 217 "ev.h"
enum {
  EV_UNDEF = (int)0xFFFFFFFF,
  EV_NONE = 0x00,
  EV_READ = 0x01,
  EV_WRITE = 0x02,
  EV__IOFDSET = 0x80,
  EV_IO = EV_READ,
  EV_TIMER = 0x00000100,

  EV_TIMEOUT = EV_TIMER,

  EV_PERIODIC = 0x00000200,
  EV_SIGNAL = 0x00000400,
  EV_CHILD = 0x00000800,
  EV_STAT = 0x00001000,
  EV_IDLE = 0x00002000,
  EV_PREPARE = 0x00004000,
  EV_CHECK = 0x00008000,
  EV_EMBED = 0x00010000,
  EV_FORK = 0x00020000,
  EV_CLEANUP = 0x00040000,
  EV_ASYNC = 0x00080000,
  EV_CUSTOM = 0x01000000,
  EV_ERROR = (int)0x80000000
};
# 298 "ev.h"
typedef struct ev_watcher
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_watcher *w, int revents);
} ev_watcher;


typedef struct ev_watcher_list
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_watcher_list *w, int revents); 
  struct ev_watcher_list *next;
} ev_watcher_list;


typedef struct ev_watcher_time
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_watcher_time *w, int revents); 
  ev_tstamp at;
} ev_watcher_time;



typedef struct ev_io
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_io *w, int revents); 
  struct ev_watcher_list *next;
  int fd;
  int events;
} ev_io;



typedef struct ev_timer
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_timer *w, int revents); 
  ev_tstamp at;
  ev_tstamp repeat;
} ev_timer;



typedef struct ev_periodic
{
  int active; 
  int pending; 
  int priority;
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_periodic *w, int revents); 
  ev_tstamp at;

  ev_tstamp offset;
  ev_tstamp interval;
  ev_tstamp (*reschedule_cb)(struct ev_periodic *w, ev_tstamp now) throw ();
} ev_periodic;



typedef struct ev_signal
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_signal *w, int revents); 
  struct ev_watcher_list *next;

  int signum;
} ev_signal;




typedef struct ev_child
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_child *w, int revents); 
  struct ev_watcher_list *next;

  int flags;
  int pid;
  int rpid;
  int rstatus;
} ev_child;




typedef struct _stati64 ev_statdata;






typedef struct ev_stat
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_stat *w, int revents); 
  struct ev_watcher_list *next;

  ev_timer timer;
  ev_tstamp interval;
  const char *path;
  ev_statdata prev;
  ev_statdata attr;

  int wd;
} ev_stat;





typedef struct ev_idle
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_idle *w, int revents);
} ev_idle;





typedef struct ev_prepare
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_prepare *w, int revents);
} ev_prepare;



typedef struct ev_check
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_check *w, int revents);
} ev_check;




typedef struct ev_fork
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_fork *w, int revents);
} ev_fork;





typedef struct ev_cleanup
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_cleanup *w, int revents);
} ev_cleanup;





typedef struct ev_embed
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_embed *w, int revents);

  struct ev_loop *other;
  ev_io io;
  ev_prepare prepare;
  ev_check check;
  ev_timer timer;
  ev_periodic periodic;
  ev_idle idle;
  ev_fork fork;

  ev_cleanup cleanup;

} ev_embed;





typedef struct ev_async
{
  int active; 
  int pending; 
  int priority; 
  void *data; 
  void (*cb)(struct ev_loop *loop, struct ev_async *w, int revents);

  sig_atomic_t volatile sent;
} ev_async;





union ev_any_watcher
{
  struct ev_watcher w;
  struct ev_watcher_list wl;

  struct ev_io io;
  struct ev_timer timer;
  struct ev_periodic periodic;
  struct ev_signal signal;
  struct ev_child child;

  struct ev_stat stat;


  struct ev_idle idle;

  struct ev_prepare prepare;
  struct ev_check check;

  struct ev_fork fork;


  struct ev_cleanup cleanup;


  struct ev_embed embed;


  struct ev_async async;

};


enum {

  EVFLAG_AUTO = 0x00000000U,

  EVFLAG_NOENV = 0x01000000U,
  EVFLAG_FORKCHECK = 0x02000000U,

  EVFLAG_NOINOTIFY = 0x00100000U,

  EVFLAG_NOSIGFD = 0,

  EVFLAG_SIGNALFD = 0x00200000U,
  EVFLAG_NOSIGMASK = 0x00400000U
};


enum {
  EVBACKEND_SELECT = 0x00000001U,
  EVBACKEND_POLL = 0x00000002U,
  EVBACKEND_EPOLL = 0x00000004U,
  EVBACKEND_KQUEUE = 0x00000008U,
  EVBACKEND_DEVPOLL = 0x00000010U,
  EVBACKEND_PORT = 0x00000020U,
  EVBACKEND_ALL = 0x0000003FU,
  EVBACKEND_MASK = 0x0000FFFFU
};


extern int ev_version_major (void) throw ();
extern int ev_version_minor (void) throw ();

extern unsigned int ev_supported_backends (void) throw ();
extern unsigned int ev_recommended_backends (void) throw ();
extern unsigned int ev_embeddable_backends (void) throw ();

extern ev_tstamp ev_time (void) throw ();
extern void ev_sleep (ev_tstamp delay) throw ();







extern void ev_set_allocator (void *(*cb)(void *ptr, long size) throw ()) throw ();





extern void ev_set_syserr_cb (void (*cb)(const char *msg) throw ()) throw ();





extern struct ev_loop *ev_default_loop (unsigned int flags = 0) throw ();





static inline struct ev_loop *
ev_default_loop_uc_ (void) throw ()
{
  extern struct ev_loop *ev_default_loop_ptr;

  return ev_default_loop_ptr;
}

static inline int
ev_is_default_loop (struct ev_loop *loop) throw ()
{
  return loop == ev_default_loop_uc_ ();
}


extern struct ev_loop *ev_loop_new (unsigned int flags = 0) throw ();

extern ev_tstamp ev_now (struct ev_loop *loop) throw ();
# 604 "ev.h"
extern void ev_loop_destroy (struct ev_loop *loop);





extern void ev_loop_fork (struct ev_loop *loop) throw ();

extern unsigned int ev_backend (struct ev_loop *loop) throw ();

extern void ev_now_update (struct ev_loop *loop) throw ();
# 626 "ev.h"
enum {
  EVRUN_NOWAIT = 1,
  EVRUN_ONCE = 2
};


enum {
  EVBREAK_CANCEL = 0,
  EVBREAK_ONE = 1,
  EVBREAK_ALL = 2
};


extern int ev_run (struct ev_loop *loop, int flags = 0);
extern void ev_break (struct ev_loop *loop, int how = EVBREAK_ONE) throw ();






extern void ev_ref (struct ev_loop *loop) throw ();
extern void ev_unref (struct ev_loop *loop) throw ();





extern void ev_once (struct ev_loop *loop, int fd, int events, ev_tstamp timeout, void (*cb)(int revents, void *arg), void *arg) throw ();


extern unsigned int ev_iteration (struct ev_loop *loop) throw ();
extern unsigned int ev_depth (struct ev_loop *loop) throw ();
extern void ev_verify (struct ev_loop *loop) throw ();

extern void ev_set_io_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ();
extern void ev_set_timeout_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ();


extern void ev_set_userdata (struct ev_loop *loop, void *data) throw ();
extern void *ev_userdata (struct ev_loop *loop) throw ();
typedef void (*ev_loop_callback)(struct ev_loop *loop);
extern void ev_set_invoke_pending_cb (struct ev_loop *loop, ev_loop_callback invoke_pending_cb) throw ();

extern void ev_set_loop_release_cb (struct ev_loop *loop, void (*release)(struct ev_loop *loop) throw (), void (*acquire)(struct ev_loop *loop) throw ()) throw ();

extern unsigned int ev_pending_count (struct ev_loop *loop) throw ();
extern void ev_invoke_pending (struct ev_loop *loop);




extern void ev_suspend (struct ev_loop *loop) throw ();
extern void ev_resume (struct ev_loop *loop) throw ();
# 747 "ev.h"
extern void ev_feed_event (struct ev_loop *loop, void *w, int revents) throw ();
extern void ev_feed_fd_event (struct ev_loop *loop, int fd, int revents) throw ();

extern void ev_feed_signal (int signum) throw ();
extern void ev_feed_signal_event (struct ev_loop *loop, int signum) throw ();

extern void ev_invoke (struct ev_loop *loop, void *w, int revents);
extern int ev_clear_pending (struct ev_loop *loop, void *w) throw ();

extern void ev_io_start (struct ev_loop *loop, ev_io *w) throw ();
extern void ev_io_stop (struct ev_loop *loop, ev_io *w) throw ();

extern void ev_timer_start (struct ev_loop *loop, ev_timer *w) throw ();
extern void ev_timer_stop (struct ev_loop *loop, ev_timer *w) throw ();

extern void ev_timer_again (struct ev_loop *loop, ev_timer *w) throw ();

extern ev_tstamp ev_timer_remaining (struct ev_loop *loop, ev_timer *w) throw ();


extern void ev_periodic_start (struct ev_loop *loop, ev_periodic *w) throw ();
extern void ev_periodic_stop (struct ev_loop *loop, ev_periodic *w) throw ();
extern void ev_periodic_again (struct ev_loop *loop, ev_periodic *w) throw ();




extern void ev_signal_start (struct ev_loop *loop, ev_signal *w) throw ();
extern void ev_signal_stop (struct ev_loop *loop, ev_signal *w) throw ();
# 785 "ev.h"
extern void ev_stat_start (struct ev_loop *loop, ev_stat *w) throw ();
extern void ev_stat_stop (struct ev_loop *loop, ev_stat *w) throw ();
extern void ev_stat_stat (struct ev_loop *loop, ev_stat *w) throw ();



extern void ev_idle_start (struct ev_loop *loop, ev_idle *w) throw ();
extern void ev_idle_stop (struct ev_loop *loop, ev_idle *w) throw ();



extern void ev_prepare_start (struct ev_loop *loop, ev_prepare *w) throw ();
extern void ev_prepare_stop (struct ev_loop *loop, ev_prepare *w) throw ();



extern void ev_check_start (struct ev_loop *loop, ev_check *w) throw ();
extern void ev_check_stop (struct ev_loop *loop, ev_check *w) throw ();



extern void ev_fork_start (struct ev_loop *loop, ev_fork *w) throw ();
extern void ev_fork_stop (struct ev_loop *loop, ev_fork *w) throw ();



extern void ev_cleanup_start (struct ev_loop *loop, ev_cleanup *w) throw ();
extern void ev_cleanup_stop (struct ev_loop *loop, ev_cleanup *w) throw ();




extern void ev_embed_start (struct ev_loop *loop, ev_embed *w) throw ();
extern void ev_embed_stop (struct ev_loop *loop, ev_embed *w) throw ();
extern void ev_embed_sweep (struct ev_loop *loop, ev_embed *w) throw ();



extern void ev_async_start (struct ev_loop *loop, ev_async *w) throw ();
extern void ev_async_stop (struct ev_loop *loop, ev_async *w) throw ();
extern void ev_async_send (struct ev_loop *loop, ev_async *w) throw ();
# 835 "ev.h"
    static inline void ev_loop (struct ev_loop *loop, int flags) { ev_run (loop, flags); }
    static inline void ev_unloop (struct ev_loop *loop, int how ) { ev_break (loop, how ); }
    static inline void ev_default_destroy (void) { ev_loop_destroy (ev_default_loop (0)); }
    static inline void ev_default_fork (void) { ev_loop_fork (ev_default_loop (0)); }

      static inline unsigned int ev_loop_count (struct ev_loop *loop) { return ev_iteration (loop); }
      static inline unsigned int ev_loop_depth (struct ev_loop *loop) { return ev_depth (loop); }
      static inline void ev_loop_verify (struct ev_loop *loop) { ev_verify (loop); }
# 851 "ev.h"
}
  
# 1345 "ev.c"
 static inline __attribute__ ((__const__)) uint32_t ecb_float_to_binary32 (float x);
  static inline __attribute__ ((__const__)) uint32_t
  ecb_float_to_binary32 (float x)
  {
    uint32_t r;


      memcpy (&r, &x, 4);
# 1381 "ev.c"
    return r;
  }


  static inline __attribute__ ((__const__)) float ecb_binary32_to_float (uint32_t x);
  static inline __attribute__ ((__const__)) float
  ecb_binary32_to_float (uint32_t x)
  {
    float r;


      memcpy (&r, &x, 4);
# 1411 "ev.c"
    return r;
  }


  static inline __attribute__ ((__const__)) uint64_t ecb_double_to_binary64 (double x);
  static inline __attribute__ ((__const__)) uint64_t
  ecb_double_to_binary64 (double x)
  {
    uint64_t r;


      memcpy (&r, &x, 8);
# 1451 "ev.c"
    return r;
  }


  static inline __attribute__ ((__const__)) double ecb_binary64_to_double (uint64_t x);
  static inline __attribute__ ((__const__)) double
  ecb_binary64_to_double (uint64_t x)
  {
    double r;


      memcpy (&r, &x, 8);
# 1481 "ev.c"
    return r;
  }


  static inline __attribute__ ((__const__)) uint16_t ecb_float_to_binary16 (float x);
  static inline __attribute__ ((__const__)) uint16_t
  ecb_float_to_binary16 (float x)
  {
    return ecb_binary32_to_binary16 (ecb_float_to_binary32 (x));
  }


  static inline __attribute__ ((__const__)) float ecb_binary16_to_float (uint16_t x);
  static inline __attribute__ ((__const__)) float
  ecb_binary16_to_float (uint16_t x)
  {
    return ecb_binary32_to_float (ecb_binary16_to_binary32 (x));
  }
# 1546 "ev.c"
typedef ev_watcher *W;
typedef ev_watcher_list *WL;
typedef ev_watcher_time *WT;
# 1574 "ev.c"
# 1 "ev_win32.c" 1
# 46 "ev_win32.c"
volatile double SIGFPE_REQ = 0.0f;

static SOCKET
ev_tcp_socket (void)
{



  return socket (
# 54 "ev_win32.c" 3
                2
# 54 "ev_win32.c"
                       , 
# 54 "ev_win32.c" 3
                         1
# 54 "ev_win32.c"
                                    , 0);

}


static int
ev_pipe (int filedes [2])
{
  struct sockaddr_in addr = { 0 };
  int addr_size = sizeof (addr);
  struct sockaddr_in adr2;
  int adr2_size = sizeof (adr2);
  SOCKET listener;
  SOCKET sock [2] = { -1, -1 };

  if ((listener = ev_tcp_socket ()) == 
# 69 "ev_win32.c" 3
                                      (SOCKET)(~0)
# 69 "ev_win32.c"
                                                    )
    return -1;

  addr.sin_family = 
# 72 "ev_win32.c" 3
                   2
# 72 "ev_win32.c"
                          ;
  addr.sin_addr.
# 73 "ev_win32.c" 3
               S_un.S_addr 
# 73 "ev_win32.c"
                      = htonl (
# 73 "ev_win32.c" 3
                               0x7f000001
# 73 "ev_win32.c"
                                              );
  addr.sin_port = 0;

  if (bind (listener, (struct sockaddr *)&addr, addr_size))
    goto fail;

  if (getsockname (listener, (struct sockaddr *)&addr, &addr_size))
    goto fail;

  if (listen (listener, 1))
    goto fail;

  if ((sock [0] = ev_tcp_socket ()) == 
# 85 "ev_win32.c" 3
                                      (SOCKET)(~0)
# 85 "ev_win32.c"
                                                    )
    goto fail;

  if (connect (sock [0], (struct sockaddr *)&addr, addr_size))
    goto fail;



  if ((sock [1] = accept (listener, 0, 0)) < 0)
    goto fail;
# 108 "ev_win32.c"
  if (getpeername (sock [0], (struct sockaddr *)&addr, &addr_size))
    goto fail;

  if (getsockname (sock [1], (struct sockaddr *)&adr2, &adr2_size))
    goto fail;

  
# 114 "ev_win32.c" 3
 (*_errno()) 
# 114 "ev_win32.c"
       = 
# 114 "ev_win32.c" 3
         10022L
# 114 "ev_win32.c"
                  ;
  if (addr_size != adr2_size
      || addr.sin_addr.
# 116 "ev_win32.c" 3
                      S_un.S_addr 
# 116 "ev_win32.c"
                             != adr2.sin_addr.
# 116 "ev_win32.c" 3
                                              S_un.S_addr
      
# 117 "ev_win32.c"
     || addr.sin_port != adr2.sin_port)
    goto fail;

  closesocket (listener);


  filedes [0] = _open_osfhandle (sock [0], 0);
  filedes [1] = _open_osfhandle (sock [1], 0);







  return 0;

fail:
  closesocket (listener);

  if (sock [0] != 
# 137 "ev_win32.c" 3
                 (SOCKET)(~0)
# 137 "ev_win32.c"
                               ) closesocket (sock [0]);
  if (sock [1] != 
# 138 "ev_win32.c" 3
                 (SOCKET)(~0)
# 138 "ev_win32.c"
                               ) closesocket (sock [1]);

  return -1;
}





ev_tstamp
ev_time (void)
{
  FILETIME ft;
  ULARGE_INTEGER ui;

  GetSystemTimeAsFileTime (&ft);
  ui.u.LowPart = ft.dwLowDateTime;
  ui.u.HighPart = ft.dwHighDateTime;


  return (LONGLONG)(ui.QuadPart - 116444736000000000) * 1e-7;
}

static ev_tstamp
ev_floor (ev_tstamp v)
{




  const ev_tstamp shift = sizeof (unsigned long) >= 8 ? 18446744073709551616. : 4294967296.;



  if (__builtin_expect ((!!(v >= shift)),(0)))
    {
      ev_tstamp f;

      if (v == v - 1.)
        return v;

      f = shift * ev_floor (v * (1. / shift));
      return f + ev_floor (v - f);
    }


  if (__builtin_expect ((!!(v < 0.)),(0)))
    {
      ev_tstamp f = -ev_floor (-v);

      return f - (f == v ? 0 : 1);
    }


  return (unsigned long)v;
}
# 1632 "ev.c"
__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static unsigned int
ev_linux_version (void)
{
# 1665 "ev.c"
  return 0;

}
# 1680 "ev.c"
static void (*syserr_cb)(const char *msg) throw ();

__attribute__ ((__cold__))
void
ev_set_syserr_cb (void (*cb)(const char *msg) throw ()) throw ()
{
  syserr_cb = cb;
}

__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
ev_syserr (const char *msg)
{
  if (!msg)
    msg = "(libev) system error";

  if (syserr_cb)
    syserr_cb (msg);
  else
    {






      perror (msg);

      abort ();
    }
}

static void *
ev_realloc_emul (void *ptr, long size) throw ()
{







  if (size)
    return realloc (ptr, size);

  free (ptr);
  return 0;
}

static void *(*alloc)(void *ptr, long size) throw () = ev_realloc_emul;

__attribute__ ((__cold__))
void
ev_set_allocator (void *(*cb)(void *ptr, long size) throw ()) throw ()
{
  alloc = cb;
}

static inline void *
ev_realloc (void *ptr, long size)
{
  ptr = alloc (ptr, size);

  if (!ptr && size)
    {



      fprintf (
# 1748 "ev.c" 3
              (&_iob[2])
# 1748 "ev.c"
                    , "(libev) cannot allocate %ld bytes, aborting.", size);

      abort ();
    }

  return ptr;
}
# 1765 "ev.c"
typedef struct
{
  WL head;
  unsigned char events;
  unsigned char reify;
  unsigned char emask;
  unsigned char unused;




  SOCKET handle;




} ANFD;


typedef struct
{
  W w;
  int events;
} ANPENDING;
# 1801 "ev.c"
  typedef struct {
    ev_tstamp at;
    WT w;
  } ANHE;
# 1820 "ev.c"
  struct ev_loop
  {
    ev_tstamp ev_rt_now;
	ev_tstamp now_floor;
	ev_tstamp mn_now;
	ev_tstamp rtmn_diff;

	W * rfeeds;
	int rfeedmax;
	int rfeedcnt;

	ANPENDING *pendings[((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];
	int pendingmax[((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];
	int pendingcnt[((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];
	int pendingpri;
	ev_prepare pending_w;

	ev_tstamp io_blocktime;
	ev_tstamp timeout_blocktime;

	int backend;
	int activecnt;
	sig_atomic_t volatile loop_done;

	int backend_fd;
	ev_tstamp backend_mintime;
	void (*backend_modify)(struct ev_loop *loop, int fd, int oev, int nev);
	void (*backend_poll)(struct ev_loop *loop, ev_tstamp timeout);

	ANFD * anfds;
	int anfdmax;

	int evpipe [2];
	ev_io pipe_w;
	sig_atomic_t volatile pipe_write_wanted;
	sig_atomic_t volatile pipe_write_skipped;

	char postfork;

	int * fdchanges;
	int fdchangemax;
	int fdchangecnt;

	ANHE * timers;
	int timermax;
	int timercnt;

	ANHE * periodics;
	int periodicmax;
	int periodiccnt;

	ev_idle **idles [((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];
	int idlemax [((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];
	int idlecnt [((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1)];

	int idleall;

	struct ev_prepare ** prepares;
	int preparemax;
	int preparecnt;

	struct ev_check ** checks;
	int checkmax;
	int checkcnt;

	struct ev_fork ** forks;
	int forkmax;
	int forkcnt;

	struct ev_cleanup ** cleanups;
	int cleanupmax;
	int cleanupcnt;

	sig_atomic_t volatile async_pending;
	struct ev_async ** asyncs;
	int asyncmax;
	int asynccnt;
	# 183 "ev_vars.h"
	sig_atomic_t volatile sig_pending;

	unsigned int origflags;

	unsigned int loop_count;
	unsigned int loop_depth;

	void * userdata;

	void (*release_cb)(struct ev_loop *loop) throw ();
	void (*acquire_cb)(struct ev_loop *loop) throw ();
	ev_loop_callback invoke_cb;
  };
  static struct ev_loop default_loop_struct;
  extern struct ev_loop *ev_default_loop_ptr = 0;
static inline ev_tstamp
get_clock (void)
{
  return ev_time ();
}


ev_tstamp
ev_now (struct ev_loop *loop) throw ()
{
  return ((loop)->ev_rt_now);
}


void
ev_sleep (ev_tstamp delay) throw ()
{
  if (delay > 0.)
    {
      Sleep ((unsigned long)(delay * 1e3));
    }
}







static inline int
array_nextsize (int elem, int cur, int cnt)
{
  int ncur = cur + 1;

  do
    ncur <<= 1;
  while (cnt > ncur);


  if (elem * ncur > 4096 - sizeof (void *) * 4)
    {
      ncur *= elem;
      ncur = (ncur + elem + (4096 - 1) + sizeof (void *) * 4) & ~(4096 - 1);
      ncur = ncur - sizeof (void *) * 4;
      ncur /= elem;
    }

  return ncur;
}

__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void *
array_realloc (int elem, void *base, int *cur, int cnt)
{
  *cur = array_nextsize (elem, *cur, cnt);
  return ev_realloc (base, elem * *cur);
}
# 1987 "ev.c"
__attribute__ ((__noinline__))
static void
pendingcb (struct ev_loop *loop, ev_prepare *w, int revents)
{
}

__attribute__ ((__noinline__))
void
ev_feed_event (struct ev_loop *loop, void *w, int revents) throw ()
{
  W w_ = (W)w;
  int pri = (((W)w_)->priority - (((0x7f) & 4) ? -2 : 0));

  if (__builtin_expect ((!!(w_->pending)),(0)))
    ((loop)->pendings) [pri][w_->pending - 1].events |= revents;
  else
    {
      w_->pending = ++((loop)->pendingcnt) [pri];
      if (__builtin_expect ((!!((w_->pending) > (((loop)->pendingmax) [pri]))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->pendingmax) [pri]); (((loop)->pendings) [pri]) = (ANPENDING *)array_realloc (sizeof (ANPENDING), (((loop)->pendings) [pri]), &(((loop)->pendingmax) [pri]), (w_->pending)); ; };
      ((loop)->pendings) [pri][w_->pending - 1].w = w_;
      ((loop)->pendings) [pri][w_->pending - 1].events = revents;
    }

  ((loop)->pendingpri) = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1) - 1;
}

static inline void
feed_reverse (struct ev_loop *loop, W w)
{
  if (__builtin_expect ((!!((((loop)->rfeedcnt) + 1) > (((loop)->rfeedmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->rfeedmax)); (((loop)->rfeeds)) = (W *)array_realloc (sizeof (W), (((loop)->rfeeds)), &(((loop)->rfeedmax)), (((loop)->rfeedcnt) + 1)); ; };
  ((loop)->rfeeds) [((loop)->rfeedcnt)++] = w;
}

static inline void
feed_reverse_done (struct ev_loop *loop, int revents)
{
  do
    ev_feed_event (loop, ((loop)->rfeeds) [--((loop)->rfeedcnt)], revents);
  while (((loop)->rfeedcnt));
}

static inline void
queue_events (struct ev_loop *loop, W *events, int eventcnt, int type)
{
  int i;

  for (i = 0; i < eventcnt; ++i)
    ev_feed_event (loop, events [i], type);
}



static inline void
fd_event_nocheck (struct ev_loop *loop, int fd, int revents)
{
  ANFD *anfd = ((loop)->anfds) + fd;
  ev_io *w;

  for (w = (ev_io *)anfd->head; w; w = (ev_io *)((WL)w)->next)
    {
      int ev = w->events & revents;

      if (ev)
        ev_feed_event (loop, (W)w, ev);
    }
}



static inline void
fd_event (struct ev_loop *loop, int fd, int revents)
{
  ANFD *anfd = ((loop)->anfds) + fd;

  if (__builtin_expect ((!!(!anfd->reify)),(1)))
    fd_event_nocheck (loop, fd, revents);
}

void
ev_feed_fd_event (struct ev_loop *loop, int fd, int revents) throw ()
{
  if (fd >= 0 && fd < ((loop)->anfdmax))
    fd_event_nocheck (loop, fd, revents);
}



static inline void
fd_reify (struct ev_loop *loop)
{
  int i;


  for (i = 0; i < ((loop)->fdchangecnt); ++i)
    {
      int fd = ((loop)->fdchanges) [i];
      ANFD *anfd = ((loop)->anfds) + fd;

      if (anfd->reify & EV__IOFDSET && anfd->head)
        {
          SOCKET handle = _get_osfhandle (fd);

          if (handle != anfd->handle)
            {
              unsigned long arg;

              
# 2093 "ev.c" 3
             ((
# 2093 "ev.c"
             ("libev: only socket fds supported in this configuration", ioctlsocket (handle, 
# 2093 "ev.c" 3
             (0x40000000|(((long)sizeof(u_long)&0x7f)<<16)|(('f')<<8)|(127))
# 2093 "ev.c"
             , &arg) == 0)
# 2093 "ev.c" 3
             ) ? (void)0 : _assert(
# 2093 "ev.c"
             "(\"libev: only socket fds supported in this configuration\", ioctlsocket (handle, FIONREAD, &arg) == 0)"
# 2093 "ev.c" 3
             , "ev.c", 2093))
# 2093 "ev.c"
                                                                                                                           ;


              ((loop)->backend_modify) (loop, fd, anfd->events, 0);
              anfd->events = 0;
              anfd->handle = handle;
            }
        }
    }


  for (i = 0; i < ((loop)->fdchangecnt); ++i)
    {
      int fd = ((loop)->fdchanges) [i];
      ANFD *anfd = ((loop)->anfds) + fd;
      ev_io *w;

      unsigned char o_events = anfd->events;
      unsigned char o_reify = anfd->reify;

      anfd->reify = 0;


        {
          anfd->events = 0;

          for (w = (ev_io *)anfd->head; w; w = (ev_io *)((WL)w)->next)
            anfd->events |= (unsigned char)w->events;

          if (o_events != anfd->events)
            o_reify = EV__IOFDSET;
        }

      if (o_reify & EV__IOFDSET)
        ((loop)->backend_modify) (loop, fd, o_events, anfd->events);
    }

  ((loop)->fdchangecnt) = 0;
}


static inline
void
fd_change (struct ev_loop *loop, int fd, int flags)
{
  unsigned char reify = ((loop)->anfds) [fd].reify;
  ((loop)->anfds) [fd].reify |= flags;

  if (__builtin_expect ((!!(!reify)),(1)))
    {
      ++((loop)->fdchangecnt);
      if (__builtin_expect ((!!((((loop)->fdchangecnt)) > (((loop)->fdchangemax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->fdchangemax)); (((loop)->fdchanges)) = (int *)array_realloc (sizeof (int), (((loop)->fdchanges)), &(((loop)->fdchangemax)), (((loop)->fdchangecnt))); ; };
      ((loop)->fdchanges) [((loop)->fdchangecnt) - 1] = fd;
    }
}


static inline __attribute__ ((__cold__)) void
fd_kill (struct ev_loop *loop, int fd)
{
  ev_io *w;

  while ((w = (ev_io *)((loop)->anfds) [fd].head))
    {
      ev_io_stop (loop, w);
      ev_feed_event (loop, (W)w, EV_ERROR | EV_READ | EV_WRITE);
    }
}


static inline __attribute__ ((__cold__)) int
fd_valid (int fd)
{

  return _get_osfhandle (fd) != -1;



}


__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
fd_ebadf (struct ev_loop *loop)
{
  int fd;

  for (fd = 0; fd < ((loop)->anfdmax); ++fd)
    if (((loop)->anfds) [fd].events)
      if (!fd_valid (fd) && 
# 2182 "ev.c" 3
                           (*_errno()) 
# 2182 "ev.c"
                                 == 
# 2182 "ev.c" 3
                                    9
# 2182 "ev.c"
                                         )
        fd_kill (loop, fd);
}


__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
fd_enomem (struct ev_loop *loop)
{
  int fd;

  for (fd = ((loop)->anfdmax); fd--; )
    if (((loop)->anfds) [fd].events)
      {
        fd_kill (loop, fd);
        break;
      }
}


__attribute__ ((__noinline__))
static void
fd_rearm_all (struct ev_loop *loop)
{
  int fd;

  for (fd = 0; fd < ((loop)->anfdmax); ++fd)
    if (((loop)->anfds) [fd].events)
      {
        ((loop)->anfds) [fd].events = 0;
        ((loop)->anfds) [fd].emask = 0;
        fd_change (loop, fd, EV__IOFDSET | 1);
      }
}



static inline void
fd_intern (int fd)
{

  unsigned long arg = 1;
  ioctlsocket (_get_osfhandle (fd), 
# 2224 "ev.c" 3
                                          (0x80000000|(((long)sizeof(u_long)&0x7f)<<16)|(('f')<<8)|(126))
# 2224 "ev.c"
                                                 , &arg);




}
# 2253 "ev.c"
static inline void
downheap (ANHE *heap, int N, int k)
{
  ANHE he = heap [k];
  ANHE *E = heap + N + (4 - 1);

  for (;;)
    {
      ev_tstamp minat;
      ANHE *minpos;
      ANHE *pos = heap + 4 * (k - (4 - 1)) + (4 - 1) + 1;


      if (__builtin_expect ((!!(pos + 4 - 1 < E)),(1)))
        {
                                                        (minpos = pos + 0), (minat = (*minpos).at);
          if ( (pos [1]).at < minat) (minpos = pos + 1), (minat = (*minpos).at);
          if ( (pos [2]).at < minat) (minpos = pos + 2), (minat = (*minpos).at);
          if ( (pos [3]).at < minat) (minpos = pos + 3), (minat = (*minpos).at);
        }
      else if (pos < E)
        {
                                                        (minpos = pos + 0), (minat = (*minpos).at);
          if (pos + 1 < E && (pos [1]).at < minat) (minpos = pos + 1), (minat = (*minpos).at);
          if (pos + 2 < E && (pos [2]).at < minat) (minpos = pos + 2), (minat = (*minpos).at);
          if (pos + 3 < E && (pos [3]).at < minat) (minpos = pos + 3), (minat = (*minpos).at);
        }
      else
        break;

      if ((he).at <= minat)
        break;

      heap [k] = *minpos;
      ((W)((*minpos).w))->active = k;

      k = minpos - heap;
    }

  heap [k] = he;
  ((W)((he).w))->active = k;
}
# 2333 "ev.c"
static inline void
upheap (ANHE *heap, int k)
{
  ANHE he = heap [k];

  for (;;)
    {
      int p = ((((k) - (4 - 1) - 1) / 4) + (4 - 1));

      if (((p) == (k)) || (heap [p]).at <= (he).at)
        break;

      heap [k] = heap [p];
      ((W)((heap [k]).w))->active = k;
      k = p;
    }

  heap [k] = he;
  ((W)((he).w))->active = k;
}


static inline void
adjustheap (ANHE *heap, int N, int k)
{
  if (k > (4 - 1) && (heap [k]).at <= (heap [((((k) - (4 - 1) - 1) / 4) + (4 - 1))]).at)
    upheap (heap, k);
  else
    downheap (heap, N, k);
}


static inline void
reheap (ANHE *heap, int N)
{
  int i;



  for (i = 0; i < N; ++i)
    upheap (heap, i + (4 - 1));
}




typedef struct
{
  sig_atomic_t volatile pending;

  struct ev_loop *loop;

  WL head;
} ANSIG;

static ANSIG signals [(
# 2388 "ev.c" 3
                     23
# 2388 "ev.c"
                     ) - 1];





__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
evpipe_init (struct ev_loop *loop)
{
  if (!(0 + ((ev_watcher *)(void *)(&((loop)->pipe_w)))->active))
    {
      int fds [2];
# 2410 "ev.c"
        {
          while (ev_pipe (fds))
            ev_syserr ("(libev) error creating signal/async pipe");

          fd_intern (fds [0]);
        }

      ((loop)->evpipe) [0] = fds [0];

      if (((loop)->evpipe) [1] < 0)
        ((loop)->evpipe) [1] = fds [1];
      else
        {





          dup2 (fds [1], ((loop)->evpipe) [1]);
          close (fds [1]);
        }

      fd_intern (((loop)->evpipe) [1]);

      do { (&((loop)->pipe_w))->fd = (((loop)->evpipe) [0] < 0 ? ((loop)->evpipe) [1] : ((loop)->evpipe) [0]); (&((loop)->pipe_w))->events = (EV_READ) | EV__IOFDSET; } while (0);
      ev_io_start (loop, &((loop)->pipe_w));
      ev_unref (loop);
    }
}

static inline void
evpipe_write (struct ev_loop *loop, sig_atomic_t volatile *flag)
{
  __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");

  if (__builtin_expect ((!!(*flag)),(1)))
    return;

  *flag = 1;
  __asm__ __volatile__ ("");

  ((loop)->pipe_write_skipped) = 1;

  __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");

  if (((loop)->pipe_write_wanted))
    {
      int old_errno;

      ((loop)->pipe_write_skipped) = 0;
      __asm__ __volatile__ ("");

      old_errno = 
# 2462 "ev.c" 3
                 (*_errno())
# 2462 "ev.c"
                      ;
# 2472 "ev.c"
        {

          WSABUF buf;
          DWORD sent;
          buf.buf = &buf;
          buf.len = 1;
          WSASend (_get_osfhandle (((loop)->evpipe) [1]), &buf, 1, &sent, 0, 0, 0);



        }

      
# 2484 "ev.c" 3
     (*_errno()) 
# 2484 "ev.c"
           = old_errno;
    }
}



static void
pipecb (struct ev_loop *loop, ev_io *iow, int revents)
{
  int i;

  if (revents & EV_READ)
    {
# 2505 "ev.c"
        {
          char dummy[4];

          WSABUF buf;
          DWORD recvd;
          DWORD flags = 0;
          buf.buf = dummy;
          buf.len = sizeof (dummy);
          WSARecv (_get_osfhandle (((loop)->evpipe) [0]), &buf, 1, &recvd, &flags, 0, 0);



        }
    }

  ((loop)->pipe_write_skipped) = 0;

  __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");


  if (((loop)->sig_pending))
    {
      ((loop)->sig_pending) = 0;

      __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");

      for (i = (
# 2531 "ev.c" 3
              23
# 2531 "ev.c"
              ) - 1; i--; )
        if (__builtin_expect ((!!(signals [i].pending)),(0)))
          ev_feed_signal_event (loop, i + 1);
    }



  if (((loop)->async_pending))
    {
      ((loop)->async_pending) = 0;

      __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");

      for (i = ((loop)->asynccnt); i--; )
        if (((loop)->asyncs) [i]->sent)
          {
            ((loop)->asyncs) [i]->sent = 0;
            __asm__ __volatile__ ("");
            ev_feed_event (loop, ((loop)->asyncs) [i], EV_ASYNC);
          }
    }

}



void
ev_feed_signal (int signum) throw ()
{

  struct ev_loop *loop;
  __asm__ __volatile__ ("" : : : "memory");
  loop = signals [signum - 1].loop;

  if (!loop)
    return;


  signals [signum - 1].pending = 1;
  evpipe_write (loop, &((loop)->sig_pending));
}

static void
ev_sighandler (int signum)
{

  signal (signum, ev_sighandler);


  ev_feed_signal (signum);
}

__attribute__ ((__noinline__))
void
ev_feed_signal_event (struct ev_loop *loop, int signum) throw ()
{
  WL w;

  if (__builtin_expect ((!!(signum <= 0 || signum >= (
# 2589 "ev.c" 3
     23
# 2589 "ev.c"
     ))),(0)))
    return;

  --signum;





  if (__builtin_expect ((!!(signals [signum].loop != loop)),(0)))
    return;


  signals [signum].pending = 0;
  __asm__ __volatile__ ("");

  for (w = signals [signum].head; w; w = w->next)
    ev_feed_event (loop, (W)w, EV_SIGNAL);
}
# 2711 "ev.c"
__attribute__ ((__cold__)) int
ev_version_major (void) throw ()
{
  return 4;
}

__attribute__ ((__cold__)) int
ev_version_minor (void) throw ()
{
  return 24;
}


static inline __attribute__ ((__cold__)) int
enable_secure (void)
{

  return 0;




}

__attribute__ ((__cold__))
unsigned int
ev_supported_backends (void) throw ()
{
  unsigned int flags = 0;

  if (0 ) flags |= EVBACKEND_PORT;
  if (0) flags |= EVBACKEND_KQUEUE;
  if (0 ) flags |= EVBACKEND_EPOLL;
  if (0 ) flags |= EVBACKEND_POLL;
  if (0) flags |= EVBACKEND_SELECT;

  return flags;
}

__attribute__ ((__cold__))
unsigned int
ev_recommended_backends (void) throw ()
{
  unsigned int flags = ev_supported_backends ();




  flags &= ~EVBACKEND_KQUEUE;
# 2770 "ev.c"
  return flags;
}

__attribute__ ((__cold__))
unsigned int
ev_embeddable_backends (void) throw ()
{
  int flags = EVBACKEND_EPOLL | EVBACKEND_KQUEUE | EVBACKEND_PORT;


  if (ev_linux_version () < 0x020620)
    flags &= ~EVBACKEND_EPOLL;

  return flags;
}

unsigned int
ev_backend (struct ev_loop *loop) throw ()
{
  return ((loop)->backend);
}


unsigned int
ev_iteration (struct ev_loop *loop) throw ()
{
  return ((loop)->loop_count);
}

unsigned int
ev_depth (struct ev_loop *loop) throw ()
{
  return ((loop)->loop_depth);
}

void
ev_set_io_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ()
{
  ((loop)->io_blocktime) = interval;
}

void
ev_set_timeout_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ()
{
  ((loop)->timeout_blocktime) = interval;
}

void
ev_set_userdata (struct ev_loop *loop, void *data) throw ()
{
  ((loop)->userdata) = data;
}

void *
ev_userdata (struct ev_loop *loop) throw ()
{
  return ((loop)->userdata);
}

void
ev_set_invoke_pending_cb (struct ev_loop *loop, ev_loop_callback invoke_pending_cb) throw ()
{
  ((loop)->invoke_cb) = invoke_pending_cb;
}

void
ev_set_loop_release_cb (struct ev_loop *loop, void (*release)(struct ev_loop *loop) throw (), void (*acquire)(struct ev_loop *loop) throw ()) throw ()
{
  ((loop)->release_cb) = release;
  ((loop)->acquire_cb) = acquire;
}



__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
loop_init (struct ev_loop *loop, unsigned int flags) throw ()
{
  if (!((loop)->backend))
    {
      ((loop)->origflags) = flags;
# 2878 "ev.c"
      if (!(flags & EVFLAG_NOENV)
          && !enable_secure ()
          && getenv ("LIBEV_FLAGS"))
        flags = atoi (getenv ("LIBEV_FLAGS"));

      ((loop)->ev_rt_now) = ev_time ();
      ((loop)->mn_now) = get_clock ();
      ((loop)->now_floor) = ((loop)->mn_now);
      ((loop)->rtmn_diff) = ((loop)->ev_rt_now) - ((loop)->mn_now);

      ((loop)->invoke_cb) = ev_invoke_pending;


      ((loop)->io_blocktime) = 0.;
      ((loop)->timeout_blocktime) = 0.;
      ((loop)->backend) = 0;
      ((loop)->backend_fd) = -1;
      ((loop)->sig_pending) = 0;

      ((loop)->async_pending) = 0;

      ((loop)->pipe_write_skipped) = 0;
      ((loop)->pipe_write_wanted) = 0;
      ((loop)->evpipe) [0] = -1;
      ((loop)->evpipe) [1] = -1;







      if (!(flags & EVBACKEND_MASK))
        flags |= ev_recommended_backends ();
# 2932 "ev.c"
      do { do { ((ev_watcher *)(void *)((&((loop)->pending_w))))->active = ((ev_watcher *)(void *)((&((loop)->pending_w))))->pending = 0; ( (ev_watcher *)(void *)(((&((loop)->pending_w)))))->priority = (0); ((((&((loop)->pending_w))))->cb = ((pendingcb)), memmove (&((ev_watcher *)(((&((loop)->pending_w)))))->cb, &(((&((loop)->pending_w))))->cb, sizeof ((((&((loop)->pending_w))))->cb))); } while (0); ; } while (0);


      do { ((ev_watcher *)(void *)(&((loop)->pipe_w)))->active = ((ev_watcher *)(void *)(&((loop)->pipe_w)))->pending = 0; ( (ev_watcher *)(void *)((&((loop)->pipe_w))))->priority = (0); (((&((loop)->pipe_w)))->cb = (pipecb), memmove (&((ev_watcher *)((&((loop)->pipe_w))))->cb, &((&((loop)->pipe_w)))->cb, sizeof (((&((loop)->pipe_w)))->cb))); } while (0);
      ( (ev_watcher *)(void *)(&((loop)->pipe_w)))->priority = ((((0x7f) & 4) ? +2 : 0));

    }
}


__attribute__ ((__cold__))
void
ev_loop_destroy (struct ev_loop *loop)
{
  int i;



  if (!loop)
    return;




  if (__builtin_expect ((!!(((loop)->cleanupcnt))),(0)))
    {
      queue_events (loop, (W *)((loop)->cleanups), ((loop)->cleanupcnt), EV_CLEANUP);
      ((loop)->invoke_cb) (loop);
    }
# 2971 "ev.c"
  if ((0 + ((ev_watcher *)(void *)(&((loop)->pipe_w)))->active))
    {



      if (((loop)->evpipe) [0] >= 0) close (((loop)->evpipe) [0]);
      if (((loop)->evpipe) [1] >= 0) close (((loop)->evpipe) [1]);
    }
# 2990 "ev.c"
  if (((loop)->backend_fd) >= 0)
    close (((loop)->backend_fd));
# 3012 "ev.c"
  for (i = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1); i--; )
    {
      ev_realloc ((((loop)->pendings) [i]), 0); ((loop)->pendingcnt) [i] = ((loop)->pendingmax) [i] = 0; ((loop)->pendings) [i] = 0;

      ev_realloc ((((loop)->idles) [i]), 0); ((loop)->idlecnt) [i] = ((loop)->idlemax) [i] = 0; ((loop)->idles) [i] = 0;

    }

  ev_realloc ((((loop)->anfds)), 0); ((loop)->anfds) = 0; ((loop)->anfdmax) = 0;


  ev_realloc ((((loop)->rfeeds)), 0); ((loop)->rfeedcnt) = ((loop)->rfeedmax) = 0; ((loop)->rfeeds) = 0;
  ev_realloc ((((loop)->fdchanges)), 0); ((loop)->fdchangecnt) = ((loop)->fdchangemax) = 0; ((loop)->fdchanges) = 0;
  ev_realloc ((((loop)->timers)), 0); ((loop)->timercnt) = ((loop)->timermax) = 0; ((loop)->timers) = 0;

  ev_realloc ((((loop)->periodics)), 0); ((loop)->periodiccnt) = ((loop)->periodicmax) = 0; ((loop)->periodics) = 0;


  ev_realloc ((((loop)->forks)), 0); ((loop)->forkcnt) = ((loop)->forkmax) = 0; ((loop)->forks) = 0;


  ev_realloc ((((loop)->cleanups)), 0); ((loop)->cleanupcnt) = ((loop)->cleanupmax) = 0; ((loop)->cleanups) = 0;

  ev_realloc ((((loop)->prepares)), 0); ((loop)->preparecnt) = ((loop)->preparemax) = 0; ((loop)->prepares) = 0;
  ev_realloc ((((loop)->checks)), 0); ((loop)->checkcnt) = ((loop)->checkmax) = 0; ((loop)->checks) = 0;

  ev_realloc ((((loop)->asyncs)), 0); ((loop)->asynccnt) = ((loop)->asyncmax) = 0; ((loop)->asyncs) = 0;


  ((loop)->backend) = 0;


  if (ev_is_default_loop (loop))

    ev_default_loop_ptr = 0;

  else
    ev_realloc ((loop), 0);

}





static inline void
loop_fork (struct ev_loop *loop)
{
# 3074 "ev.c"
  if ((0 + ((ev_watcher *)(void *)(&((loop)->pipe_w)))->active) && ((loop)->postfork) != 2)
    {


      ev_ref (loop);
      ev_io_stop (loop, &((loop)->pipe_w));

      if (((loop)->evpipe) [0] >= 0)
        close (((loop)->evpipe) [0]);

      evpipe_init (loop);

      ev_feed_event (loop, &((loop)->pipe_w), EV_CUSTOM);
    }


  ((loop)->postfork) = 0;
}



__attribute__ ((__cold__))
struct ev_loop *
ev_loop_new (unsigned int flags) throw ()
{
  struct ev_loop *loop = (struct ev_loop *)ev_realloc (0, (sizeof (struct ev_loop)));

  memset (loop, 0, sizeof (struct ev_loop));
  loop_init (loop, flags);

  if (ev_backend (loop))
    return loop;

  ev_realloc ((loop), 0);
  return 0;
}




__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
verify_watcher (struct ev_loop *loop, W w)
{
  
# 3118 "ev.c" 3
 ((
# 3118 "ev.c"
 ("libev: watcher has invalid priority", (((W)w)->priority - (((0x7f) & 4) ? -2 : 0)) >= 0 && (((W)w)->priority - (((0x7f) & 4) ? -2 : 0)) < ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1))
# 3118 "ev.c" 3
 ) ? (void)0 : _assert(
# 3118 "ev.c"
 "(\"libev: watcher has invalid priority\", ABSPRI (w) >= 0 && ABSPRI (w) < NUMPRI)"
# 3118 "ev.c" 3
 , "ev.c", 3118))
# 3118 "ev.c"
                                                                                         ;

  if (w->pending)
    
# 3121 "ev.c" 3
   ((
# 3121 "ev.c"
   ("libev: pending watcher not on pending queue", ((loop)->pendings) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][w->pending - 1].w == w)
# 3121 "ev.c" 3
   ) ? (void)0 : _assert(
# 3121 "ev.c"
   "(\"libev: pending watcher not on pending queue\", pendings [ABSPRI (w)][w->pending - 1].w == w)"
# 3121 "ev.c" 3
   , "ev.c", 3121))
# 3121 "ev.c"
                                                                                                         ;
}

__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
verify_heap (struct ev_loop *loop, ANHE *heap, int N)
{
  int i;

  for (i = (4 - 1); i < N + (4 - 1); ++i)
    {
      
# 3132 "ev.c" 3
     ((
# 3132 "ev.c"
     ("libev: active index mismatch in heap", ((W)((heap [i]).w))->active == i)
# 3132 "ev.c" 3
     ) ? (void)0 : _assert(
# 3132 "ev.c"
     "(\"libev: active index mismatch in heap\", ev_active (ANHE_w (heap [i])) == i)"
# 3132 "ev.c" 3
     , "ev.c", 3132))
# 3132 "ev.c"
                                                                                          ;
      
# 3133 "ev.c" 3
     ((
# 3133 "ev.c"
     ("libev: heap condition violated", i == (4 - 1) || (heap [((((i) - (4 - 1) - 1) / 4) + (4 - 1))]).at <= (heap [i]).at)
# 3133 "ev.c" 3
     ) ? (void)0 : _assert(
# 3133 "ev.c"
     "(\"libev: heap condition violated\", i == HEAP0 || ANHE_at (heap [HPARENT (i)]) <= ANHE_at (heap [i]))"
# 3133 "ev.c" 3
     , "ev.c", 3133))
# 3133 "ev.c"
                                                                                                                  ;
      
# 3134 "ev.c" 3
     ((
# 3134 "ev.c"
     ("libev: heap at cache mismatch", (heap [i]).at == ((WT)((heap [i]).w))->at)
# 3134 "ev.c" 3
     ) ? (void)0 : _assert(
# 3134 "ev.c"
     "(\"libev: heap at cache mismatch\", ANHE_at (heap [i]) == ev_at (ANHE_w (heap [i])))"
# 3134 "ev.c" 3
     , "ev.c", 3134))
# 3134 "ev.c"
                                                                                                ;

      verify_watcher (loop, (W)(heap [i]).w);
    }
}

__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
array_verify (struct ev_loop *loop, W *ws, int cnt)
{
  while (cnt--)
    {
      
# 3146 "ev.c" 3
     ((
# 3146 "ev.c"
     ("libev: active index mismatch", ((W)(ws [cnt]))->active == cnt + 1)
# 3146 "ev.c" 3
     ) ? (void)0 : _assert(
# 3146 "ev.c"
     "(\"libev: active index mismatch\", ev_active (ws [cnt]) == cnt + 1)"
# 3146 "ev.c" 3
     , "ev.c", 3146))
# 3146 "ev.c"
                                                                               ;
      verify_watcher (loop, ws [cnt]);
    }
}



void __attribute__ ((__cold__))
ev_verify (struct ev_loop *loop) throw ()
{

  int i;
  WL w, w2;

  
# 3160 "ev.c" 3
 ((
# 3160 "ev.c"
 ((loop)->activecnt) >= -1
# 3160 "ev.c" 3
 ) ? (void)0 : _assert(
# 3160 "ev.c"
 "activecnt >= -1"
# 3160 "ev.c" 3
 , "ev.c", 3160))
# 3160 "ev.c"
                         ;

  
# 3162 "ev.c" 3
 ((
# 3162 "ev.c"
 ((loop)->fdchangemax) >= ((loop)->fdchangecnt)
# 3162 "ev.c" 3
 ) ? (void)0 : _assert(
# 3162 "ev.c"
 "fdchangemax >= fdchangecnt"
# 3162 "ev.c" 3
 , "ev.c", 3162))
# 3162 "ev.c"
                                    ;
  for (i = 0; i < ((loop)->fdchangecnt); ++i)
    
# 3164 "ev.c" 3
   ((
# 3164 "ev.c"
   ("libev: negative fd in fdchanges", ((loop)->fdchanges) [i] >= 0)
# 3164 "ev.c" 3
   ) ? (void)0 : _assert(
# 3164 "ev.c"
   "(\"libev: negative fd in fdchanges\", fdchanges [i] >= 0)"
# 3164 "ev.c" 3
   , "ev.c", 3164))
# 3164 "ev.c"
                                                                   ;

  
# 3166 "ev.c" 3
 ((
# 3166 "ev.c"
 ((loop)->anfdmax) >= 0
# 3166 "ev.c" 3
 ) ? (void)0 : _assert(
# 3166 "ev.c"
 "anfdmax >= 0"
# 3166 "ev.c" 3
 , "ev.c", 3166))
# 3166 "ev.c"
                      ;
  for (i = 0; i < ((loop)->anfdmax); ++i)
    {
      int j = 0;

      for (w = w2 = ((loop)->anfds) [i].head; w; w = w->next)
        {
          verify_watcher (loop, (W)w);

          if (j++ & 1)
            {
              
# 3177 "ev.c" 3
             ((
# 3177 "ev.c"
             ("libev: io watcher list contains a loop", w != w2)
# 3177 "ev.c" 3
             ) ? (void)0 : _assert(
# 3177 "ev.c"
             "(\"libev: io watcher list contains a loop\", w != w2)"
# 3177 "ev.c" 3
             , "ev.c", 3177))
# 3177 "ev.c"
                                                                         ;
              w2 = w2->next;
            }

          
# 3181 "ev.c" 3
         ((
# 3181 "ev.c"
         ("libev: inactive fd watcher on anfd list", ((W)(w))->active == 1)
# 3181 "ev.c" 3
         ) ? (void)0 : _assert(
# 3181 "ev.c"
         "(\"libev: inactive fd watcher on anfd list\", ev_active (w) == 1)"
# 3181 "ev.c" 3
         , "ev.c", 3181))
# 3181 "ev.c"
                                                                                 ;
          
# 3182 "ev.c" 3
         ((
# 3182 "ev.c"
         ("libev: fd mismatch between watcher and anfd", ((ev_io *)w)->fd == i)
# 3182 "ev.c" 3
         ) ? (void)0 : _assert(
# 3182 "ev.c"
         "(\"libev: fd mismatch between watcher and anfd\", ((ev_io *)w)->fd == i)"
# 3182 "ev.c" 3
         , "ev.c", 3182))
# 3182 "ev.c"
                                                                                        ;
        }
    }

  
# 3186 "ev.c" 3
 ((
# 3186 "ev.c"
 ((loop)->timermax) >= ((loop)->timercnt)
# 3186 "ev.c" 3
 ) ? (void)0 : _assert(
# 3186 "ev.c"
 "timermax >= timercnt"
# 3186 "ev.c" 3
 , "ev.c", 3186))
# 3186 "ev.c"
                              ;
  verify_heap (loop, ((loop)->timers), ((loop)->timercnt));


  
# 3190 "ev.c" 3
 ((
# 3190 "ev.c"
 ((loop)->periodicmax) >= ((loop)->periodiccnt)
# 3190 "ev.c" 3
 ) ? (void)0 : _assert(
# 3190 "ev.c"
 "periodicmax >= periodiccnt"
# 3190 "ev.c" 3
 , "ev.c", 3190))
# 3190 "ev.c"
                                    ;
  verify_heap (loop, ((loop)->periodics), ((loop)->periodiccnt));


  for (i = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1); i--; )
    {
      
# 3196 "ev.c" 3
     ((
# 3196 "ev.c"
     ((loop)->pendingmax) [i] >= ((loop)->pendingcnt) [i]
# 3196 "ev.c" 3
     ) ? (void)0 : _assert(
# 3196 "ev.c"
     "pendingmax [i] >= pendingcnt [i]"
# 3196 "ev.c" 3
     , "ev.c", 3196))
# 3196 "ev.c"
                                              ;

      
# 3198 "ev.c" 3
     ((
# 3198 "ev.c"
     ((loop)->idleall) >= 0
# 3198 "ev.c" 3
     ) ? (void)0 : _assert(
# 3198 "ev.c"
     "idleall >= 0"
# 3198 "ev.c" 3
     , "ev.c", 3198))
# 3198 "ev.c"
                          ;
      
# 3199 "ev.c" 3
     ((
# 3199 "ev.c"
     ((loop)->idlemax) [i] >= ((loop)->idlecnt) [i]
# 3199 "ev.c" 3
     ) ? (void)0 : _assert(
# 3199 "ev.c"
     "idlemax [i] >= idlecnt [i]"
# 3199 "ev.c" 3
     , "ev.c", 3199))
# 3199 "ev.c"
                                        ;
      array_verify (loop, (W *)((loop)->idles) [i], ((loop)->idlecnt) [i]);

    }


  
# 3205 "ev.c" 3
 ((
# 3205 "ev.c"
 ((loop)->forkmax) >= ((loop)->forkcnt)
# 3205 "ev.c" 3
 ) ? (void)0 : _assert(
# 3205 "ev.c"
 "forkmax >= forkcnt"
# 3205 "ev.c" 3
 , "ev.c", 3205))
# 3205 "ev.c"
                            ;
  array_verify (loop, (W *)((loop)->forks), ((loop)->forkcnt));



  
# 3210 "ev.c" 3
 ((
# 3210 "ev.c"
 ((loop)->cleanupmax) >= ((loop)->cleanupcnt)
# 3210 "ev.c" 3
 ) ? (void)0 : _assert(
# 3210 "ev.c"
 "cleanupmax >= cleanupcnt"
# 3210 "ev.c" 3
 , "ev.c", 3210))
# 3210 "ev.c"
                                  ;
  array_verify (loop, (W *)((loop)->cleanups), ((loop)->cleanupcnt));



  
# 3215 "ev.c" 3
 ((
# 3215 "ev.c"
 ((loop)->asyncmax) >= ((loop)->asynccnt)
# 3215 "ev.c" 3
 ) ? (void)0 : _assert(
# 3215 "ev.c"
 "asyncmax >= asynccnt"
# 3215 "ev.c" 3
 , "ev.c", 3215))
# 3215 "ev.c"
                              ;
  array_verify (loop, (W *)((loop)->asyncs), ((loop)->asynccnt));



  
# 3220 "ev.c" 3
 ((
# 3220 "ev.c"
 ((loop)->preparemax) >= ((loop)->preparecnt)
# 3220 "ev.c" 3
 ) ? (void)0 : _assert(
# 3220 "ev.c"
 "preparemax >= preparecnt"
# 3220 "ev.c" 3
 , "ev.c", 3220))
# 3220 "ev.c"
                                  ;
  array_verify (loop, (W *)((loop)->prepares), ((loop)->preparecnt));



  
# 3225 "ev.c" 3
 ((
# 3225 "ev.c"
 ((loop)->checkmax) >= ((loop)->checkcnt)
# 3225 "ev.c" 3
 ) ? (void)0 : _assert(
# 3225 "ev.c"
 "checkmax >= checkcnt"
# 3225 "ev.c" 3
 , "ev.c", 3225))
# 3225 "ev.c"
                              ;
  array_verify (loop, (W *)((loop)->checks), ((loop)->checkcnt));
# 3236 "ev.c"
}



__attribute__ ((__cold__))
struct ev_loop *



ev_default_loop (unsigned int flags) throw ()
{
  if (!ev_default_loop_ptr)
    {

      struct ev_loop *loop = ev_default_loop_ptr = &default_loop_struct;




      loop_init (loop, flags);

      if (ev_backend (loop))
        {






        }
      else
        ev_default_loop_ptr = 0;
    }

  return ev_default_loop_ptr;
}

void
ev_loop_fork (struct ev_loop *loop) throw ()
{
  ((loop)->postfork) = 1;
}



void
ev_invoke (struct ev_loop *loop, void *w, int revents)
{
  ((W)w)->cb (loop, ((W)w), (revents));
}

unsigned int
ev_pending_count (struct ev_loop *loop) throw ()
{
  int pri;
  unsigned int count = 0;

  for (pri = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1); pri--; )
    count += ((loop)->pendingcnt) [pri];

  return count;
}

__attribute__ ((__noinline__))
void
ev_invoke_pending (struct ev_loop *loop)
{
  ((loop)->pendingpri) = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1);

  while (((loop)->pendingpri))
    {
      --((loop)->pendingpri);

      while (((loop)->pendingcnt) [((loop)->pendingpri)])
        {
          ANPENDING *p = ((loop)->pendings) [((loop)->pendingpri)] + --((loop)->pendingcnt) [((loop)->pendingpri)];

          p->w->pending = 0;
          (p->w)->cb (loop, (p->w), (p->events));
          do { } while (0);
        }
    }
}




static inline void
idle_reify (struct ev_loop *loop)
{
  if (__builtin_expect ((!!(((loop)->idleall))),(0)))
    {
      int pri;

      for (pri = ((((0x7f) & 4) ? +2 : 0) - (((0x7f) & 4) ? -2 : 0) + 1); pri--; )
        {
          if (((loop)->pendingcnt) [pri])
            break;

          if (((loop)->idlecnt) [pri])
            {
              queue_events (loop, (W *)((loop)->idles) [pri], ((loop)->idlecnt) [pri], EV_IDLE);
              break;
            }
        }
    }
}



static inline void
timers_reify (struct ev_loop *loop)
{
  do { } while (0);

  if (((loop)->timercnt) && (((loop)->timers) [(4 - 1)]).at < ((loop)->mn_now))
    {
      do
        {
          ev_timer *w = (ev_timer *)(((loop)->timers) [(4 - 1)]).w;




          if (w->repeat)
            {
              ((WT)(w))->at += w->repeat;
              if (((WT)(w))->at < ((loop)->mn_now))
                ((WT)(w))->at = ((loop)->mn_now);

              
# 3366 "ev.c" 3
             ((
# 3366 "ev.c"
             ("libev: negative ev_timer repeat value found while processing timers", w->repeat > 0.)
# 3366 "ev.c" 3
             ) ? (void)0 : _assert(
# 3366 "ev.c"
             "(\"libev: negative ev_timer repeat value found while processing timers\", w->repeat > 0.)"
# 3366 "ev.c" 3
             , "ev.c", 3366))
# 3366 "ev.c"
                                                                                                             ;

              (((loop)->timers) [(4 - 1)]).at = (((loop)->timers) [(4 - 1)]).w->at;
              downheap (((loop)->timers), ((loop)->timercnt), (4 - 1));
            }
          else
            ev_timer_stop (loop, w);

          do { } while (0);
          feed_reverse (loop, (W)w);
        }
      while (((loop)->timercnt) && (((loop)->timers) [(4 - 1)]).at < ((loop)->mn_now));

      feed_reverse_done (loop, EV_TIMER);
    }
}



__attribute__ ((__noinline__))
static void
periodic_recalc (struct ev_loop *loop, ev_periodic *w)
{
  ev_tstamp interval = w->interval > 0.0001220703125 ? w->interval : 0.0001220703125;
  ev_tstamp at = w->offset + interval * ev_floor ((((loop)->ev_rt_now) - w->offset) / interval);


  while (at <= ((loop)->ev_rt_now))
    {
      ev_tstamp nat = at + w->interval;


      if (__builtin_expect ((!!(nat == at)),(0)))
        {
          at = ((loop)->ev_rt_now);
          break;
        }

      at = nat;
    }

  ((WT)(w))->at = at;
}


static inline void
periodics_reify (struct ev_loop *loop)
{
  do { } while (0);

  while (((loop)->periodiccnt) && (((loop)->periodics) [(4 - 1)]).at < ((loop)->ev_rt_now))
    {
      do
        {
          ev_periodic *w = (ev_periodic *)(((loop)->periodics) [(4 - 1)]).w;




          if (w->reschedule_cb)
            {
              ((WT)(w))->at = w->reschedule_cb (w, ((loop)->ev_rt_now));

              
# 3429 "ev.c" 3
             ((
# 3429 "ev.c"
             ("libev: ev_periodic reschedule callback returned time in the past", ((WT)(w))->at >= ((loop)->ev_rt_now))
# 3429 "ev.c" 3
             ) ? (void)0 : _assert(
# 3429 "ev.c"
             "(\"libev: ev_periodic reschedule callback returned time in the past\", ev_at (w) >= ev_rt_now)"
# 3429 "ev.c" 3
             , "ev.c", 3429))
# 3429 "ev.c"
                                                                                                                  ;

              (((loop)->periodics) [(4 - 1)]).at = (((loop)->periodics) [(4 - 1)]).w->at;
              downheap (((loop)->periodics), ((loop)->periodiccnt), (4 - 1));
            }
          else if (w->interval)
            {
              periodic_recalc (loop, w);
              (((loop)->periodics) [(4 - 1)]).at = (((loop)->periodics) [(4 - 1)]).w->at;
              downheap (((loop)->periodics), ((loop)->periodiccnt), (4 - 1));
            }
          else
            ev_periodic_stop (loop, w);

          do { } while (0);
          feed_reverse (loop, (W)w);
        }
      while (((loop)->periodiccnt) && (((loop)->periodics) [(4 - 1)]).at < ((loop)->ev_rt_now));

      feed_reverse_done (loop, EV_PERIODIC);
    }
}



__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
periodics_reschedule (struct ev_loop *loop)
{
  int i;


  for (i = (4 - 1); i < ((loop)->periodiccnt) + (4 - 1); ++i)
    {
      ev_periodic *w = (ev_periodic *)(((loop)->periodics) [i]).w;

      if (w->reschedule_cb)
        ((WT)(w))->at = w->reschedule_cb (w, ((loop)->ev_rt_now));
      else if (w->interval)
        periodic_recalc (loop, w);

      (((loop)->periodics) [i]).at = (((loop)->periodics) [i]).w->at;
    }

  reheap (((loop)->periodics), ((loop)->periodiccnt));
}



__attribute__ ((__noinline__)) __attribute__ ((__cold__))
static void
timers_reschedule (struct ev_loop *loop, ev_tstamp adjust)
{
  int i;

  for (i = 0; i < ((loop)->timercnt); ++i)
    {
      ANHE *he = ((loop)->timers) + i + (4 - 1);
      (*he).w->at += adjust;
      (*he).at = (*he).w->at;
    }
}



static inline void
time_update (struct ev_loop *loop, ev_tstamp max_block)
{
# 3547 "ev.c"
    {
      ((loop)->ev_rt_now) = ev_time ();

      if (__builtin_expect ((!!(((loop)->mn_now) > ((loop)->ev_rt_now) || ((loop)->ev_rt_now) > ((loop)->mn_now) + max_block + 1.)),(0)))
        {

          timers_reschedule (loop, ((loop)->ev_rt_now) - ((loop)->mn_now));

          periodics_reschedule (loop);

        }

      ((loop)->mn_now) = ((loop)->ev_rt_now);
    }
}

int
ev_run (struct ev_loop *loop, int flags)
{

  ++((loop)->loop_depth);


  
# 3570 "ev.c" 3
 ((
# 3570 "ev.c"
 ("libev: ev_loop recursion during release detected", ((loop)->loop_done) != 0x80)
# 3570 "ev.c" 3
 ) ? (void)0 : _assert(
# 3570 "ev.c"
 "(\"libev: ev_loop recursion during release detected\", loop_done != EVBREAK_RECURSE)"
# 3570 "ev.c" 3
 , "ev.c", 3570))
# 3570 "ev.c"
                                                                                            ;

  ((loop)->loop_done) = EVBREAK_CANCEL;

  ((loop)->invoke_cb) (loop);

  do
    {
# 3593 "ev.c"
      if (__builtin_expect ((!!(((loop)->postfork))),(0)))
        if (((loop)->forkcnt))
          {
            queue_events (loop, (W *)((loop)->forks), ((loop)->forkcnt), EV_FORK);
            ((loop)->invoke_cb) (loop);
          }




      if (__builtin_expect ((!!(((loop)->preparecnt))),(0)))
        {
          queue_events (loop, (W *)((loop)->prepares), ((loop)->preparecnt), EV_PREPARE);
          ((loop)->invoke_cb) (loop);
        }


      if (__builtin_expect ((!!(((loop)->loop_done))),(0)))
        break;


      if (__builtin_expect ((!!(((loop)->postfork))),(0)))
        loop_fork (loop);


      fd_reify (loop);


      {
        ev_tstamp waittime = 0.;
        ev_tstamp sleeptime = 0.;


        ev_tstamp prev_mn_now = ((loop)->mn_now);


        time_update (loop, 1e100);


        ((loop)->pipe_write_wanted) = 1;

        __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory");

        if (__builtin_expect ((!!(!(flags & EVRUN_NOWAIT || ((loop)->idleall) || !((loop)->activecnt) || ((loop)->pipe_write_skipped)))),(1)))
          {
            waittime = 59.743;

            if (((loop)->timercnt))
              {
                ev_tstamp to = (((loop)->timers) [(4 - 1)]).at - ((loop)->mn_now);
                if (waittime > to) waittime = to;
              }


            if (((loop)->periodiccnt))
              {
                ev_tstamp to = (((loop)->periodics) [(4 - 1)]).at - ((loop)->ev_rt_now);
                if (waittime > to) waittime = to;
              }



            if (__builtin_expect ((!!(waittime < ((loop)->timeout_blocktime))),(0)))
              waittime = ((loop)->timeout_blocktime);



            if (__builtin_expect ((!!(waittime < ((loop)->backend_mintime))),(0)))
              waittime = ((loop)->backend_mintime);


            if (__builtin_expect ((!!(((loop)->io_blocktime))),(0)))
              {
                sleeptime = ((loop)->io_blocktime) - (((loop)->mn_now) - prev_mn_now);

                if (sleeptime > waittime - ((loop)->backend_mintime))
                  sleeptime = waittime - ((loop)->backend_mintime);

                if (__builtin_expect ((!!(sleeptime > 0.)),(1)))
                  {
                    ev_sleep (sleeptime);
                    waittime -= sleeptime;
                  }
              }
          }


        ++((loop)->loop_count);

        
# 3682 "ev.c" 3
       ((
# 3682 "ev.c"
       (((loop)->loop_done) = 0x80, 1)
# 3682 "ev.c" 3
       ) ? (void)0 : _assert(
# 3682 "ev.c"
       "(loop_done = EVBREAK_RECURSE, 1)"
# 3682 "ev.c" 3
       , "ev.c", 3682))
# 3682 "ev.c"
                                                ;
        ((loop)->backend_poll) (loop, waittime);
        
# 3684 "ev.c" 3
       ((
# 3684 "ev.c"
       (((loop)->loop_done) = EVBREAK_CANCEL, 1)
# 3684 "ev.c" 3
       ) ? (void)0 : _assert(
# 3684 "ev.c"
       "(loop_done = EVBREAK_CANCEL, 1)"
# 3684 "ev.c" 3
       , "ev.c", 3684))
# 3684 "ev.c"
                                               ;

        ((loop)->pipe_write_wanted) = 0;

        __asm__ __volatile__ ("" : : : "memory");
        if (((loop)->pipe_write_skipped))
          {
            
# 3691 "ev.c" 3
           ((
# 3691 "ev.c"
           ("libev: pipe_w not active, but pipe not written", (0 + ((ev_watcher *)(void *)(&((loop)->pipe_w)))->active))
# 3691 "ev.c" 3
           ) ? (void)0 : _assert(
# 3691 "ev.c"
           "(\"libev: pipe_w not active, but pipe not written\", ev_is_active (&pipe_w))"
# 3691 "ev.c" 3
           , "ev.c", 3691))
# 3691 "ev.c"
                                                                                              ;
            ev_feed_event (loop, &((loop)->pipe_w), EV_CUSTOM);
          }



        time_update (loop, waittime + sleeptime);
      }


      timers_reify (loop);

      periodics_reify (loop);




      idle_reify (loop);




      if (__builtin_expect ((!!(((loop)->checkcnt))),(0)))
        queue_events (loop, (W *)((loop)->checks), ((loop)->checkcnt), EV_CHECK);


      ((loop)->invoke_cb) (loop);
    }
  while (__builtin_expect ((!!(((loop)->activecnt) && !((loop)->loop_done) && !(flags & (EVRUN_ONCE | EVRUN_NOWAIT)))),(1))



   );

  if (((loop)->loop_done) == EVBREAK_ONE)
    ((loop)->loop_done) = EVBREAK_CANCEL;


  --((loop)->loop_depth);


  return ((loop)->activecnt);
}

void
ev_break (struct ev_loop *loop, int how) throw ()
{
  ((loop)->loop_done) = how;
}

void
ev_ref (struct ev_loop *loop) throw ()
{
  ++((loop)->activecnt);
}

void
ev_unref (struct ev_loop *loop) throw ()
{
  --((loop)->activecnt);
}

void
ev_now_update (struct ev_loop *loop) throw ()
{
  time_update (loop, 1e100);
}

void
ev_suspend (struct ev_loop *loop) throw ()
{
  ev_now_update (loop);
}

void
ev_resume (struct ev_loop *loop) throw ()
{
  ev_tstamp mn_prev = ((loop)->mn_now);

  ev_now_update (loop);
  timers_reschedule (loop, ((loop)->mn_now) - mn_prev);


  periodics_reschedule (loop);

}




static inline void
wlist_add (WL *head, WL elem)
{
  elem->next = *head;
  *head = elem;
}

static inline void
wlist_del (WL *head, WL elem)
{
  while (*head)
    {
      if (__builtin_expect ((!!(*head == elem)),(1)))
        {
          *head = elem->next;
          break;
        }

      head = &(*head)->next;
    }
}


static inline void
clear_pending (struct ev_loop *loop, W w)
{
  if (w->pending)
    {
      ((loop)->pendings) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][w->pending - 1].w = (W)&((loop)->pending_w);
      w->pending = 0;
    }
}

int
ev_clear_pending (struct ev_loop *loop, void *w) throw ()
{
  W w_ = (W)w;
  int pending = w_->pending;

  if (__builtin_expect ((!!(pending)),(1)))
    {
      ANPENDING *p = ((loop)->pendings) [(((W)w_)->priority - (((0x7f) & 4) ? -2 : 0))] + pending - 1;
      p->w = (W)&((loop)->pending_w);
      w_->pending = 0;
      return p->events;
    }
  else
    return 0;
}

static inline void
pri_adjust (struct ev_loop *loop, W w)
{
  int pri = (+(((ev_watcher *)(void *)(w))->priority));
  pri = pri < (((0x7f) & 4) ? -2 : 0) ? (((0x7f) & 4) ? -2 : 0) : pri;
  pri = pri > (((0x7f) & 4) ? +2 : 0) ? (((0x7f) & 4) ? +2 : 0) : pri;
  ( (ev_watcher *)(void *)(w))->priority = (pri);
}

static inline void
ev_start (struct ev_loop *loop, W w, int active)
{
  pri_adjust (loop, w);
  w->active = active;
  ev_ref (loop);
}

static inline void
ev_stop (struct ev_loop *loop, W w)
{
  ev_unref (loop);
  w->active = 0;
}



__attribute__ ((__noinline__))
void
ev_io_start (struct ev_loop *loop, ev_io *w) throw ()
{
  int fd = w->fd;

  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  
# 3866 "ev.c" 3
 ((
# 3866 "ev.c"
 ("libev: ev_io_start called with negative fd", fd >= 0)
# 3866 "ev.c" 3
 ) ? (void)0 : _assert(
# 3866 "ev.c"
 "(\"libev: ev_io_start called with negative fd\", fd >= 0)"
# 3866 "ev.c" 3
 , "ev.c", 3866))
# 3866 "ev.c"
                                                                 ;
  
# 3867 "ev.c" 3
 ((
# 3867 "ev.c"
 ("libev: ev_io_start called with illegal event mask", !(w->events & ~(EV__IOFDSET | EV_READ | EV_WRITE)))
# 3867 "ev.c" 3
 ) ? (void)0 : _assert(
# 3867 "ev.c"
 "(\"libev: ev_io_start called with illegal event mask\", !(w->events & ~(EV__IOFDSET | EV_READ | EV_WRITE)))"
# 3867 "ev.c" 3
 , "ev.c", 3867))
# 3867 "ev.c"
                                                                                                                   ;

  do { } while (0);

  ev_start (loop, (W)w, 1);
  if (__builtin_expect ((!!((fd + 1) > (((loop)->anfdmax)))),(0))) { 
	  __attribute__ ((__unused__)) int ocur_ = (((loop)->anfdmax)); 
	  (((loop)->anfds)) = (ANFD *)array_realloc (sizeof (ANFD), (((loop)->anfds)), &(((loop)->anfdmax)), (fd + 1)); 
	  memset ((void *)((((loop)->anfds)) + (ocur_)), 0, sizeof (*((((loop)->anfds)) + (ocur_))) * ((((loop)->anfdmax)) - ocur_)); 
  };
  wlist_add (&((loop)->anfds)[fd].head, (WL)w);


  
# 3876 "ev.c" 3
 ((
# 3876 "ev.c"
 ("libev: ev_io_start called with corrupted watcher", ((WL)w)->next != (WL)w)
# 3876 "ev.c" 3
 ) ? (void)0 : _assert(
# 3876 "ev.c"
 "(\"libev: ev_io_start called with corrupted watcher\", ((WL)w)->next != (WL)w)"
# 3876 "ev.c" 3
 , "ev.c", 3876))
# 3876 "ev.c"
                                                                                      ;

  fd_change (loop, fd, w->events & EV__IOFDSET | 1);
  w->events &= ~EV__IOFDSET;

  do { } while (0);
}

__attribute__ ((__noinline__))
void
ev_io_stop (struct ev_loop *loop, ev_io *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  
# 3892 "ev.c" 3
 ((
# 3892 "ev.c"
 ("libev: ev_io_stop called with illegal fd (must stay constant after start!)", w->fd >= 0 && w->fd < ((loop)->anfdmax))
# 3892 "ev.c" 3
 ) ? (void)0 : _assert(
# 3892 "ev.c"
 "(\"libev: ev_io_stop called with illegal fd (must stay constant after start!)\", w->fd >= 0 && w->fd < anfdmax)"
# 3892 "ev.c" 3
 , "ev.c", 3892))
# 3892 "ev.c"
                                                                                                                       ;

  do { } while (0);

  wlist_del (&((loop)->anfds)[w->fd].head, (WL)w);
  ev_stop (loop, (W)w);

  fd_change (loop, w->fd, 1);

  do { } while (0);
}

__attribute__ ((__noinline__))
void
ev_timer_start (struct ev_loop *loop, ev_timer *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  ((WT)(w))->at += ((loop)->mn_now);

  
# 3913 "ev.c" 3
 ((
# 3913 "ev.c"
 ("libev: ev_timer_start called with negative timer repeat value", w->repeat >= 0.)
# 3913 "ev.c" 3
 ) ? (void)0 : _assert(
# 3913 "ev.c"
 "(\"libev: ev_timer_start called with negative timer repeat value\", w->repeat >= 0.)"
# 3913 "ev.c" 3
 , "ev.c", 3913))
# 3913 "ev.c"
                                                                                            ;

  do { } while (0);

  ++((loop)->timercnt);
  ev_start (loop, (W)w, ((loop)->timercnt) + (4 - 1) - 1);
  if (__builtin_expect ((!!((((W)(w))->active + 1) > (((loop)->timermax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->timermax)); (((loop)->timers)) = (ANHE *)array_realloc (sizeof (ANHE), (((loop)->timers)), &(((loop)->timermax)), (((W)(w))->active + 1)); ; };
  (((loop)->timers) [((W)(w))->active]).w = (WT)w;
  (((loop)->timers) [((W)(w))->active]).at = (((loop)->timers) [((W)(w))->active]).w->at;
  upheap (((loop)->timers), ((W)(w))->active);

  do { } while (0);


}

__attribute__ ((__noinline__))
void
ev_timer_stop (struct ev_loop *loop, ev_timer *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    
# 3942 "ev.c" 3
   ((
# 3942 "ev.c"
   ("libev: internal timer heap corruption", (((loop)->timers) [active]).w == (WT)w)
# 3942 "ev.c" 3
   ) ? (void)0 : _assert(
# 3942 "ev.c"
   "(\"libev: internal timer heap corruption\", ANHE_w (timers [active]) == (WT)w)"
# 3942 "ev.c" 3
   , "ev.c", 3942))
# 3942 "ev.c"
                                                                                        ;

    --((loop)->timercnt);

    if (__builtin_expect ((!!(active < ((loop)->timercnt) + (4 - 1))),(1)))
      {
        ((loop)->timers) [active] = ((loop)->timers) [((loop)->timercnt) + (4 - 1)];
        adjustheap (((loop)->timers), ((loop)->timercnt), active);
      }
  }

  ((WT)(w))->at -= ((loop)->mn_now);

  ev_stop (loop, (W)w);

  do { } while (0);
}

__attribute__ ((__noinline__))
void
ev_timer_again (struct ev_loop *loop, ev_timer *w) throw ()
{
  do { } while (0);

  clear_pending (loop, (W)w);

  if ((0 + ((ev_watcher *)(void *)(w))->active))
    {
      if (w->repeat)
        {
          ((WT)(w))->at = ((loop)->mn_now) + w->repeat;
          (((loop)->timers) [((W)(w))->active]).at = (((loop)->timers) [((W)(w))->active]).w->at;
          adjustheap (((loop)->timers), ((loop)->timercnt), ((W)(w))->active);
        }
      else
        ev_timer_stop (loop, w);
    }
  else if (w->repeat)
    {
      ((WT)(w))->at = w->repeat;
      ev_timer_start (loop, w);
    }

  do { } while (0);
}

ev_tstamp
ev_timer_remaining (struct ev_loop *loop, ev_timer *w) throw ()
{
  return ((WT)(w))->at - ((0 + ((ev_watcher *)(void *)(w))->active) ? ((loop)->mn_now) : 0.);
}


__attribute__ ((__noinline__))
void
ev_periodic_start (struct ev_loop *loop, ev_periodic *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  if (w->reschedule_cb)
    ((WT)(w))->at = w->reschedule_cb (w, ((loop)->ev_rt_now));
  else if (w->interval)
    {
      
# 4006 "ev.c" 3
     ((
# 4006 "ev.c"
     ("libev: ev_periodic_start called with negative interval value", w->interval >= 0.)
# 4006 "ev.c" 3
     ) ? (void)0 : _assert(
# 4006 "ev.c"
     "(\"libev: ev_periodic_start called with negative interval value\", w->interval >= 0.)"
# 4006 "ev.c" 3
     , "ev.c", 4006))
# 4006 "ev.c"
                                                                                                 ;
      periodic_recalc (loop, w);
    }
  else
    ((WT)(w))->at = w->offset;

  do { } while (0);

  ++((loop)->periodiccnt);
  ev_start (loop, (W)w, ((loop)->periodiccnt) + (4 - 1) - 1);
  if (__builtin_expect ((!!((((W)(w))->active + 1) > (((loop)->periodicmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->periodicmax)); (((loop)->periodics)) = (ANHE *)array_realloc (sizeof (ANHE), (((loop)->periodics)), &(((loop)->periodicmax)), (((W)(w))->active + 1)); ; };
  (((loop)->periodics) [((W)(w))->active]).w = (WT)w;
  (((loop)->periodics) [((W)(w))->active]).at = (((loop)->periodics) [((W)(w))->active]).w->at;
  upheap (((loop)->periodics), ((W)(w))->active);

  do { } while (0);


}

__attribute__ ((__noinline__))
void
ev_periodic_stop (struct ev_loop *loop, ev_periodic *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    
# 4039 "ev.c" 3
   ((
# 4039 "ev.c"
   ("libev: internal periodic heap corruption", (((loop)->periodics) [active]).w == (WT)w)
# 4039 "ev.c" 3
   ) ? (void)0 : _assert(
# 4039 "ev.c"
   "(\"libev: internal periodic heap corruption\", ANHE_w (periodics [active]) == (WT)w)"
# 4039 "ev.c" 3
   , "ev.c", 4039))
# 4039 "ev.c"
                                                                                              ;

    --((loop)->periodiccnt);

    if (__builtin_expect ((!!(active < ((loop)->periodiccnt) + (4 - 1))),(1)))
      {
        ((loop)->periodics) [active] = ((loop)->periodics) [((loop)->periodiccnt) + (4 - 1)];
        adjustheap (((loop)->periodics), ((loop)->periodiccnt), active);
      }
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}

__attribute__ ((__noinline__))
void
ev_periodic_again (struct ev_loop *loop, ev_periodic *w) throw ()
{

  ev_periodic_stop (loop, w);
  ev_periodic_start (loop, w);
}
# 4071 "ev.c"
__attribute__ ((__noinline__))
void
ev_signal_start (struct ev_loop *loop, ev_signal *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  
# 4078 "ev.c" 3
 ((
# 4078 "ev.c"
 ("libev: ev_signal_start called with illegal signal number", w->signum > 0 && w->signum < (
# 4078 "ev.c" 3
 23
# 4078 "ev.c"
 ))
# 4078 "ev.c" 3
 ) ? (void)0 : _assert(
# 4078 "ev.c"
 "(\"libev: ev_signal_start called with illegal signal number\", w->signum > 0 && w->signum < EV_NSIG)"
# 4078 "ev.c" 3
 , "ev.c", 4078))
# 4078 "ev.c"
                                                                                                            ;


  
# 4081 "ev.c" 3
 ((
# 4081 "ev.c"
 ("libev: a signal must not be attached to two different loops", !signals [w->signum - 1].loop || signals [w->signum - 1].loop == loop)
# 4081 "ev.c" 3
 ) ? (void)0 : _assert(
# 4081 "ev.c"
 "(\"libev: a signal must not be attached to two different loops\", !signals [w->signum - 1].loop || signals [w->signum - 1].loop == loop)"
# 4081 "ev.c" 3
 ,
                                                                                 "ev.c"
# 4081 "ev.c" 3
  ,
                                                                                 4082
# 4081 "ev.c" 3
  ))
                                                                                  
# 4082 "ev.c"
                                                                                 ;

  signals [w->signum - 1].loop = loop;
  __asm__ __volatile__ ("");


  do { } while (0);
# 4120 "ev.c"
  ev_start (loop, (W)w, 1);
  wlist_add (&signals [w->signum - 1].head, (WL)w);

  if (!((WL)w)->next)



      {

        evpipe_init (loop);

        signal (w->signum, ev_sighandler);
# 4149 "ev.c"
      }

  do { } while (0);
}

__attribute__ ((__noinline__))
void
ev_signal_stop (struct ev_loop *loop, ev_signal *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  wlist_del (&signals [w->signum - 1].head, (WL)w);
  ev_stop (loop, (W)w);

  if (!signals [w->signum - 1].head)
    {

      signals [w->signum - 1].loop = 0;
# 4186 "ev.c"
        signal (w->signum, 
# 4186 "ev.c" 3
                          ((__p_sig_fn_t) 0)
# 4186 "ev.c"
                                 );
    }

  do { } while (0);
}
# 4241 "ev.c"
__attribute__ ((__noinline__)) static void stat_timer_cb (struct ev_loop *loop, ev_timer *w_, int revents);
# 4488 "ev.c"
void
ev_stat_stat (struct ev_loop *loop, ev_stat *w) throw ()
{
  if (_stati64 (w->path,&w->attr) < 0)
    w->attr.st_nlink = 0;
  else if (!w->attr.st_nlink)
    w->attr.st_nlink = 1;
}

__attribute__ ((__noinline__))
static void
stat_timer_cb (struct ev_loop *loop, ev_timer *w_, int revents)
{
  ev_stat *w = (ev_stat *)(((char *)w_) - 
# 4501 "ev.c" 3 4
                                         __builtin_offsetof (
# 4501 "ev.c"
                                         ev_stat
# 4501 "ev.c" 3 4
                                         , 
# 4501 "ev.c"
                                         timer
# 4501 "ev.c" 3 4
                                         )
# 4501 "ev.c"
                                                                  );

  ev_statdata prev = w->attr;
  ev_stat_stat (loop, w);


  if (
    prev.st_dev != w->attr.st_dev
    || prev.st_ino != w->attr.st_ino
    || prev.st_mode != w->attr.st_mode
    || prev.st_nlink != w->attr.st_nlink
    || prev.st_uid != w->attr.st_uid
    || prev.st_gid != w->attr.st_gid
    || prev.st_rdev != w->attr.st_rdev
    || prev.st_size != w->attr.st_size
    || prev.st_atime != w->attr.st_atime
    || prev.st_mtime != w->attr.st_mtime
    || prev.st_ctime != w->attr.st_ctime
  ) {



      w->prev = prev;
# 4534 "ev.c"
      ev_feed_event (loop, w, EV_STAT);
    }
}

void
ev_stat_start (struct ev_loop *loop, ev_stat *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  ev_stat_stat (loop, w);

  if (w->interval < 0.1074891 && w->interval)
    w->interval = 0.1074891;

  do { do { ((ev_watcher *)(void *)((&w->timer)))->active = ((ev_watcher *)(void *)((&w->timer)))->pending = 0; ( (ev_watcher *)(void *)(((&w->timer))))->priority = (0); ((((&w->timer)))->cb = ((stat_timer_cb)), memmove (&((ev_watcher *)(((&w->timer))))->cb, &(((&w->timer)))->cb, sizeof ((((&w->timer)))->cb))); } while (0); do { ((ev_watcher_time *)((&w->timer)))->at = ((0.)); ((&w->timer))->repeat = ((w->interval ? w->interval : 5.0074891)); } while (0); } while (0);
  ( (ev_watcher *)(void *)(&w->timer))->priority = ((+(((ev_watcher *)(void *)(w))->priority)));
# 4559 "ev.c"
    {
      ev_timer_again (loop, &w->timer);
      ev_unref (loop);
    }

  ev_start (loop, (W)w, 1);

  do { } while (0);
}

void
ev_stat_stop (struct ev_loop *loop, ev_stat *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);





  if ((0 + ((ev_watcher *)(void *)(&w->timer))->active))
    {
      ev_ref (loop);
      ev_timer_stop (loop, &w->timer);
    }

  ev_stop (loop, (W)w);

  do { } while (0);
}



void
ev_idle_start (struct ev_loop *loop, ev_idle *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  pri_adjust (loop, (W)w);

  do { } while (0);

  {
    int active = ++((loop)->idlecnt) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))];

    ++((loop)->idleall);
    ev_start (loop, (W)w, active);

    if (__builtin_expect ((!!((active) > (((loop)->idlemax) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->idlemax) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]); (((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]) = (ev_idle * *)array_realloc (sizeof (ev_idle *), (((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]), &(((loop)->idlemax) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]), (active)); ; };
    ((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][active - 1] = w;
  }

  do { } while (0);
}

void
ev_idle_stop (struct ev_loop *loop, ev_idle *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    ((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][active - 1] = ((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][--((loop)->idlecnt) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))]];
    ((W)(((loop)->idles) [(((W)w)->priority - (((0x7f) & 4) ? -2 : 0))][active - 1]))->active = active;

    ev_stop (loop, (W)w);
    --((loop)->idleall);
  }

  do { } while (0);
}



void
ev_prepare_start (struct ev_loop *loop, ev_prepare *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  ev_start (loop, (W)w, ++((loop)->preparecnt));
  if (__builtin_expect ((!!((((loop)->preparecnt)) > (((loop)->preparemax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->preparemax)); (((loop)->prepares)) = (ev_prepare * *)array_realloc (sizeof (ev_prepare *), (((loop)->prepares)), &(((loop)->preparemax)), (((loop)->preparecnt))); ; };
  ((loop)->prepares) [((loop)->preparecnt) - 1] = w;

  do { } while (0);
}

void
ev_prepare_stop (struct ev_loop *loop, ev_prepare *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    ((loop)->prepares) [active - 1] = ((loop)->prepares) [--((loop)->preparecnt)];
    ((W)(((loop)->prepares) [active - 1]))->active = active;
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}



void
ev_check_start (struct ev_loop *loop, ev_check *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  ev_start (loop, (W)w, ++((loop)->checkcnt));
  if (__builtin_expect ((!!((((loop)->checkcnt)) > (((loop)->checkmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->checkmax)); (((loop)->checks)) = (ev_check * *)array_realloc (sizeof (ev_check *), (((loop)->checks)), &(((loop)->checkmax)), (((loop)->checkcnt))); ; };
  ((loop)->checks) [((loop)->checkcnt) - 1] = w;

  do { } while (0);
}

void
ev_check_stop (struct ev_loop *loop, ev_check *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    ((loop)->checks) [active - 1] = ((loop)->checks) [--((loop)->checkcnt)];
    ((W)(((loop)->checks) [active - 1]))->active = active;
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}



__attribute__ ((__noinline__))
void
ev_embed_sweep (struct ev_loop *loop, ev_embed *w) throw ()
{
  ev_run (w->other, EVRUN_NOWAIT);
}

static void
embed_io_cb (struct ev_loop *loop, ev_io *io, int revents)
{
  ev_embed *w = (ev_embed *)(((char *)io) - 
# 4728 "ev.c" 3 4
                                           __builtin_offsetof (
# 4728 "ev.c"
                                           ev_embed
# 4728 "ev.c" 3 4
                                           , 
# 4728 "ev.c"
                                           io
# 4728 "ev.c" 3 4
                                           )
# 4728 "ev.c"
                                                                  );

  if ((memmove (&(w)->cb, &((ev_watcher *)(w))->cb, sizeof ((w)->cb)), (w)->cb))
    ev_feed_event (loop, (W)w, EV_EMBED);
  else
    ev_run (w->other, EVRUN_NOWAIT);
}

static void
embed_prepare_cb (struct ev_loop *loop, ev_prepare *prepare, int revents)
{
  ev_embed *w = (ev_embed *)(((char *)prepare) - 
# 4739 "ev.c" 3 4
                                                __builtin_offsetof (
# 4739 "ev.c"
                                                ev_embed
# 4739 "ev.c" 3 4
                                                , 
# 4739 "ev.c"
                                                prepare
# 4739 "ev.c" 3 4
                                                )
# 4739 "ev.c"
                                                                            );

  {
    struct ev_loop *loop = w->other;

    while (((loop)->fdchangecnt))
      {
        fd_reify (loop);
        ev_run (loop, EVRUN_NOWAIT);
      }
  }
}

static void
embed_fork_cb (struct ev_loop *loop, ev_fork *fork_w, int revents)
{
  ev_embed *w = (ev_embed *)(((char *)fork_w) - 
# 4755 "ev.c" 3 4
                                               __builtin_offsetof (
# 4755 "ev.c"
                                               ev_embed
# 4755 "ev.c" 3 4
                                               , 
# 4755 "ev.c"
                                               fork
# 4755 "ev.c" 3 4
                                               )
# 4755 "ev.c"
                                                                        );

  ev_embed_stop (loop, w);

  {
    struct ev_loop *loop = w->other;

    ev_loop_fork (loop);
    ev_run (loop, EVRUN_NOWAIT);
  }

  ev_embed_start (loop, w);
}
# 4777 "ev.c"
void
ev_embed_start (struct ev_loop *loop, ev_embed *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  {
    struct ev_loop *loop = w->other;
    
# 4785 "ev.c" 3
   ((
# 4785 "ev.c"
   ("libev: loop to be embedded is not embeddable", ((loop)->backend) & ev_embeddable_backends ())
# 4785 "ev.c" 3
   ) ? (void)0 : _assert(
# 4785 "ev.c"
   "(\"libev: loop to be embedded is not embeddable\", backend & ev_embeddable_backends ())"
# 4785 "ev.c" 3
   , "ev.c", 4785))
# 4785 "ev.c"
                                                                                                 ;
    do { do { ((ev_watcher *)(void *)((&w->io)))->active = ((ev_watcher *)(void *)((&w->io)))->pending = 0; ( (ev_watcher *)(void *)(((&w->io))))->priority = (0); ((((&w->io)))->cb = ((embed_io_cb)), memmove (&((ev_watcher *)(((&w->io))))->cb, &(((&w->io)))->cb, sizeof ((((&w->io)))->cb))); } while (0); do { ((&w->io))->fd = ((((loop)->backend_fd))); ((&w->io))->events = ((EV_READ)) | EV__IOFDSET; } while (0); } while (0);
  }

  do { } while (0);

  ( (ev_watcher *)(void *)(&w->io))->priority = ((+(((ev_watcher *)(void *)(w))->priority)));
  ev_io_start (loop, &w->io);

  do { do { ((ev_watcher *)(void *)((&w->prepare)))->active = ((ev_watcher *)(void *)((&w->prepare)))->pending = 0; ( (ev_watcher *)(void *)(((&w->prepare))))->priority = (0); ((((&w->prepare)))->cb = ((embed_prepare_cb)), memmove (&((ev_watcher *)(((&w->prepare))))->cb, &(((&w->prepare)))->cb, sizeof ((((&w->prepare)))->cb))); } while (0); ; } while (0);
  ( (ev_watcher *)(void *)(&w->prepare))->priority = ((((0x7f) & 4) ? -2 : 0));
  ev_prepare_start (loop, &w->prepare);

  do { do { ((ev_watcher *)(void *)((&w->fork)))->active = ((ev_watcher *)(void *)((&w->fork)))->pending = 0; ( (ev_watcher *)(void *)(((&w->fork))))->priority = (0); ((((&w->fork)))->cb = ((embed_fork_cb)), memmove (&((ev_watcher *)(((&w->fork))))->cb, &(((&w->fork)))->cb, sizeof ((((&w->fork)))->cb))); } while (0); ; } while (0);
  ev_fork_start (loop, &w->fork);



  ev_start (loop, (W)w, 1);

  do { } while (0);
}

void
ev_embed_stop (struct ev_loop *loop, ev_embed *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  ev_io_stop (loop, &w->io);
  ev_prepare_stop (loop, &w->prepare);
  ev_fork_stop (loop, &w->fork);

  ev_stop (loop, (W)w);

  do { } while (0);
}



void
ev_fork_start (struct ev_loop *loop, ev_fork *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  ev_start (loop, (W)w, ++((loop)->forkcnt));
  if (__builtin_expect ((!!((((loop)->forkcnt)) > (((loop)->forkmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->forkmax)); (((loop)->forks)) = (ev_fork * *)array_realloc (sizeof (ev_fork *), (((loop)->forks)), &(((loop)->forkmax)), (((loop)->forkcnt))); ; };
  ((loop)->forks) [((loop)->forkcnt) - 1] = w;

  do { } while (0);
}

void
ev_fork_stop (struct ev_loop *loop, ev_fork *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    ((loop)->forks) [active - 1] = ((loop)->forks) [--((loop)->forkcnt)];
    ((W)(((loop)->forks) [active - 1]))->active = active;
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}



void
ev_cleanup_start (struct ev_loop *loop, ev_cleanup *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  ev_start (loop, (W)w, ++((loop)->cleanupcnt));
  if (__builtin_expect ((!!((((loop)->cleanupcnt)) > (((loop)->cleanupmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->cleanupmax)); (((loop)->cleanups)) = (ev_cleanup * *)array_realloc (sizeof (ev_cleanup *), (((loop)->cleanups)), &(((loop)->cleanupmax)), (((loop)->cleanupcnt))); ; };
  ((loop)->cleanups) [((loop)->cleanupcnt) - 1] = w;


  ev_unref (loop);
  do { } while (0);
}

void
ev_cleanup_stop (struct ev_loop *loop, ev_cleanup *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);
  ev_ref (loop);

  {
    int active = ((W)(w))->active;

    ((loop)->cleanups) [active - 1] = ((loop)->cleanups) [--((loop)->cleanupcnt)];
    ((W)(((loop)->cleanups) [active - 1]))->active = active;
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}



void
ev_async_start (struct ev_loop *loop, ev_async *w) throw ()
{
  if (__builtin_expect ((!!((0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  w->sent = 0;

  evpipe_init (loop);

  do { } while (0);

  ev_start (loop, (W)w, ++((loop)->asynccnt));
  if (__builtin_expect ((!!((((loop)->asynccnt)) > (((loop)->asyncmax)))),(0))) { __attribute__ ((__unused__)) int ocur_ = (((loop)->asyncmax)); (((loop)->asyncs)) = (ev_async * *)array_realloc (sizeof (ev_async *), (((loop)->asyncs)), &(((loop)->asyncmax)), (((loop)->asynccnt))); ; };
  ((loop)->asyncs) [((loop)->asynccnt) - 1] = w;

  do { } while (0);
}

void
ev_async_stop (struct ev_loop *loop, ev_async *w) throw ()
{
  clear_pending (loop, (W)w);
  if (__builtin_expect ((!!(!(0 + ((ev_watcher *)(void *)(w))->active))),(0)))
    return;

  do { } while (0);

  {
    int active = ((W)(w))->active;

    ((loop)->asyncs) [active - 1] = ((loop)->asyncs) [--((loop)->asynccnt)];
    ((W)(((loop)->asyncs) [active - 1]))->active = active;
  }

  ev_stop (loop, (W)w);

  do { } while (0);
}

void
ev_async_send (struct ev_loop *loop, ev_async *w) throw ()
{
  w->sent = 1;
  evpipe_write (loop, &((loop)->async_pending));
}




struct ev_once
{
  ev_io io;
  ev_timer to;
  void (*cb)(int revents, void *arg);
  void *arg;
};

static void
once_cb (struct ev_loop *loop, struct ev_once *once, int revents)
{
  void (*cb)(int revents, void *arg) = once->cb;
  void *arg = once->arg;

  ev_io_stop (loop, &once->io);
  ev_timer_stop (loop, &once->to);
  ev_realloc ((once), 0);

  cb (revents, arg);
}

static void
once_cb_io (struct ev_loop *loop, ev_io *w, int revents)
{
  struct ev_once *once = (struct ev_once *)(((char *)w) - 
# 4981 "ev.c" 3 4
                                                         __builtin_offsetof (
# 4981 "ev.c"
                                                         struct ev_once
# 4981 "ev.c" 3 4
                                                         , 
# 4981 "ev.c"
                                                         io
# 4981 "ev.c" 3 4
                                                         )
# 4981 "ev.c"
                                                                                      );

  once_cb (loop, once, revents | ev_clear_pending (loop, &once->to));
}

static void
once_cb_to (struct ev_loop *loop, ev_timer *w, int revents)
{
  struct ev_once *once = (struct ev_once *)(((char *)w) - 
# 4989 "ev.c" 3 4
                                                         __builtin_offsetof (
# 4989 "ev.c"
                                                         struct ev_once
# 4989 "ev.c" 3 4
                                                         , 
# 4989 "ev.c"
                                                         to
# 4989 "ev.c" 3 4
                                                         )
# 4989 "ev.c"
                                                                                      );

  once_cb (loop, once, revents | ev_clear_pending (loop, &once->io));
}

void
ev_once (struct ev_loop *loop, int fd, int events, ev_tstamp timeout, void (*cb)(int revents, void *arg), void *arg) throw ()
{
  struct ev_once *once = (struct ev_once *)ev_realloc (0, (sizeof (struct ev_once)));

  if (__builtin_expect ((!!(!once)),(0)))
    {
      cb (EV_ERROR | EV_READ | EV_WRITE | EV_TIMER, arg);
      return;
    }

  once->cb = cb;
  once->arg = arg;

  do { ((ev_watcher *)(void *)(&once->io))->active = ((ev_watcher *)(void *)(&once->io))->pending = 0; ( (ev_watcher *)(void *)((&once->io)))->priority = (0); (((&once->io))->cb = (once_cb_io), memmove (&((ev_watcher *)((&once->io)))->cb, &((&once->io))->cb, sizeof (((&once->io))->cb))); } while (0);
  if (fd >= 0)
    {
      do { (&once->io)->fd = (fd); (&once->io)->events = (events) | EV__IOFDSET; } while (0);
      ev_io_start (loop, &once->io);
    }

  do { ((ev_watcher *)(void *)(&once->to))->active = ((ev_watcher *)(void *)(&once->to))->pending = 0; ( (ev_watcher *)(void *)((&once->to)))->priority = (0); (((&once->to))->cb = (once_cb_to), memmove (&((ev_watcher *)((&once->to)))->cb, &((&once->to))->cb, sizeof (((&once->to))->cb))); } while (0);
  if (timeout >= 0.)
    {
      do { ((ev_watcher_time *)(&once->to))->at = (timeout); (&once->to)->repeat = (0.); } while (0);
      ev_timer_start (loop, &once->to);
    }
}
# 5141 "ev.c"
# 1 "ev_wrap.h" 1
# 5142 "ev.c" 2
