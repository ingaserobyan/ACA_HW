#include "node.hpp"
#include "singleList.hpp"

int main()
{
	my::Node<int> a(9);
	a.display();

	my::singleList<int> myList(7);
	my::singleList<int> myList1(a);
	myList.display();
	myList1.push_front(5);
	myList1.display();
}