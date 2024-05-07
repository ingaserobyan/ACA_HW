#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

//  Feed Conversion Ratio - FCR
// 	Specific Dynamic Action - SDA

class Animal
{
	public:
		Animal(const float&, const float&, const float&);
		virtual ~Animal();

	public:
		void eat(const float&);
		float getWeight() const;

	protected:
		float	_weight;
		float	_fcr;
		float	_sda;
};

#endif // __ANIMAL_HPP__
