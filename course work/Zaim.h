//Zaim.h
#pragma once
#include"Schet.h"
class Zaim : public Schet
{
protected:
	char date[11];
public:
	Zaim();
	Zaim(const Zaim& other);
	Zaim(char type[], char account_number[], double interest_rate, double sum, char date[]);
	~Zaim();
	void SetDate(char date[]);
	char* GetDate();
	void Output(int i);
	virtual void Cap()const override;
	Zaim* clone() const override;
	void ChangingServiceFields();
	Zaim& operator=(const Zaim& other);
	bool operator==(Zaim& other);
	friend ofstream& operator<<(std::ofstream& ofs, Zaim& obj);
	friend ifstream& operator>>(std::ifstream& ifs, Zaim& obj);
	friend std::ostream& operator<<(std::ostream& os, const Zaim& obj);
	friend istream& operator>>(std::istream& in, Zaim& obj);
};