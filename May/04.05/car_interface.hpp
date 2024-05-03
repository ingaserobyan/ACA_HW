#ifndef __CAR_INTERFACE__
#define __CAR_INTERFACE__

class Car
{
	public:
		Car() {};
		virtual ~Car() {};

	public:
		virtual bool	drive() = 0;
		virtual bool	stop() = 0;

		virtual float	fuelLevel() = 0;
		virtual bool	addFuel() = 0;

		virtual float	currentSpeed() = 0;
		virtual bool	speedUp(float) = 0;
		virtual bool	speedDown(float) = 0;

		virtual bool	lights(bool) = 0;
		virtual bool	controlWipers(bool) = 0;
};

#endif // __CAR_INTERFACE__
