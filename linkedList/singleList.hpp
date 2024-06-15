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
			void	insert(T&&, const int&);
			void	insert(Node<T>&, const int&);

		public:
			Node<T>*	findLastN(T&&);
			void	reverse();
			bool	isCyclic();
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
			_head = _head->_next;
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

	template<typename T>
	void	singleList<T>::insert(T&& data, const int& position)
	{
		if(position <= 0)
		{
			this->push_front(std::move(data));
			return ;
		}

		Node<T>* tmp = _head;
		int	i = 0;

		while(i < (position - 1) && tmp)
		{
			++i;
			tmp = tmp->_next;
		}
		if(!tmp)
			return ;
		tmp->_next = new Node<T>(std::move(data), tmp->_next);
	}


	template<typename T>
	void	singleList<T>::insert(Node<T>& node, const int& position)
	{
		if(position <= 0)
		{
			this->push_front(node);
			return ;
		}

		Node<T>* tmp = _head;
		int	i = 0;

		while(i < (position - 1) && tmp)
		{
			++i;
			tmp = tmp->_next;
		}
		if(!tmp)
			return ;
		Node<T>* holder = tmp->_next;
		tmp->_next = new Node<T>(node);
		tmp->_next->_next = holder;
	}

	template<typename T>
	Node<T>*	singleList<T>::findLastN(T&& value)
	{
		Node<T>*	counter = _head;
		Node<T>*	element = NULL;
		while(counter)
		{
			if(counter->_data == value)
				element = counter;
			counter = counter->_next;
		}
		return element;
	}

	template<typename T>
	void	singleList<T>::reverse()
	{
		Node<T>*	current = _head;
		Node<T>*	next = nullptr;
		Node<T>*	previous = nullptr;

		while(current)
		{
			next = current->_next;
			current->_next = previous;
			previous = current;
			current = next;
		}
		_head = previous;
	}

	template<typename T>
	bool	singleList<T>::isCyclic()
	{
		bool	status = false;
		Node<T>*	counter = _head;

		while(counter && (counter != _head))
		{
			if(counter->_next == _head)
				status = true;
			counter = counter->_next;
		}
		return status;
	}
}

#endif // __SINGLE_LIST_H__
