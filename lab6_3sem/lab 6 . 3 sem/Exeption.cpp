#include "Exeption.h"

Exeption::Exeption(string message)
{
	this->message = message;
}

Exeption::~Exeption() {}

string Exeption::What() const
{
	return this->message;
}