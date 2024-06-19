#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstddef>

namespace my
{
	template <typename T>
	class Vector
	{
		public:
			Vector();
			Vector(const size_t&);
			Vector(const Vector<T>&);
			Vector(Vector<T>&&);
			~Vector();

		public:
			Vector<T>&	operator= (const Vector<T>&);
			Vector<T>&	operator= (Vector<T>&&);

		public:
			bool	push_back(const T&);
			bool	pop_back();
			bool	push_fornt(const T&);
			bool	pop_front();
			bool	insert(const T&, const size_t&);

		class	Iterator
		{
			Iterator();
			~Iterator();
			private:
				T* _vec;
		};

		private:
			size_t	_size;
			size_t	_capacity;
			T*	_vector = nullptr;
	};

	template <typename T>
	Vector<T>::Vector() : _size(0), _capacity(0), _vector(nullptr) {}

	template <typename T>
	Vector<T>::Vector(const size_t& size) : _size(size), _capacity(2*_size), _vector(new T[_capacity]) {}

	template <typename T>
	Vector<T>::Vector(const Vector<T>& vec) : _size(vec._size), _capacity(vec._capacity), _vector(new T[_capacity])
	{
		for(size_t i = 0; i < _size; ++i)
		{
			_vector[i] = vec._vector[i];
		}
	}

	template <typename T>
	Vector<T>::Vector(Vector<T>&& vec) : _size(vec._size), _capacity(vec._capacity), _vector(vec._vector)
	{
		vec._size = 0;
		vec._capacity = 0;
		vec._vector = nullptr;
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		delete[] _vector;
	}

	template <typename T>
	Vector<T>&	Vector<T>::operator= (const Vector<T>& vec)
	{
		if(this != &vec)
		{
			T* new_vector = new T[vec._capacity];
			for(size_t i = 0; i < vec._size; ++i)
			{
				new_vector[i] = vec._vector[i];
			}
			delete[] _vector;
			_vector = new_vector;
			_size = vec._size;
			_capacity = vec._capacity;
		}
		return (*this);
	}

	template <typename T>
	Vector<T>&	Vector<T>::operator= (Vector<T>&& vec)
	{
		if(this != &vec)
		{
			delete[] _vector;
			_vector = vec._vector;
			_size = vec._size;
			_capacity = vec._capacity;

			vec._size = 0;
			vec._capacity = 0;
			vec._vector = nullptr;
		}
		return (*this);
	}

	template<typename T>
	bool	Vector<T>::push_back(const T& newElement)
	{
		bool	status = false;
		if(_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 1 : 2 * _capacity;
			T*	tmp = new T[newCapacity];
			for(int i = 0; i < _size; ++i)
			{
				tmp[i] = _vector[i];
			}
			delete[] _vector;
			_vector = tmp;
			tmp = nullptr;
			_capacity = newCapacity;
		}
		_vector[_size++] = newElement;
		status = true;

		return (status);
	}

	template <typename T>
	bool	Vector<T>::pop_back()
	{
		if (_size == 0)
			return false;
		--_size;

		return true;
	}

	template <typename T>
	bool	Vector<T>::push_fornt(const T& newElement)
	{
		bool	status = false;
		if(_size >= _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 1 : 2 * _capacity;
			T*	tmp = new T[newCapacity];
			tmp[0] = newElement;
			for(int i = 0; i < _size; ++i)
			{
				tmp[i + 1] = _vector[i];
			}
			delete[] _vector;
			_vector = tmp;
			tmp = nullptr;
			_capacity = newCapacity;
			_size++;
			status = true;
		}
		else
		{
			for (int i = (_size - 1); i >= 0; --i)
			{
				_vector[i + 1] = _vector[i];
			}
			_vector[0] = newElement;
			_size++;
			status = true;
		}
		return status;
	}

	template <typename T>
	bool	Vector<T>::pop_front()
	{
		bool	status = false;
		if(_size != 0)
		{
			for(int i = 0; i < _size; ++i)
			{
				_vector[i] = _vector[i + 1];
			}
			_size--;
			status = true;
		}
		return status;
	}

	template <typename T>
	bool	Vector<T>::insert(const T& newElement, const size_t& index)
	{
		bool	status = false;
		if(index <= _size)
		{
			if(index == _size)
				push_back(newElement);
			else if(index == 0)
				push_fornt(newElement);
			else
			{
				if(_size == _capacity)
				{
					size_t newCapacity = _capacity == 0 ? 1 : 2 * _capacity;
					T*	tmp = new T[newCapacity];
					for (size_t i = 0; i < index; i++)
					{
						tmp[i] = _vector[i];
					}
					tmp[index] = newElement;
					for(int i = index; i < _size; ++i)
					{
						tmp[i + 1] = _vector[i];
					}
					delete[] _vector;
					_vector = tmp;
					tmp = nullptr;
					_capacity = newCapacity;
					_size++;
					status = true;
				}
				else
				{
					for(int i = (_size - 1); i >= index; --i)
					{
						_vector[i + 1] = _vector[i];
					}
					_vector[index] = newElement;
					_size++;
					status = true;
				}
		}
		return status;
	}

	template <typename T>
	Vector<T>::Iterator::Iterator(T&&) : _


} // namespace my


#endif // __VECTOR_HPP__
