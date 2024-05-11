#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

class Array
{
	public:
		Array(const int);
		Array(const Array&);
		~Array();

	public:
		Array& operator= (const Array&);
		int& operator[](int) const;

	private:
		int _size;
		int* _array;
};

#endif // __ARRAY_HPP__
