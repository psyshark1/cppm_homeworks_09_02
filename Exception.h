#pragma once
#include<stdexcept>

class NullArg : public std::invalid_argument
{
public:
	NullArg(const char* msg);
	~NullArg();
	const char* what() const override;
private:
	const char* message;
};
