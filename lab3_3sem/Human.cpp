#include "Human.h"

Human::Human()
{
	this->name[0] = '\0';
	this->surname[0] = '\0';
	this->data_of_birdth[0] = '\0';
	cout << "called the class Human constructor with the address " << endl;
}

Human::Human(const Human& other)
{
	strcpy_s(this->data_of_birdth,11, other.data_of_birdth);
	strcpy_s(this->name,32, other.name);
	strcpy_s(this->surname,32, other.surname);
}

Human::Human(char name[], char surname[], char data_of_birdth[])
{
	strcpy_s(this->name,32, name);
	strcpy_s(this->surname,32, surname);
	strcpy_s(this->data_of_birdth,11, data_of_birdth);
}

char* Human::GetName()
{
	return this->name;
}

char* Human::GetSurname()
{
	return this->surname;
}

char* Human::GetDataOfBirdth()
{
	return this->data_of_birdth;
}

void Human::SetName(char name[])
{
	strcpy_s(this->name, name);
}

void Human::SetSurname(char surname[])
{
	strcpy_s(this->surname,surname);
}

void Human::SetDataOfBirdth(char data_of_birdth[])
{
	strcpy_s(this->data_of_birdth, data_of_birdth);
}

Human::~Human()
{
	cout << "called the class Human destructor with the address "<< endl;
}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	os << left << setw(15) << "Name:" << setw(15) << "Surname:" << setw(30) << "Data birdth:" << endl;
	os  << left<< setw(15) << obj.name << setw(15) <<obj.surname << setw(30) <<obj.data_of_birdth << endl<<endl;
	return os;
}

std::istream& operator >> (std::istream& in, Human& obj)
{
	cout << "Input name :";
	in.getline(obj.name, 32);
	cout << "Input surname :";
	in.getline(obj.surname, 32);
	cout << "Input data of birdth in format xx.xx.xxxx: ";
	in.getline(obj.data_of_birdth, 11);
	return in;
}



