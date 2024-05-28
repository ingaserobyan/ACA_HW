#ifndef __DATA_H__
#define __DATA_H__

#include <string>

struct	data
{
	enum	DataType {INTEGER, FLOAT, STRING};
	DataType	type;

	union
	{
		int	u_i;
		float	u_f;
		std::string*	u_s;
	};

	data(int);
	data(float);
	data(const std::string &s);

	data(const data&);
	data(data&&);

	~data();

	data&	operator=(const data&);
	data&	operator=(data&&);
};

#endif //__DATA_H__
