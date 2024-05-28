#include "data.hpp"

data::data(int i) :
	type(DataType::INTEGER),
	u_i(i) {}

data::data(float f) :
	type(DataType::FLOAT),
	u_f(f) {}

data::data(const std::string &s) :
	type(DataType::STRING),
	u_s(new std::string(s)){}

data::data(const data& old) : type(old.type)
{
	switch (old.type)
	{
		case DataType::INTEGER:
			u_i = old.u_i;
			break;
		case DataType::FLOAT:
			u_f = old.u_f;
			break;
		case DataType::STRING:
			u_s = new std::string(*(old.u_s));
			break;
	}
}

data::data(data&& old)  : type(old.type)
{
    switch (old.type)
	{
        case DataType::INTEGER:
		{
            u_i = old.u_i;
			old.u_i = 0;
            break;
		}
        case DataType::FLOAT:
		{
            u_f = old.u_f;
			old.u_f = 0;
            break;
		}
        case DataType::STRING:
		{
            u_s = old.u_s;
            old.u_s = nullptr;
		}
    }
}

data::~data()
{
	if (type == DataType::STRING && u_s != nullptr)
		delete u_s;
}

data& data::operator=(const data& old)
{
	if (this == &old) return *this;

	if (type == DataType::STRING)
		delete u_s;

	type = old.type;
	switch (old.type)
	{
		case DataType::INTEGER:
			u_i = old.u_i;
			break;
		case DataType::FLOAT:
			u_f = old.u_f;
			break;
		case DataType::STRING:
			u_s = new std::string(*(old.u_s));
			break;
	}
	return *this;
}


data& data::operator=(data&& old)
{
	if (this == &old) return *this;

	if (type == DataType::STRING)
	{
		delete u_s;
	}

	type = old.type;
	switch (old.type)
	{
		case DataType::INTEGER:
			u_i = old.u_i;
			break;
		case DataType::FLOAT:
			u_f = old.u_f;
			break;
		case DataType::STRING:
			u_s = old.u_s;
			old.u_s = nullptr;
			break;
	}
	return *this;
}
