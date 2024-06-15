#include "node.hpp"
#include "singleList.hpp"

int main()
{
	my::Node<int> a(9);

	my::singleList<int> myList1(a);
	myList1.push_front(5);
	myList1.push_front(5);
	myList1.insert(4, 1);
	myList1.insert(a, 2);
	myList1.display();

	// std::cout << "Last: ";
	// my::Node<int>* b = myList1.findLastN(5);
	// b->display();

	myList1.reverse();
	myList1.display();

	if(myList1.isCyclic())
		std::cout << "List is cyclic" << std::endl;
	else
		std::cout << "List is NOT cyclic" << std::endl;
	return 0;
}