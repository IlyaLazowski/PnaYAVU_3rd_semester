#include "Error_file.h"
#include "Exeption.h"
FileError::FileError(string message) :Exeption(message) {}

string FileError::What() const
{
	return Exeption::What();
}

FileError::~FileError() {}
