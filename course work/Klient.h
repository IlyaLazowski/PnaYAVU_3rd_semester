//Klient.h
#pragma once
#include"Errors.h"
class Klient
{
protected:
	char surname[32];
	char personal_account[20];
	double balance;
	int pin_code;
	double salary;
	static char count_schet[20];
private:
	static char count_klient[20];
public:
	Klient();
	Klient(const Klient& other);
	Klient(char surname[], char personal_account[], double balance , int pin_code , double salary);
	~Klient();
	int GetPinCode();
	char* GetPersonalAccount();
	char* GetSurname();
	double GetBalance();
	double GetSalary();
	void SetPersonalAccount(char personal_account[]);
	void SetSurname(char surname[]);
	void SetSalary(double salary);
	void SetBalance(double balance);
	void SetPinCode(int pin_code);
	void RegistrationOfServices();
	virtual void Cap() const;
	virtual double TotalBalance() const;
	bool operator<(Klient& other);
	bool operator>(Klient& other);
	Klient& operator=(const Klient& other);
	bool operator==(Klient& other);
	friend ofstream& operator<<(std::ofstream& ofs, Klient& obj);
	friend ifstream& operator>>(std::ifstream& is, Klient& obj);
	friend ostream& operator<<(std::ostream& os, const Klient& obj);
	friend istream& operator>>(std::istream& in, Klient& obj);
};