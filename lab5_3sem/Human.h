#pragma once
#include"Errors.h"

class Human
{
protected:
	char name[32];
	char surname[32];
	char data_of_birdth[11];
public:
	Human();
	Human(const Human& other);
	Human(char name[], char surname[], char data_of_birdth[]);
	~Human();
	virtual void Cap()const;
	char* GetName();
	char* GetSurname();
	char* GetDataOfBirdth();
	void SetName(char name[]);
	void SetSurname(char surname[]);
	void SetDataOfBirdth(char data_of_birdth[]);
	friend ostream& operator<<(std::ostream& os, const Human& obj);
	friend istream& operator>>(std::istream& in, Human& obj);
	Human& operator=(const Human& other);

};



