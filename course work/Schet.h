//Schet.h
#pragma once
#include"Errors.h"
class Schet
{
protected:
	char account_number[20];
	double interest_rate;      // процентная ставка
	double sum;
	char type[10];
public:
	Schet();
	Schet(char type[], char account_number[], double interest_rate, double sum);
	Schet(const Schet& other);
	~Schet();
	void SetType(char type[]);
	char* GetType();
	double GetInterestRate();
	char* GetAccountNumber();
	double GetSum();
	void SetSum(double sum);
	void SetAccountNumber(char account_number[]);
	void SetInterestRate(double interest_rate);
	virtual void Cap()const;
	virtual Schet* clone() const = 0;
	bool operator<(Schet& other);
	bool operator>(Schet& other);
	Schet& operator=(const Schet& other);
	bool operator==(Schet& other);
	friend ostream& operator<<(std::ostream& os, const Schet& obj);
	friend istream& operator>>(std::istream& in, Schet& obj);
};
