#pragma once

template<class T>
class Shared
{
private:
	T* _ptr = nullptr;
	int* _count = nullptr;

public:
	Shared() : _ptr(), _count(new int(0)) {}

	Shared(T* ptr) : _ptr(ptr), _count(new int(1)) {}

	Shared(const Shared& obj) { 
		_ptr = obj._ptr;
		_count = obj._count;
		if (obj._ptr)
			(*_count)++;
	}

	Shared& operator=(const Shared& obj) { 
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}

		_ptr = obj._ptr;
		_count = obj._count;
		if (nullptr != obj._ptr)
			(*_count)++;
	}

	Shared& operator=(Shared&& ll) { 
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}

		_ptr = ll._ptr;
		_count = ll._count;

		ll._ptr = nullptr;
		ll._count = nullptr;
	}

	int getCount() const { return *_count; }

	T* get() const { return _ptr; }

	T* operator->() const { return _ptr; }

	T& operator*() const { return _ptr; }

	~Shared()
	{
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}
	}
};