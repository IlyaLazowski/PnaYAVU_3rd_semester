//Vklad.h
#pragma once
#include "Schet.h"
class Vklad : public Schet
{
protected:
	int time;
	bool permission;// разрешение пополнения

public:
	Vklad();
	Vklad(const Vklad& other);
	Vklad(char type[], char account_number[], double interest_rate, double sum, int time, bool permission);
	~Vklad();
	int GetTime();
	bool GetPermission();
	void SetTime(int time);
	void SetPermission(bool permission);
	void Output(int i);
	virtual void Cap()const override;
	void ChangingServiceFields();
	Vklad* clone() const override;
	Vklad& operator=(const Vklad& other);
	bool operator==(const Vklad& other);
	friend ofstream& operator<<(std::ofstream& ofs, Vklad& obj);
	friend ifstream& operator>>(std::ifstream& ifs, Vklad& obj);
	friend std::ostream& operator<<(std::ostream& os, const Vklad& obj);
	friend istream& operator>>(std::istream& in, Vklad& obj);
};
