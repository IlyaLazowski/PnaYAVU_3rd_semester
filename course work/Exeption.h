//Exeption.h
#pragma once
#include <iostream>
using namespace std;
class Exeption
{
protected:
	string message;
public:
	Exeption(string message);
	~Exeption();
	virtual string What() const;
};
