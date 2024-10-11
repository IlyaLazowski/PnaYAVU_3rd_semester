//Kredit.h
#pragma once
#include"Schet.h"
class Kredit : public Schet
{
protected:
	double monthly_fee; // ежемес€чный взнос
	int time;
public:
	Kredit();
	Kredit(char type[], char account_number[], double interest_rate, double sum, double monthly_fee, int time);
	Kredit(const Kredit& other);
	~Kredit();
	int GetTime();
	double GetMonthlyFee();
	void SetTime(int time);
	void SetMonthlyFee(double monthly_fee);
	Kredit* clone() const override;
	virtual void Cap()const override;
	void Output(int i);
	void ChangingServiceFields();
	Kredit& operator=(const Kredit& other);
	bool operator==(Kredit& other);
	friend ofstream& operator<<(std::ofstream& ofs, Kredit& obj);
	friend ifstream& operator>>(std::ifstream& ifs, Kredit& obj);
	friend std::ostream& operator<<(std::ostream& os, const Kredit& obj);
	friend istream& operator>>(std::istream& in, Kredit& obj);
};
