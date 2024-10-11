#include "Zaim.h"

Zaim::Zaim()
{
	this->date[0] = '\0';
}

Zaim::Zaim(const Zaim& other):Schet(other)
{
	strcpy_s(this->type, 10, other.type);
	strcpy_s(this->date, 11, other.date);
}

Zaim::Zaim(char type[], char account_number[], double interest_rate, double sum, char date[]) :Schet(type, account_number, interest_rate, sum)
{
	strcpy_s(this->date, 11, date);
}

Zaim::~Zaim(){}

void Zaim::SetDate(char date[])
{
	strcpy_s(this->date, 11, date);
}

char* Zaim::GetDate()
{
	return this->date;
}

void Zaim::Cap() const
{
	std::string line(75, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(10) << "NUMBER"
		<< std::setw(10) << "TYPE"
		<< std::setw(21) << "CHECK"
		<< std::setw(9) << "PROCENT"
		<< std::setw(11) << "SUM"
		<< std::setw(14) << "DATA"
		<< std::endl;
	std::cout << line << std::endl;
}

void Zaim::Output(int i)
{
	cout << setiosflags(ios::left)
		<< std::setw(10) << i
		<< setw(10) << "ZAIM"
		<< setw(21) << this->account_number
		<< setw(9) << this->interest_rate
		<< setw(11) << this->sum
		<< setw(14) << this->date;
}

Zaim* Zaim::clone() const
{
	return new Zaim(*this);
}

void Zaim::ChangingServiceFields()
{
	int choise;
	do
	{
		cout << "Что вы хотите изменить\n";
		cout << "1. Процентную ставку\n";
		cout << "2. Минимальную сумму займа\n";
		cout << "3. Дату конечного погашения\n";
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
			cout << "Введите новую сумму займа: ";
			this->sum = CreateDouble(10000, 100000);
			
		}
		break;
		case 3:
		{
			cout << "Введите новую дату конечного погашения: ";
			CreateDate(this->date);
		}
		break;
		}
	} while (choise != 4);
}

Zaim& Zaim::operator=(const Zaim& other)
{
	Schet::operator=(other);
	strcpy_s(this->date, 11, other.date);
	return *this;
}

bool Zaim::operator==(Zaim& other)
{
	if (other.interest_rate != 0)
		if (this->interest_rate != other.interest_rate)
			return false;
	if (other.sum != 0)
		if (this->sum != other.sum)
			return false;
	if (other.date[0] != '\0')
		if (strcmp(this->date,other.date)!=0)
			return false;
	return true;
}

ofstream& operator<<(std::ofstream& ofs, Zaim& obj)
{
	ofs << "ZAIM" << '!' << obj.account_number << '!' << obj.interest_rate << '!' << obj.sum << '!' << obj.date << '!' << '\n';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, Zaim& obj)
{
	char str[32];
	int i = 1;
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
	ifs.getline(str, 11, '!');
	obj.SetDate(str);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Zaim& obj)
{
	cout << setiosflags(ios::left)
		<< setw(10) << "ZAIM"
		<< setw(21) << obj.account_number
		<< setw(9) << obj.interest_rate
		<< setw(11) << obj.sum
		<< setw(15) << "-"
		<< setw(14) << obj.date;
	return os;
}

istream& operator>>(std::istream& in, Zaim& obj)
{
	strcpy_s(obj.type, 10, "Zaim");
	cout << "Введите желаемую процентную ставку(6-10): ";
	obj.interest_rate = CreateDouble(6.0, 10.0);
	strcpy_s(obj.account_number, 20, "SCHET NUMBER");
	cout << "Введите желаемую сумму займа(20000-100000): ";
	obj.sum = CreateDouble(20000.0, 100000.0);
	CreateDate(obj.date);
	return in;
}
