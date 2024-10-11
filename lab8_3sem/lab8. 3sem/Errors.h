#pragma once
#include "InputError.h"
#include "Error_file.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstring>
#include <locale.h>  
#include <limits>
#include <cctype>
#include<fstream>
//#include"fname.h"
using namespace std;

template <typename T>
T enter_num(istream& in)
{
	bool flag = false;
	T value{};
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
int compareBirthDates(const char* date1, const char* date2);
int LenghtOfStrlen(char str[]);
bool IsAllSpace(const char* str);
void CreateName(char* surname, string output);
int  CreateInt(int min, int max);
bool IsValidDate(const char* date);
void CreateDate(char* date);
bool WithCounterIsAllSpace(const char* str);
bool IsInvalidCharacters(const char* str);
bool IsNumberCrunching(const char* str);
void ExaminationLine(char* surname, std::string output);
bool ParametrForSearch(bool& flag1, bool& flag2);
template<typename T>
int ComparisonByParameter(bool search_bu_surname, bool search_bu_data_of_birdth, T& obj, char surname[], char data_of_birdth[])
{
	if (search_bu_data_of_birdth == true && search_bu_surname == true)
	{
		if (strcmp(obj.GetSurname(), surname) == 0 && strcmp(obj.GetDataOfBirdth(), data_of_birdth) == 0)
			return 0; // или любое другое значение, которое вы хотите вернуть, если обе строки равны
		else
			return 1;
	}
	if (search_bu_data_of_birdth == false && search_bu_surname == true)return strcmp(obj.GetSurname(), surname);
	if (search_bu_data_of_birdth == true && search_bu_surname == false)return strcmp(obj.GetDataOfBirdth(), data_of_birdth);
	return 1;
}
bool OpeningFile(string filename);

