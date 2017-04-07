#pragma once
#include <new>
#include <stdlib.h>

/*
RAObjList
用法：	(1) Insert时返回一个index，以后存取该元素均用该index直接进行[]下标操作
(2) 提供Iterator、Const_Iterator进行遍历操作

性能：	(1) 取值、增加等操作时间复杂度为O(1)
(2) 删除操作如果元素位于beg或end，时间复杂度为O(n)，否则为O(1)

适用：	用于可分配ID的对象管理
*/

template<class T>
class RAObjList
{
public:
	template<class U, class PARE = RAObjList>
	class _Iterator
	{
		friend class RAObjList;
	public:
		_Iterator() :index_(-1), parents_(0) {}

		_Iterator<U, PARE>& operator ++()
		{
			++index_;
			while (index_ < parents_->m_end.m_index && !parents_->m_obj_use[index_]){
				++index_;
			}
			return *this;
		}
		const _Iterator<U, PARE> operator++(int)
		{
			_Iterator<U, PARE> t = *this;
			operator ++();
			return t;
		}
		_Iterator<U, PARE>& operator --()
		{
			--index_;
			while (index_ >= parents_->m_beg.m_index && !parents_->m_obj_use[index_]){
				--index_;
			}
			return *this;
		}

		const _Iterator<U, PARE> operator--(int)
		{
			_Iterator<U, PARE> t = *this;
			operator --();
			return t;
		}

		operator U*() { return &parents_->m_obj[index_]; }
		U* operator->() { return &parents_->m_obj[index_]; }
		U& operator*() { return parents_->m_obj[index_]; }
		bool operator==(const _Iterator<U, PARE> &_right) const { return (index_ == _right.m_index && parents_ == _right.m_parents); }
		bool operator!=(const _Iterator<U, PARE> &_right) const { return (index_ != _right.m_index || parents_ != _right.m_parents); }

		unsigned int index_;
	protected:
		PARE *parents_;
		_Iterator(unsigned int index, PARE *parent = 0) :index_(index), parents_(parent) {}
	};
	typedef _Iterator<T> Iterator;
	typedef _Iterator<const T, const RAObjList<T> > Const_Iterator;

#define DEFAULT_RAOBJLISE_SIZE 32
	RAObjList(unsigned int size = DEFAULT_RAOBJLISE_SIZE)
		: obj_(0)
		, obj_use_(0)
		, obj_cur_(0)
		, obj_max_(0)
		, recovery_id_(0)
		, recovery_id_cur_(0)
		, recovery_id_max_(0)
		, begin_(0)
		, end_(0)
		, size_(0)
	{
		begin_.parents_ = this;
		end_.parents_ = this;
		_ResizeObj(size);
	}

	RAObjList(const RAObjList<T> &_raol)
	{
		_ConstructInit(_raol);
	}
	~RAObjList()
	{
		_Release();
	}
	const RAObjList<T> & operator=(const RAObjList<T> &_raol)
	{
		_Release();
		_ConstructInit(_raol);
		return *this;
	}

	void Clear()
	{
		for (unsigned int i = begin_.index_; i < end_.index_; ++i) {
			if (obj_use_[i]) { 
				obj_[i].~T();
			}
		}
		obj_cur_ = 0;
		recovery_id_cur_ = 0;
		begin_.index_ = 0;
		end_.index_ = 0;
		size_ = 0;
	}

	unsigned int Insert(const T &value)
	{
		unsigned int index = -1;
		if (recovery_id_cur_ == 0) {
			if (obj_cur_ == obj_max_) {
				unsigned int size = (obj_max_ != 0 ? obj_max_ * 2 : DEFAULT_RAOBJLISE_SIZE);
				_ResizeObj(size);
			}

			index = obj_cur_++;
		}
		else {
			--recovery_id_cur_;
			index = recovery_id_[recovery_id_cur_];
		}

		new (&obj_[index])T(value);
		obj_use_[index] = true;

		if (begin_.index_ == end_.index_) end_.index_ = (begin_.index_ = index) + 1;
		else
		{
			if (begin_.index_ > index) begin_.index_ = index;
			if (end_.index_ <= index) end_.index_ = index + 1;
		}
		++size_;
		return index;
	}

