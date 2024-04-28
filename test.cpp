#include <iostream>

class A
{
	public:
		A() : x(5) {}

	public:
		virtual void foo()
		{
			std::cout << "Class A " << this->x << std::endl;
		}
	private:
		int x;
};

class B : public A
{
	public:
		B() : x(6) {}
	public:
		void foo()
		{
			std::cout << "Class B " << this->x << std::endl;
		}

	private:
		int x;
};

int main()
{
	A ob;
	B obj;

	ob.foo();
	obj.foo();

	std::cout << std::endl;

	A* ptr1 = new B();
	ptr1->foo();


	delete ptr1;



	return (0);
}