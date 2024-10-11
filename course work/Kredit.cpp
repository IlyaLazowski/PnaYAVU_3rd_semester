#include "Kredit.h"

Kredit::Kredit()
{
	this->monthly_fee = 0;
	this->time = 0;
}

Kredit::Kredit(char type[], char account_number[], double interest_rate, double sum, double monthly_fee, int time) :Schet(type, account_number, interest_rate, sum)
{
	this->monthly_fee = monthly_fee;
	this->time = time;
}

Kredit::Kredit(const Kredit& other):Schet(other)
{
	strcpy_s(this->type, 10, other.type);
	this->monthly_fee = other.monthly_fee;
	this->time = other.time;
}

Kredit::~Kredit()
{

}

int Kredit::GetTime()
{
	return this->time;
}

double Kredit::GetMonthlyFee()
{
	return this->monthly_fee;
}

void Kredit::SetTime(int time)
{
	this->time = time;
}

void Kredit::SetMonthlyFee(double monthly_fee)
{
	this->monthly_fee = monthly_fee;
}

Kredit* Kredit::clone() const
{
	return new Kredit(*this);
}

void Kredit::Cap() const
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
		<< std::setw(14) << "PAYMENT"
		<< std::endl;
	std::cout << line << std::endl;
}

void Kredit::Output(int i)
{
	cout << setiosflags(ios::left)
		<< std::setw(10) << i
		<< setw(10) << "KREDIT"
		<< setw(21) << this->account_number
		<< setw(9) << this->interest_rate
		<< setw(11) << this->sum
		<< setw(6) << this->time
		<< setw(14) << this->monthly_fee;
}

void Kredit::ChangingServiceFields()
{
	int choise;
	do
	{
		cout << "Что вы хотите изменить\n";
		cout << "1. Процентную ставку\n";
		cout << "2. Сумму кредита\n";
		cout << "3. Время на которое выдан кредит\n";
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
			cout << "Введите новую сумму кредита: ";
			this->sum = CreateDouble(1, 5000);
		}
		break;
		case 3:
		{
			cout << "Введите новое время на которое будет выдан кредит: ";
			this->time = CreateInt(1, 96);
		}
		break;
		}
	} while (choise != 4);
	this->monthly_fee = (this->sum * (this->interest_rate / 100) + this->sum) / this->time;
}

Kredit& Kredit::operator=(const Kredit& other)
{
	Schet::operator=(other);
	this->monthly_fee = monthly_fee;
	this->time = time;
	return *this;
}

bool Kredit::operator==(Kredit& other)
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
	if (other.monthly_fee != 0)
		if (this->monthly_fee!= other.monthly_fee)
			return false;
	return true;
}



ofstream& operator<<(std::ofstream& ofs, Kredit& obj)
{
	ofs << "KREDIT" << '!' << obj.account_number << '!' << obj.interest_rate << '!' << obj.sum << '!' << obj.time << '!' << obj.monthly_fee << '\n';
	return ofs;
}



ifstream& operator>>(std::ifstream& ifs, Kredit& obj)
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
	ifs >> doubl_type;
	obj.SetMonthlyFee(doubl_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}


std::ostream& operator<<(std::ostream& os, const Kredit& obj)
{
	cout << setiosflags(ios::left)
		<< setw(10) << "KREDIT"
		<< setw(21) << obj.account_number
		<< setw(9) << obj.interest_rate
		<< setw(11) << obj.sum
		<< setw(6) << obj.time
		<< setw(14) << obj.monthly_fee
		<< setw(6) << "-";
	return os;
}

istream& operator>>(std::istream& in, Kredit& obj)
{
	strcpy_s(obj.type, 10, "Kredit");
	cout << "В желаемую процентную ставку(5-7): ";
	obj.interest_rate = CreateDouble(5.0, 7.0);
	strcpy_s(obj.account_number, 20, "SCHET NUMBER");
	cout << "Введите желаемую сумму(10000-100000): ";
	obj.sum = CreateDouble(10000.0, 100000.0);
	cout << "Введите количество месяцев на которое вы хотите открыть кредит(6-48): ";
	obj.time = CreateInt(6, 48);
	obj.monthly_fee = (obj.sum * (obj.interest_rate/100) + obj.sum) / obj.time;
	return in;
}
