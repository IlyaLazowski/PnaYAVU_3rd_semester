#include "UnionMember.h"
#include "Teacher.h"

UnionMember::UnionMember()
{
	party_name[0] = '\0';
	for (int i=0;i<3;i++)
	{
		autobiography[i][0] = '\0';
	}
	cout << "called the class UnionMember constructor with the address " << endl;
}

UnionMember::UnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char autobiografi[][64]) :Human(name, surname, data_of_birdth)
{
	strcpy_s(this->party_name,32, party_name);
	for (int i = 0; i < 3; i++)
	{
		strcpy_s(this->autobiography[i],64, autobiografi[i]);
	}
}

UnionMember::UnionMember(const UnionMember& other):Human(other)
{
	strcpy_s(this->party_name,32, other.party_name);
	for (int i=0;i<3;i++)
	{
	strcpy_s(this->autobiography[i], 64,other.autobiography[i]);
	}
}

char* UnionMember::GetPartyName()
{
	return this->party_name;
}

char(*UnionMember::GetAutobiography())[64] 
{
	return this->autobiography;
}

void UnionMember::SetPartyName(char* party_name)
{
	strcpy_s(this->party_name, party_name);
}

void UnionMember::SetAutobiography(char autobiography[][64])
{
	for (int i = 0; i < 3; i++)
		strcpy_s(this->autobiography[i], autobiography[i]);
}

UnionMember::~UnionMember()
{
	cout << "called the class UnionMember destructor with the address " << endl;
}

std::ostream& operator<<(std::ostream& os, const UnionMember& obj)
{
	os << static_cast<const Human&>(obj);
	os << left << setw(15) << "Party name:" << setw(15) << "Autobiography:"<< endl;
	os << left << setw(15) << obj.party_name << right << setw(14) << obj.autobiography[0] << endl;
	for (int i = 1; i < 3; i++)
	{
		os << right << setw(29) << obj.autobiography[i] << endl;
	}
	return os;
}

std::istream& operator >> (std::istream& in, UnionMember& obj)
{
	in >> static_cast<Human&>(obj);
	rewind(stdin);
	cout << "Input party name: ";
	in.getline(obj.party_name, 32);
	cout << "Input your biografi: " << endl;

	for (int i = 0; i < 3; i++)
	{

		rewind(stdin);
		cin.getline(obj.autobiography[i], 64);
	}

	return in;
}






