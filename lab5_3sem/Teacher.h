#pragma once
#include "Human.h"

class Teacher :virtual public Human
{
protected:
	char read_coorse[32];     //должность 
	char speciality[32];
public:
	Teacher();
	Teacher(char name[], char surname[], char data_of_birdth[], char read_coorse[], char speciality[]);
	Teacher(const Teacher& other);
	~Teacher();
	virtual void Cap()const override;
	char* GetReadCoorse();
	char* GetSpeciality();
	void SetReadCoorse(char post[]);
	void SetSpeciality(char speciality[]);
	friend ostream& operator<<(std::ostream& os, const Teacher& obj);
	friend istream& operator>>(std::istream& in, Teacher& obj);
	Teacher& operator=(const Teacher& other);
};
