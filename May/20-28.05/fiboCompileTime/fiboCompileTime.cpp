#include <iostream>

template<unsigned int T>
class Fibonacci
{
	public:
		static const unsigned int val = (Fibonacci<T - 1>::val) + (Fibonacci<T - 2>::val);
};

template<>
class Fibonacci<1>
{
	public:
		static const int val = 1;
};


template<>
class Fibonacci<0>
{
	public:
		static const int val = 0;
};

int main()
{

	std::cout << Fibonacci<0>::val << ", ";
	std::cout << Fibonacci<1>::val << ", ";
	std::cout << Fibonacci<2>::val << ", ";
	std::cout << Fibonacci<3>::val << ", ";
	std::cout << Fibonacci<4>::val << ", ";
	std::cout << Fibonacci<5>::val << ", ";
	std::cout << Fibonacci<6>::val << ", ";
	std::cout << Fibonacci<7>::val << std::endl;

	return 0;
}
