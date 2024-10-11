//InputError.h
#pragma once
#include "Exeption.h"
class InputError :public Exeption
{
public:
	InputError(string message);
	~InputError();
	string What() const override;
};