	void Erase(unsigned int index)
	{
		if (index >= obj_cur_ || !obj_use_[index]) return;

		obj_[index].~T();

		if (recovery_id_cur_ == recovery_id_max_)	{
			unsigned int size = (recovery_id_max_ != 0 ? recovery_id_max_ * 2 : 32);
			_ResizeRecoveryid(size);
		}
		recovery_id_[recovery_id_cur_++] = index;

		obj_use_[index] = false;

		if (begin_.index_ == index)	{
			unsigned int i = index;
			while (i < obj_cur_ && !obj_use_[i] && i != end_.index_) ++i;
			begin_.index_ = i;
		}
		if (end_.index_ == index + 1 && begin_.index_ != end_.index_) {
			unsigned int i = index;
			while (i < obj_cur_ && !obj_use_[i] && i != begin_.index_) --i;
			end_.index_ = i + 1;
		}
		--size_;
	}

	Iterator Find(unsigned int index)
	{
		if (index < obj_cur_ && obj_use_[index]){
			return Iterator(index, this);
		}
		return end_;
	}

	Const_Iterator Find(unsigned int index) const
	{
		if (index < obj_cur_ && obj_use_[index]){
			return Const_Iterator(index, this);
		}
		return Const_Iterator(end_.index_, this);
	}

	bool Exist(unsigned int index)
	{
		if (index < obj_cur_ && obj_use_[index]){
			return true;
		}
		return false;
	}

	Iterator Begin() { return begin_; }
	Iterator End() { return end_; }
	Const_Iterator Begin() const { return Const_Iterator(begin_.index_, this); }
	Const_Iterator End() const { return Const_Iterator(end_.index_, this); }
	T& operator[](unsigned int i) { return obj_[i]; }	// 此处不检查是否已经分配，由外部保证，如需检查请用Find
	const T& operator[](unsigned int i) const { return obj_[i]; }

	bool Empty() const { return (0 == size_); }
	unsigned int Size() const { return size_; }
protected:
	T							*obj_;
	bool						*obj_use_;

	unsigned int				obj_cur_;
	unsigned int				obj_max_;

	unsigned int				*recovery_id_;
	unsigned int				recovery_id_cur_;
	unsigned int				recovery_id_max_;

	Iterator					begin_;
	Iterator					end_;
	unsigned int				size_;

	void _ResizeObj(unsigned int size)
	{
		if (size <= obj_max_) return;
		obj_ = (T*)realloc((void *)obj_, sizeof(T) * size);
		obj_use_ = (bool*)realloc(obj_use_, sizeof(bool) * size);
		obj_max_ = size;
	}

	void _ResizeRecoveryid(unsigned int size)
	{
		if (size <= recovery_id_max_) return;
		recovery_id_ = (unsigned int *)realloc(recovery_id_, sizeof(unsigned int) * size);
		recovery_id_max_ = size;
	}

	void _ConstructInit(const RAObjList<T> &_raol)
	{
		obj_ = 0;
		obj_use_ = 0;
		obj_max_ = 0;
		_ResizeObj(_raol.obj_max_);
		obj_cur_ = _raol.obj_cur_;
		memcpy(obj_use_, _raol.obj_use_, sizeof(bool) * obj_cur_);

		recovery_id_ = 0;
		recovery_id_max_ = 0;
		_ResizeRecoveryid(_raol.recovery_id_max_);
		recovery_id_cur_ = _raol.recovery_id_cur_;
		memcpy(recovery_id_, _raol.recovery_id_, sizeof(unsigned int) * recovery_id_cur_);

		begin_.index_ = _raol.begin_.m_index;
		begin_.parents_ = this;
		end_.index_ = _raol.end_.m_index;
		end_.parents_ = this;
		size_ = _raol.size_;

		for (unsigned int i = begin_.index_; i < end_.index_; ++i)
		{
			if (obj_use_[i])
				new (&obj_[i])T(_raol.obj_[i]);
		}
	}
	void _Release()
	{
		for (unsigned int i = begin_.index_; i < end_.index_; ++i)
		{
			if (obj_use_[i])
				obj_[i].~T();
		}
		if (obj_ != 0) free((void*)obj_);
		if (obj_use_ != 0) free(obj_use_);
		if (recovery_id_ != 0) free(recovery_id_);
	}
};



