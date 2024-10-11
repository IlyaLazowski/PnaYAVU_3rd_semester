#include "Human.h"
#include <fstream>
#include <iostream> 
#include <fstream> 
#include <cstring> 
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

bool Human::operator==(Human& other)
{
	if (other.name[0] != '\0')
		if (strcmp(this->name, other.name)!=0)
			return false;
	if (other.surname[0] != '\0')
		if (strcmp(this->surname, other.surname) != 0)
			return false;
	if (other.data_of_birdth[0] != '\0')
		if (strcmp(this->data_of_birdth, other.data_of_birdth) != 0)
			return false;
	return true;
}

bool Human::operator<(Human& other)
{
	if (LenghtOfStrlen(this->surname) < LenghtOfStrlen(other.GetSurname())) return true;
	else return false;
}
bool Human::operator>(Human& other)
{
	if (stoi(string(this->data_of_birdth).substr(6, 4)) < stoi(string(other.GetDataOfBirdth()).substr(6, 4))) return true;
	else return false;
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

Human::~Human() {}

void Human::Cap() const {}

fstream& operator<<(std::fstream& fs, Human& obj)
{
	fs.write((char*)&obj, sizeof(Human));
	return fs;
}

fstream& operator>>(std::fstream& fs, Human& obj)
{
	fs.read((char*)&obj, sizeof(Human));
	return fs;
}

ofstream& operator<<(std::ofstream& ofs, Human& obj)
{
	ofs << obj.GetName() << '!' << obj.GetSurname() << '!' << obj.GetDataOfBirdth() <<'!';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	char str[32];
	ifs.getline(str, 32, '!');
	obj.SetName(str);
	ifs.getline(str, 32, '!');
	obj.SetSurname(str);
	ifs.getline(str, 11, '!');
	obj.SetDataOfBirdth(str);
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	os << setiosflags(ios::left)
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