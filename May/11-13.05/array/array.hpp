#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

class Array
{
	public:
		Array(const int);
		Array(const Array&);
		~Array();

	public:
		int size() const;

	public:
		Array& operator= (const Array&);
		int& operator[](int) const;
		int& operator[](int);

	public:
		friend std::ostream& operator<< (std::ostream& os, const Array&);

	private:
		int _size;
		int* _array;
};

#endif // __ARRAY_HPP__
