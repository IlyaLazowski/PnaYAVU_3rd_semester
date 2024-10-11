#include "InputError.h"
#include "Exeption.h"
InputError::InputError(string message) :Exeption(message) {}

string InputError::What() const
{
	return Exeption::What();
}

InputError::~InputError() {}
