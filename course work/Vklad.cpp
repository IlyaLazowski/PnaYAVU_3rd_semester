#include "Vklad.h"

Vklad::Vklad()
{
	this->time = 0;
	this->permission = false;
}

Vklad::Vklad(const Vklad& other):Schet(other)
{
	strcpy_s(this->type, 10, other.type);
	this->time = other.time;
	this->permission = other.permission;
}

Vklad::Vklad(char type[], char account_number[], double interest_rate, double sum, int time, bool permission) :Schet(type, account_number, interest_rate, sum)
{
	strcpy_s(this->type, 10,"Vklad");
	this->permission = permission;
	this->time = time;
}

int Vklad::GetTime()
{
	return this->time;
}

void Vklad::Cap() const
{
	std::string line(75, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(10) << "NUMBER"
		<< std::setw(10) << "TYPE"
		<< std::setw(21) << "CHECK"
		<< std::setw(9) << "PROCENT"
		<< std::setw(11) << "SUM"
		<< std::setw(6) << "TIME"
		<< std::setw(8) << "REFILL"
		<< std::endl;
	std::cout << line << std::endl;
}

void Vklad::ChangingServiceFields() 
{
	int choise;
	do
	{
		cout << "Что вы хотите изменить\n";
		cout << "1. Процентную ставку\n";
		cout << "2. Минимальную сумму для открытия вклада\n";
		cout << "3. Время действия вклада\n";
		cout << "4. Возможность пополнения\n";
		cout << "5. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 5);
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
			cout << "Введите новую минимальную сумму для открытия вклада: ";
			this->sum = CreateDouble(1, 5000);
		}
		break;
		case 3:
		{
			cout << "Введите новое время которое будет действовать вклад: ";
			this->time = CreateInt(1,96);
		}
		break;
		case 4:
		{
			this->permission = !(this->permission);
		}
		break;
		}
	} while (choise != 5);
}

void Vklad::Output(int i) 
{
	cout << setiosflags(ios::left)
		<< std::setw(10) << i
		<< setw(10) << "VKLAD"
		<< setw(21) << this->account_number
		<< setw(9) << this->interest_rate
		<< setw(11) << this->sum
		<< setw(6) << this->time;
	if (this->permission) cout << setw(8) << "YES";
	else cout << setw(8) << "NOY";


}

void Vklad::SetTime(int time)
{
	this->time = time;
}

bool Vklad::GetPermission()
{
	return this->permission;
}

void Vklad::SetPermission(bool permission)
{
	this->permission = permission;
}

Vklad* Vklad::clone() const
{
	return new Vklad(*this);
}

Vklad::~Vklad(){}

Vklad& Vklad::operator=(const Vklad& other)
{
	Schet::operator=(other);
	this->time = other.time;
	this->permission = other.permission;
	return *this;
}

bool Vklad::operator==(const Vklad& other)
{
	if (other.interest_rate != 0)
		if (this->interest_rate != other.interest_rate)
			return false;
	if (other.sum != 0)
		if (this->sum != other.sum)
			return false;
	if (other.time != 0)
		if (this->time != other.time)
			return false;
	if (other.permission != 0)
		if (this->permission != other.permission)
			return false;
	return true;
}

istream& operator>>(std::istream& in, Vklad& obj)
{
	strcpy_s(obj.type, 10, "Vklad");
	cout << "Введите желаемую процентную ставку(2-10): ";
	obj.interest_rate = CreateDouble(2.0, 10.0);
	strcpy_s(obj.account_number, 20, "SCHET NUMBER");
	cout << "Введите желаемую сумму для начального зачисленияна вклад(200-20000): ";
	obj.sum = CreateDouble(200.0, 20000.0);
	cout << "Введите количество месяцев на которое вы хотите открыть вклад(3-24): ";
	obj.time = CreateInt(3, 24);
	cout << "Нажмите 1 , если хотет вклад с возможностью пополнение и 2 без: ";
	int choise = CreateInt(1, 2);
	switch (choise)
	{
	case 1:
	{
		obj.permission = true;
	}
		break;
	case 2:
	{
		obj.permission = false;
	}
	break;
	}
	return in;
}

std::ofstream& operator<<(std::ofstream& ofs, Vklad& obj)
{
	ofs << "VKLAD" << '!' << obj.account_number << '!' << obj.interest_rate << '!' << obj.sum << '!' << obj.time << '!' << obj.permission << '\n';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, Vklad& obj)
{
	char str[32];
	int in_type;
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
	ifs >> in_type;
	obj.SetTime(in_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> in_type;
	obj.SetPermission(in_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Vklad& obj)
{
	cout << setiosflags(ios::left)
		<< setw(10) << "VKLAD"
		<< setw(21) << obj.account_number
		<< setw(9) << obj.interest_rate
		<< setw(11) << obj.sum
		<< setw(6) << obj.time
		<< std::setw(14) << "-";
	if (obj.permission) cout << setw(8) << "YES";
	else cout << setw(8) << "NOY";
	return os;
}
