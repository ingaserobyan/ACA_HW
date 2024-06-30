#include "vector.hpp"

bool is_prime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; (i * i) <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	my::Vector<int> a;
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.display();
	for(my::Vector<int>::Iterator itr = a.begin(); itr != a.end(); ++itr)
	{
		if (is_prime(*itr))
			a.pop(itr);
	}
	a.display();

	return 0;
}
