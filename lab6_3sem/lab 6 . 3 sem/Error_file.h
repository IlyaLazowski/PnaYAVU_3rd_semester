#pragma once
#include "Exeption.h"

class FileError :public Exeption
{
public:
	FileError(string message);
	~FileError();
	string What() const override;
};

