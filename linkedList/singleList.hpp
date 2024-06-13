#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

namespace my
{
	template <typename T>
	class singleList
	{
		public:
			singleList();
			singleList(const T&);


		public:
			void	add_front(const Node<T>&);
			void	pop_front();

		private:
			Node*	_head = nullptr;
	};
}

#endif // __SINGLE_LIST_H__
