#include <iostream>

template<typename T1, typename T2>
struct my_pair
{
	T1	element1;
	T2	element2;
};

template<typename T1, typename T2>
my_pair<T1, T2> my_make_pair(T1 e_1, T2 e_2)
{
	my_pair<T1, T2> pair;
	pair.element1 = e_1;
	pair.element2 = e_2;
	return pair;
}

int	main()
{
	my_pair<int, const char*> pair = my_make_pair(1, "One");
	std::cout << "element 1 = " << pair.element1 << " element 2 = " << pair.element2 << std::endl;
	return 0;
}
