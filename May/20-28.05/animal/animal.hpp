#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	public:
		Animal(const int&);
		Animal(const Animal&);
		Animal(Animal&&);

		virtual ~Animal();

	public:
		virtual void voice() = 0;
		virtual	void info() = 0;

	public:
		int	getAge() const;
		void	setAge(const int&);
		bool	operator< (const Animal&) const;
		bool	operator> (const Animal&) const;
		bool	operator== (const Animal&) const;
		bool	operator>= (const Animal&) const;

	static int count;

	private:
		int	_age;
};

# endif //__ANIMAL_HPP__
