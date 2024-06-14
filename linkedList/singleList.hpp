#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#include "node.hpp"

namespace my
{
	template <typename T>
	class singleList
	{
		public:
			singleList();
			singleList(T&&);
			singleList(Node<T>&);

		public:
			void	push_front(const Node<T>&);
			void	push_front(T&&);
			void	pop_front();

		public:
			void	display();

		private:
			Node<T>*	_head = nullptr;
	};

	template<typename T>
	singleList<T>::singleList() {}

	template<typename T>
	singleList<T>::singleList(T&& data) : _head(new Node<T>(std::move(data))) {}

	template<typename T>
	singleList<T>::singleList(Node<T>& myNode) : _head(new Node<T>(myNode)) {}

	template<typename T>
	void	singleList<T>::push_front(const Node<T>& element)
	{
		Node<T>* tmp = _head;
		_head = new Node<T>(element);
		_head->_next = tmp;
	}

	template<typename T>
	void	singleList<T>::push_front(T&& data)
	{
		Node<T>* tmp = _head;
		_head = new Node<T>(std::move(data));
		_head->_next = tmp;
	}

	template<typename T>
	void	singleList<T>::pop_front()
	{
		if (_head)
		{
			Node<T>* tmp = _head;
			_head = _head->next;
			delete tmp;
		}
	}

	template<typename T>
	void	singleList<T>::display()
	{
		Node<T>* tmp = _head;
		while(tmp)
		{
			tmp->display();
			tmp = tmp->_next;
		}
	}
}

#endif // __SINGLE_LIST_H__
