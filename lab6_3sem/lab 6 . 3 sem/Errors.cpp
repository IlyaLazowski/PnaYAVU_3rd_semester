#include "Errors.h"

int compareBirthDates(const char* date1, const char* date2)
{
    int day1, month1, year1, day2, month2, year2;
    sscanf_s(date1, "%d/%d/%d", &day1, &month1, &year1);
    sscanf_s(date2, "%d/%d/%d", &day2, &month2, &year2);
    if (year1 > year2) return 1;
    else if (year1 < year2) return -1;
    else
    {
        if (month1 > month2) return 1;
        else if (month1 < month2) return -1;
        else
        {
            if (day1 > day2) return 1;
            else if (day1 < day2) return -1;
            else return 0;
        }
    }
}

int LenghtOfStrlen(char str[])
{
    int i;
    for (i = 0; str[i] != 0; i++);
    return i;
}

bool IsAllSpace(const char* str)
{
    for (int i = 0; i < strlen(str); ++i)
        if (!isspace(str[i])) return false;
    return true;
}

void CreateName(char* surname, string output)
{
    while (true)
    {
        try
        {
            std::cout << output;
            std::cin.getline(surname, 32);
            for (int i = 0; i < strlen(surname); ++i)
                if ((surname[i] >= 'А' && surname[i] <= 'Я') || (surname[i] >= 'а' && surname[i] <= 'я'))
                    throw InputError("Строка содержит русские буквы");
            if (IsAllSpace(surname)) throw InputError("Не может быть пустой или состоять только из пробелов");
            if (strlen(surname) < 3) throw InputError("Должна(о) состоять минимум из трех символов");
            if (!std::isupper(surname[0])) throw InputError("Должна(о) начинаться с заглавной буквы");
            for (int i = 1; i < strlen(surname); ++i)
                if (!std::islower(surname[i])) throw InputError("Все символы , кроме первого, должны быть строчными");
            for (int i = 0; i < strlen(surname); ++i)
                if (!std::isalpha(surname[i])) throw InputError("Должна(о) состоять только из букв");
            break;
        }
        catch (const InputError& e)
        {
            std::cout << "Ошибка! Исключение ввода: " << e.What() << ". Попробуйте еще раз.\n";
        }
    }
}

void ExaminationLine(char* surname, std::string output)
{
    while (true)
    {
        try
        {
            std::cout << output;
            std::cin.getline(surname, 32);
            if (!IsNumberCrunching(surname)) throw InputError("Слишком много цифр в строке");
            if (!IsInvalidCharacters(surname)) throw InputError("Введен запрещенный символ");
            if (!WithCounterIsAllSpace(surname)) throw InputError("Слишком много пробелов");
            if (strlen(surname) < 3) throw InputError("Строка слишком короткая");
            break;
        }
        catch (const InputError& e)
        {
            std::cout << "Ошибка! Исключение ввода: " << e.What() << ". Попробуйте еще раз.\n";
        }
    }
}

bool IsNumberCrunching(const char* str)
{
    int counter = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            counter++;
            if (counter >= 5) return false;
        }
    }
    return true;
}

int CreateInt(int min, int max)
{
    setlocale(LC_ALL, "RUS");
    int value;
    std::string input;
    while (true)
    {
        try
        {
            std::getline(std::cin, input);
            bool isNegative = false;
            for (char const& c : input)
            {
                if (c == '-' && !isNegative) isNegative = true;
                else if (!std::isdigit(c)) throw InputError("Введено не число");
            }
            value = std::stoi(input);
            if (value < min || value > max) throw InputError("Число вне диапазона");
            break;
        }
        catch (const InputError& e)
        {
            std::cout << "Ошибка! Исключение ввода: " << e.What() << ". Попробуйте еще раз.\n";
        }
    }
    return value;
}

void CreateDate(char* date)
{
    while (true)
    {
        try
        {
            cout << "Введите дату рождения в формате ДД/ММ/ГГГГ: ";
            cin.getline(date, 80);
            if (!IsValidDate(date)) throw InputError("Введена некорректная дата");
            break;
        }
        catch (const InputError& e)
        {
            cout << "Ошибка! Исключение ввода: " << e.What() << ". Попробуйте еще раз.\n";
        }
    }
}

bool WithCounterIsAllSpace(const char* str)
{
    int counter = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == ' ')
        {
            counter++;
            if (counter >= 2) return false;
        }
    }
    return true;
}

bool IsInvalidCharacters(const char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 33 && str[i] <= 44) || str[i] == 46 || str[i] == 47 || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96)
            || (str[i] >= 123 && str[i] <= 126)) return false;
    }
    return true;
}

bool IsValidDate(const char* date)
{
    if (strlen(date) != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;
    int day = stoi(string(date).substr(0, 2));
    int month = stoi(string(date).substr(3, 2));
    int year = stoi(string(date).substr(6, 4));
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) return false;
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeapYear)) return false;
    }
    if (year > 2023 || year < 1900) return false;
    return true;
}

bool ParametrForSearch(bool& flag1, bool& flag2)
{
	int choise;
	cout << "По каким параметрам осуществлять поиск:(1-да,2-нет)\n";
	cout << "Фамилия:";
	choise = CreateInt(1, 2);
	if (choise == 1)flag1 = true;
	else flag1 = false;
	cout << "Дата рождения:";
	choise = CreateInt(1, 2);
	if (choise == 1)flag2 = true;
	else flag2 = false;
    if (flag1==false&&flag2==false) return true;
    else return false;
}

bool OpeningFile(string filename)
{
    fstream file;
    try {
        file.open(filename);

        if (!file) {
            throw FileError("Не удалось открыть файл");
        }
        file.close();
    }
    catch (const FileError& e) {
        std::cerr << "Произошла ошибка: " << e.What() << std::endl;
        return true;
    }
    return false;
}

