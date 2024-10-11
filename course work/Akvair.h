//Akvair.h
#pragma once
#include"Schet.h"
class Akvair : public Schet
{
protected:
	char model[16];
public:
	Akvair();
	Akvair(const Akvair& other);
	Akvair(char type[], char account_number[], double interest_rate, double sum, char model[]);
	~Akvair();
	void SetModel(char model[]);
	char* GetModel();
	virtual void Cap()const override;
	void Output(int i);
	Akvair* clone() const override;
	void ChangingServiceFields();
	Akvair& operator=(const Akvair& other);
	bool operator==(Akvair& other);
	friend ofstream& operator<<(std::ofstream& ofs, Akvair& obj);
	friend ifstream& operator>>(std::ifstream& ifs, Akvair& obj);
	friend std::ostream& operator<<(std::ostream& os, const Akvair& obj);
	friend istream& operator>>(std::istream& in, Akvair& obj);
};