//Errors.h
#pragma once
#include "InputError.h"
#include <iostream>
#include<fstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <ctime>
#include <locale.h>  
#include <limits>
#include <cctype>
#include <cstring>
#include<locale.h>
#include <sstream>
#include <typeinfo>
#include <cstdlib> 
using namespace std;

void SkipSpaces(ifstream& ifs);
void WriteSpaces(ofstream& ofs);
void CheckPassport(char* passport);
void CheckTelefon(char* telefon);
char* GenerateCountingServices(string fname);
void incrementNumber(char* str);
bool hasMoreThanTwoDigits(const std::string& str);
double CreateDouble(double min, double max);
bool IsAllSpace(const char* str);
void CreateName(char* surname, string output);
int  CreateInt(int min, int max);
bool IsValidDate(const char* date);
void CreateDate(char* date);
bool WithCounterIsAllSpace(const char* str);
bool IsInvalidCharacters(const char* str);
bool IsNumberCrunching(const char* str);
void ExaminationLine(char* surname, std::string output);
template <typename T>
T enter_num(istream& in)
{
	bool flag = false;
	T value;
	do {
		try
		{
			in >> value;
			if (!in || (in.peek() != '\n'))
			{
				throw InputError("Некорректно введено число");
			}
			else 	return value;
		}
		catch (const InputError& e)
		{
			flag = true;
			in.clear();
			rewind(stdin);
			cout << "Ошибка при вводе данных!" << e.What() << "Попробуйте ещё раз: ";
		}
	} while (flag);
	return 0;
}
template <typename T>
T enter_num(istream& in, T flimit, T slimit)
{
	bool flag = false;
	T value;
	do {
		try
		{
			in >> value;
			if (!in || (in.peek() != '\n') || value < flimit || value > slimit)
			{
				throw InputError("Некорректно введено число!");
			}
			else 	return value;
		}
		catch (const InputError& e)
		{
			flag = true;
			in.clear();
			rewind(stdin);
			cout << "Ошибка при вводе данных: " << e.What() << " Попробуйте ещё раз: ";
		}
	} while (flag);
	return 0;
}
