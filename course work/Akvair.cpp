//Akvair.cpp
#include "Akvair.h"
Akvair::Akvair()
{
	this->model[0] = '\0';
}
Akvair::Akvair(const Akvair& other):Schet(other)
{
	strcpy_s(this->model, 16, other.model);
}
Akvair::Akvair(char type[], char account_number[], double interest_rate, double sum, char model[]) :Schet(type,account_number, interest_rate, sum)
{
	strcpy_s(this->type, 10, "Akvair");
	strcpy_s(this->model, 16, model);
}
Akvair::~Akvair(){}
void Akvair::SetModel(char model[])
{
	strcpy_s(this->model, 16, model);
}
char* Akvair::GetModel()
{
	return this->model;
}
void Akvair::Cap() const
{
	std::string line(75, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(10) << "NUMBER"
		<< std::setw(10) << "TYPE"
		<< std::setw(21) << "CHECK"
		<< std::setw(9) << "PROCENT"
		<< std::setw(11) << "SUM"
		<< std::setw(16) << "MODEL"
		<< std::endl;
	std::cout << line << std::endl;
}
void Akvair::Output(int i)
{
	cout << setiosflags(ios::left)
		<< std::setw(10) << i
		<< setw(10) << "AKVAIR"
		<< setw(21) << this->account_number
		<< setw(9) << this->interest_rate
		<< setw(11) << this->sum
		<< setw(14) << this->model;
}
Akvair* Akvair::clone() const   //метод клонирования чтобы занести в вектор
{
	return new Akvair(*this);
}
void Akvair::ChangingServiceFields() // метод изменения полей объекта на выбор
{
	int choise;
	do
	{
		cout << "Что вы хотите изменить\n";
		cout << "1. Процентную ставку\n";
		cout << "2. Цену эквайринга\n";
		cout << "3. Модель\n";
		cout << "4. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 4);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "Введите новую процентную ставку: ";
			this->interest_rate = CreateDouble(0.1, 20);
		}
		break;
		case 2:
		{
			cout << "Введите новую цену эквайринга: ";
			this->sum = CreateDouble(10000, 100000);

		}
		break;
		case 3:
		{
			ExaminationLine(this->model, "Введите новую модель эквайринга: ");
		}
		break;
		}
	} while (choise != 4);
}
Akvair& Akvair::operator=(const Akvair& other)
{
	Schet::operator=(other);
	strcpy_s(this->model, 16, other.model);
	return *this;
}
bool Akvair::operator==(Akvair& other)
{
	if (other.interest_rate != 0)
		if (this->interest_rate != other.interest_rate)
			return false;
	if (other.sum != 0)
		if (this->sum != other.sum)
			return false;
	if (other.model[0] != '\0')
		if (strcmp(this->model,other.model)!=0)
			return false;
	return true;
}
std::ofstream& operator<<(std::ofstream& ofs, Akvair& obj)
{
	ofs << "AKVAIR" << '!' << obj.account_number << '!' << obj.interest_rate << '!' << obj.sum << '!' << obj.model << '!' << '\n';
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Akvair& obj)
{
	char str[32];
	int  i = 1;
	double doubl_type;
	ifs.getline(str, 10, '!');
	obj.SetType(str);
	ifs.getline(str, 20, '!');
	obj.SetAccountNumber(str);
	ifs >> doubl_type;
	obj.SetInterestRate(doubl_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> doubl_type;
	obj.SetSum(doubl_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs.getline(str, 16, '!');
	obj.SetModel(str);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}
std::ostream& operator<<(std::ostream& os, const Akvair& obj)
{
	cout << setiosflags(ios::left)
		<< setw(10) << "AKVAIR"
		<< setw(21) << obj.account_number
		<< setw(9) << obj.interest_rate
		<< setw(11) << obj.sum
		<< setw(15) << obj.model
		<< setw(14) << '-';
	return os;
}
istream& operator>>(std::istream& in, Akvair& obj)
{
	strcpy_s(obj.type, 10, "Akvair");
	cout << "Введите желаемую процентную ставку(1-3): ";
	obj.interest_rate = CreateDouble(1.0, 3);
	strcpy_s(obj.account_number, 20, "SCHET NUMBER");
	cout << "Введите желаемую цену(350-800): ";
	obj.sum = CreateDouble(350.0, 800.0);
	ExaminationLine(obj.model, "Введите модель эквайринга: ");
	return in;
}
