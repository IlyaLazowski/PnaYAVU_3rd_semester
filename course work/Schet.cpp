#include "Schet.h"

Schet::Schet()
{
	this->account_number[0] = '\0';
	this->interest_rate = 0;
	this->sum = 0;
	this->type[0] = '\0';
}

Schet::Schet(char type[], char account_number[], double interest_rate, double sum)
{
	strcpy_s(this->type, 10, type);
	strcpy_s(this->account_number, 20,account_number );
	this->interest_rate = interest_rate;
	this->sum = sum;
}

Schet::Schet(const Schet& other)
{
	strcpy_s(this->type, 10, other.type);
	strcpy_s(this->account_number, 20, other.account_number);
	this->interest_rate = other.interest_rate;
	this->sum = other.sum;
}

Schet::~Schet(){}

void Schet::Cap() const{}

bool Schet::operator<(Schet& other)
{
	if (this->interest_rate > other.interest_rate) return true;
	else return false;
}

bool Schet::operator>(Schet& other)
{
	if (this->sum > other.sum) return true;
	else return false;
}

void Schet::SetType(char type[])
{
	strcpy_s(this->type, 10, type);
}

char* Schet::GetType()
{
	return this->type;
}

char* Schet::GetAccountNumber()
{
	return this->account_number;
}

double Schet::GetInterestRate()
{
	return this->interest_rate;
}

Schet& Schet::operator=(const Schet& other)
{
	strcpy_s(this->type, 10, other.type);
	strcpy_s(this->account_number, 20, other.account_number);
	this->interest_rate = other.interest_rate;
	this->sum = other.sum;
	return *this;
}

bool Schet::operator==(Schet& other)
{
	if (other.interest_rate != 0)
		if (this->interest_rate!=other.interest_rate)
			return false;
	if (other.sum != 0)
		if (this->sum != other.sum)
			return false;
	return true;
}

double Schet::GetSum()
{
	return this->sum;
}

void Schet::SetAccountNumber(char account_number[])
{
	strcpy_s(this->account_number, 20, account_number);
}

void Schet::SetInterestRate(double interest_rate)
{
	this->interest_rate = interest_rate;
}

void Schet::SetSum(double sum)
{
	this->sum = sum;
}

ostream& operator<<(std::ostream& os, const Schet& obj)
{
	return os;
}

std::istream& operator >> (std::istream& in, Schet& obj)
{
	cout << "¬ведите желаемую процентную ставку(2-5): ";
	obj.interest_rate = CreateDouble(2.0, 5.0);
	strcpy_s(obj.account_number, 20, "SCHET NUMBER");
	cout << "¬ам сгенерирован счЄт услуги" << endl;
	cout << "¬ведите начальную сумму(100-10000): ";
	obj.sum = CreateDouble(100.0, 10000.0);
	return in;
}