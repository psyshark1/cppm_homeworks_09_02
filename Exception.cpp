#include"Exception.h"

const char* NullArg::what() const
{
	return message;
}

NullArg::NullArg(const char* msg) : std::invalid_argument(msg)
{
	this->message = msg;
}

NullArg::~NullArg()
{
}