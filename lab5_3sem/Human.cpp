#include "Human.h"

Human::Human()
{
	this->name[0] = '\0';
	this->surname[0] = '\0';
	this->data_of_birdth[0] = '\0';
}

Human::Human(const Human& other)
{
	strcpy_s(this->data_of_birdth, 11, other.data_of_birdth);
	strcpy_s(this->name, 32, other.name);
	strcpy_s(this->surname, 32, other.surname);
}

Human::Human(char name[], char surname[], char data_of_birdth[])
{
	strcpy_s(this->name, 32, name);
	strcpy_s(this->surname, 32, surname);
	strcpy_s(this->data_of_birdth, 11, data_of_birdth);
}

char* Human::GetName()
{
	return this->name;
}

char* Human::GetSurname()
{
	return this->surname;
}

Human& Human::operator=(const Human& other)
{
	strcpy_s(this->data_of_birdth, 11, other.data_of_birdth);
	strcpy_s(this->name, 32, other.name);
	strcpy_s(this->surname, 32, other.surname);
	return *this;
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
	strcpy_s(this->surname, surname);
}

void Human::SetDataOfBirdth(char data_of_birdth[])
{
	strcpy_s(this->data_of_birdth, data_of_birdth);
}

Human::~Human(){}

void Human::Cap() const{}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	cout << setiosflags(ios::left)
		<< setw(20) << obj.name
		<< setw(20) << obj.surname
		<< setw(20) << obj.data_of_birdth;
	return os;
}

std::istream& operator >> (std::istream& in, Human& obj)
{
	CreateName(obj.name, "¬ведите им€: ");
	CreateName(obj.surname, "¬ведите фамилию: ");
    CreateDate(obj.data_of_birdth);
	return in;
}



