#ifndef __VECTOR_H__
#define __VECTOR_H__

namespace	my
{
	template<typename T>
	class vector
	{
		public:
			vector(const unsigned int&);
			vector(const vector&);
			vector(vector&&);
			~vector();

		public:
			vector& operator= (const vector&);
			vector& operator= (vector&&);

		public:
			void	push_back(const T&);

		public:
			T&	operator[](const int&);

		private:
			int	_size;
			int	_capacity;
			T*	_vector = nullptr;
	};
}

#endif // __VECTOR_H__
