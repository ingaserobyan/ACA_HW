#include "node.hpp"

template<typename T>
Node<T>::Node(T&& data) : _data(std::forward(data)), _next(nullptr) {}

template<typename T>
Node<T>::Node(const Node& oldNode) : _data(oldNode._data), _next(oldNode.next) {}

template<typename T>
Node<T>::Node(Node&& oldNode) : _data(oldNode._data), _next(oldNode.next)
{
	oldNode._next = nullptr;
}

template<typename T>
Node<T>&	Node<T>::operator= (const Node& oldNode)
{
	if (this != &oldNode)
	{
        _data = oldNode._data;
        _next = oldNode._next;
    }
    return *this;
}

template<typename T>
Node<T>& Node<T>::operator= (Node&& oldNode)
{
    if (this != &oldNode) {
        _data = std::move(oldNode._data);
        _next = oldNode._next;
        oldNode._next = nullptr;
    }
    return *this;
}

template<typename T>
void Node<T>::next (Node* ptrToNext)
{
	
}
