//Fizliz.h
#pragma once
#include"Klient.h"
#include"Vklad.h"
#include"Kredit.h"
#include<vector>
#include <memory>
class Fizliz : public Klient
{
protected:
	char phone[10];
	char pasport[10];
	vector<Vklad*> vkladu;
	vector<Kredit*> kreditu;
public:
	Fizliz();
	Fizliz(const Fizliz& other);
	~Fizliz();
	char* GetPhone();
	char* GetPasport();
	void SetPhone(char phone[]);
	void SetPasport(char pasport[]);
    size_t GetKredituSize();
	size_t GetVkladuSize();
	vector<Kredit*>& GetKreditu();
	vector<Vklad*>& GetVkladu();
	void RegistrationVklad();
	void RegistrationKredit();
	void DeletionUnderIndex(int index);
	virtual void Cap() const override;
	virtual double TotalBalance() const override;
	void RegistrationOfServices();
	Fizliz& operator=(const Fizliz& other);
	friend ifstream& operator>>(std::ifstream& ifs, Fizliz& obj);
	friend ofstream& operator<<(std::ofstream& ofs, Fizliz& obj);
	friend ostream& operator<<(std::ostream& os, const Fizliz& obj);
	friend istream& operator>>(std::istream& in, Fizliz& obj);
};