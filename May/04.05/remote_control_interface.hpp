#ifndef __REMOTE_CONTROL_INTERFACE__
#define __REMOTE_CONTROL_INTERFACE__

class I_RemoteControl
{
	public:
		I_RemoteControl() {};
		virtual ~I_RemoteControl() {};

	public:
		virtual bool turnOn() = 0;
		virtual bool turnOff() = 0;

		virtual	bool Settings() = 0;

		virtual bool up(int) = 0; // for TV up the volume, for Air conditioner up the temperature ...
		virtual bool down(int) = 0;
};

#endif // __REMOTE_CONTROL_INTERFACE__
