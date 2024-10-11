#include "InputError.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstring>
#include <locale.h>  
#include <limits>
#include <cctype>
#include <cstring>
#include<locale.h>
using namespace std;

int compareBirthDates(const char* date1, const char* date2);
bool IsAllSpace(const char* str);
void CreateName(char* surname, string output);
int  CreateInt(int min, int max);
bool IsValidDate(const char* date);
void CreateDate(char* date);
bool WithCounterIsAllSpace(const char* str);
bool IsInvalidCharacters(const char* str);
bool IsNumberCrunching(const char* str);
void ExaminationLine(char* surname, std::string output);

