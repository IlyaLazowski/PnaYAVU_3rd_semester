//Yrliz.h
#pragma once
#include"Klient.h"
#include"Akvair.h"
#include"Zaim.h"
#include<vector>
#include <memory>

class Yrliz: public Klient
{
protected:
	char yr_name[20];
	int number_employees;
	vector<Zaim*> zaimu;
	vector<Akvair*> akvairu;
public:
	Yrliz();
	Yrliz(const Yrliz& other);
	~Yrliz();
	size_t GetZaimuSize();
	size_t GetAkvairuSize();
	vector<Zaim*>& GetZaimu();
	vector<Akvair*>& GetAkvairu();
	void SetYrName(char yr_name[]);
	void SetNumberEmployess(int number_employess);
	char* GetYrName();
	int GetNumberEmployess();
	void RegistrationZaim();
	void RegistrationAkvair();
	void DeletionUnderIndex(int index);
	virtual void Cap() const override;
	virtual double TotalBalance() const override;
	void RegistrationOfServices();
	Yrliz& operator=(const Yrliz& other);
	friend ifstream& operator>>(std::ifstream& ifs, Yrliz& obj);
	friend ofstream& operator<<(std::ofstream& ofs, Yrliz& obj);
	friend ostream& operator<<(std::ostream& os, const Yrliz& obj);
	friend istream& operator>>(std::istream& in, Yrliz& obj);
};