#include <iostream>



class f
{
	public:
	int c = 0;
		int getCount () {return c;}
	int operator() ()
	{
		return c++;
	}
};

std::ostream& operator<< (std::ostream& os, cosnt f& obj)
{
	os << obj.getCount();
	return os;
}

int main()
{
	std::cout << f() << std::endl;
	std::cout << f()() << std::endl;
	std::cout << f()()() << std::endl;
}
