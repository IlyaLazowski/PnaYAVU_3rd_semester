#include "Errors.h"

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
                if ((surname[i] >= '�' && surname[i] <= '�') || (surname[i] >= '�' && surname[i] <= '�'))
                    throw std::invalid_argument("������ �������� ������� �����");
            if (IsAllSpace(surname)) throw std::invalid_argument("������� �� ����� ���� ������ ��� �������� ������ �� ��������");
            if (strlen(surname) < 3) throw std::invalid_argument("������� ������ �������� ������� �� ���� ��������");
            if (!std::isupper(surname[0])) throw std::invalid_argument("������� ������ ���������� � ��������� �����");
            for (int i = 1; i < strlen(surname); ++i)
                if (!std::islower(surname[i])) throw std::invalid_argument("��� ������� �������, ����� �������, ������ ���� ���������");
            for (int i = 0; i < strlen(surname); ++i)
                if (!std::isalpha(surname[i])) throw std::invalid_argument("������� ������ �������� ������ �� ����");
            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
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
            for (int i = 0; i < strlen(surname); ++i)
                if ((surname[i] >= '�' && surname[i] <= '�') || (surname[i] >= '�' && surname[i] <= '�'))
                    throw std::invalid_argument("������ �������� ������� �����");
            if (!IsNumberCrunching(surname)) throw std::invalid_argument("������� ����� ���� � ������");
            if (!IsInvalidCharacters(surname)) throw std::invalid_argument("������ ����������� ������");
            if (!WithCounterIsAllSpace(surname)) throw std::invalid_argument("������� ����� ��������");
            if (strlen(surname) < 3) throw std::invalid_argument("������ ������� ��������");

            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
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
                else if (!std::isdigit(c)) throw std::invalid_argument("������� �� �����");
            }
            value = std::stoi(input);
            if (value < min || value > max) throw std::out_of_range("����� ��� ���������");
            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
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
            cout << "������� �������� ���� ��������� ��/��/����: ";
            cin.getline(date, 80);
            if (!IsValidDate(date)) throw invalid_argument("������� ������������ ����");
            break;
        }
        catch (const exception& e)
        {
            cout << "������: " << e.what() << ". ���������� ��� ���.\n";
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
    if (year < 2024||year>2027) return false;
    return true;
}

bool hasMoreThanTwoDigits(const std::string& str)
{
    size_t dotPos = str.find('.');
    return (dotPos != std::string::npos) && (str.length() - dotPos - 1 > 2);
}

double CreateDouble(double min, double max)
{
    setlocale(LC_ALL, "RUS");
    double value;
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
                else if (!std::isdigit(c) && c != '.' && c != ',') throw std::invalid_argument("������� �� �����");
            }

            // �������� ',' �� '.', ���� ����
            size_t dotPos = input.find(',');
            if (dotPos != std::string::npos)
            {
                input[dotPos] = '.';
            }
            if (hasMoreThanTwoDigits(input)) throw std::invalid_argument("����� �������� ����� ���� ������ ����� �������");
            std::stringstream ss(input);
            ss >> value;
            if (value < min || value > max) throw std::out_of_range("����� ��� ���������");
            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
        }
    }
    return value;
}

char* GenerateCountingServices(string fname)
{
    char* str = new char[20]; // ������������ ��������� ������ ��� ������� char
    ifstream ifs(fname, ifstream::in);
    if (!ifs)
    {
        cout << "�� ������� ������� ����: " << "Human.txt";
        system("pause");
    }
    ifs.getline(str, 20, '!');
    incrementNumber(str);
    ifs.close();

    std::ofstream ofs(fname);
    ofs << str << '!';
    ofs.close();

    return str; // ������� ��������� �� ����������� ���������� ������
}

void incrementNumber(char* str)
{
    string result = str;
    result.erase(remove(result.begin(), result.end(), ' '), result.end());
    long long bigNumber = stoll(result);
    bigNumber++;
    result = to_string(bigNumber);
    string formattedNumber;
    for (int i = 0; i < result.length(); i++) 
    {
        if (i > 0 && (i % 4) == 0) 
        {
            formattedNumber += " ";
        }
        formattedNumber += result[i];
    }
    strcpy_s(str, 20, formattedNumber.c_str());
}

void SkipSpaces(ifstream& ifs)
{
    char c;
    for (int i=0;i<80;i++)
    {
        ifs.get(c);
    }
}

void WriteSpaces(ofstream& ofs)
{
    for (int i = 0; i < 80; i++) {
        ofs << " ";
    }
}


void CheckPassport(char* passport)
{
    string regionu[10] = { "AB","BM" ,"HB", "KH" , "MP" ,"MC","KB" ,"PP" ,"SP","DP" };
    //��� �������	                ������

    //    ��	                        ��������� �������
    //    ��	                        ��������� �������
    //    ��	                        ���������� �������
    //    ��	                        ����������� �������
    //    ��	                        ����� �����
    //    ��	                        ������� �������
    //    ��	                        ���������� �������
    //    ��	                        ��������, �������� ������������� ����������� ���(� ����� ���������� �� �������)
    //    SP	                        ��������� ������� ���������� ���������� ��������
    //    DP	                        ��������������� ������� ���������� ���������� ��������
    while (true)
    {
        try
        {
            bool flag = false;
            cout << "������� �������: ";
            std::cin.getline(passport, 10);
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ����� �����
                throw std::invalid_argument("�������� ����� ������ ��������");
            }
            std::string region_code(passport, 2);
            if (strlen(passport) != 9) throw std::invalid_argument("�������� ����� ������ ��������");

            for (int i = 0; i < 10; i++)
            {
                if (region_code == regionu[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag) throw std::invalid_argument("�������� ��� �������");
            for (int i = 2; i < strlen(passport); ++i)
            {
                if (!isdigit(passport[i])) throw std::invalid_argument("��� ������� ����� ���� ������� ������ ���� �������");
            }
            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
        }
    }
}

void CheckTelefon(char* telefon)
{
    //+ 375 24 xxx xx xx � ����������(��������)
    //+ 375 25 xxx xx xx � life : )
    //+ 375 29 1xx xx xx � �1
    //+ 375 29 2xx xx xx � ���
    //+ 375 29 3xx xx xx � �1
    //+ 375 29 5xx xx xx � ���
    //+ 375 29 6xx xx xx � �1
    //+ 375 29 7xx xx xx � ���
    //+ 375 29 8xx xx xx � ���
    //+ 375 29 9xx xx xx � �1
    //+ 375 33 xxx xx xx � ���
    //+ 375 44 xxx xx xx � �1
    while (true)
    {
        try
        {
            bool flag = false;
            cout << "������� ����� �������� ��� (+375): ";
            std::cin.getline(telefon, 10);
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ����� �����
                throw std::invalid_argument("�������� ����� ������ ��������");
            }
            if (strlen(telefon) != 9) throw std::invalid_argument("�������� ����� ������ ��������");
            for (int i = 0; i < strlen(telefon); ++i)
                if (!isdigit(telefon[i])) throw std::invalid_argument("����� �������� ������ �������� ������ �� ����");
            int code = stoi(string(telefon).substr(0, 2));
            if (code != 24 && code != 25 && code != 29 && code != 33 && code != 44) throw std::invalid_argument("��c������������ ��� ���������");

            break;
        }
        catch (const std::exception& e)
        {
            std::cout << "������: " << e.what() << ". ���������� ��� ���.\n";
        }
    }
}