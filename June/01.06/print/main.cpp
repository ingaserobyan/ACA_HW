#include <iostream>

#include "array.hpp"

void Print() {}

template<typename T, typename ... Args>
void Print(T&& firstArg, Args&& ... args)
{
    std::cout << std::forward<T>(firstArg);
    if (sizeof...(args) > 0)
	{
        Print(std::forward<Args>(args)...);
    }
}

std::ostream& operator<< (std::ostream& os, const Array& arr)
{
	for (int i = 0; i < arr._size; ++i)
	{
		os << arr[i];
		if (i < (arr._size - 1))
			os << ", ";
	}
	return os;
}

int main()
{
	Print("hi", " ", 1," ", 45.7);

	Array myArr(5);
	int size = myArr.size();

	for(int i = 0; i < size; ++i)
	{
		myArr[i] = i;
	}

	Print("\n");
	Print(myArr);
	return 0;
}
