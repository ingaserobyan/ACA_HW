#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <utility>

template <typename T>
class Node
{
public:
	Node(T&&);
	Node(const Node&);
	Node(Node&&);
	~Node() = default;

	Node&	operator= (const Node&);
	Node&	operator= (Node&&);

	void	next(Node*);

	T	_data;
	Node*	_next;
};




#endif // __NODE_HPP__


