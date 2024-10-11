#include "Teacher.h"

Teacher::Teacher()
{
	post[0] = '\0';
	speciality[0] = '\0';
	for (int i=0;i<5;i++)
	{
		scientific_works[i][0] = '\0';
	}
	cout << "called the class Teacher constructor with the address "<< endl;
}

Teacher::Teacher(char name[], char surname[], char data_of_birdth[] ,char post[], char speciality[], char scientific_works[][32]):Human(name,surname,data_of_birdth)
{
	strcpy_s(this->post,32, post);
	strcpy_s(this->speciality,32, speciality);
	for (int i = 0; i < 5; i++)
	{
		strcpy_s(this->scientific_works[i],32, scientific_works[i]);
	}
}

Teacher::Teacher(const Teacher& other):Human(other)
{
	strcpy_s(this->post,32, other.post);
	strcpy_s(this->speciality,32, other.speciality);
	for (int i = 0; i < 5; i++)
	{
		strcpy_s(this->scientific_works[i],32, other.scientific_works[i]);
	}
}

char* Teacher::GetPost()
{
	return this->post;
}

char* Teacher::GetSpeciality()
{
	return this->speciality;
}

char(*Teacher::GetScientificWorks())[32]
{
	return this->scientific_works;
}

void Teacher::SetPost(char post[])
{
	strcpy_s(this->post, post);
}

void Teacher::SetSpeciality(char speciality[])
{
	strcpy_s(this->speciality, speciality);
}

void Teacher::SetScientificWorks(char scientific_works[][64])
{
	for (int i = 0; i < 5; i++)
		strcpy_s(this->scientific_works[i], scientific_works[i]);
}

Teacher::~Teacher()
{
	cout << "called the class Teacher destructor with the address " << endl;
}

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	os << static_cast<const Human&>(obj);
	os << left << setw(15) << "Post:" << setw(15) << "Speciality:" << setw(30) << "Scientific works:" << endl;
	os << left << setw(15) << obj.post << setw(15) << obj.speciality<<right<<setw(16)<<obj.scientific_works[0]<<endl;
	for (int i = 1; i < 5; i++)
	{
		os << right << setw(46) << obj.scientific_works[i]<<endl;
		if (obj.scientific_works[i + 1][0] == '\0') break;
	}
	return os;
}

std::istream& operator >> (std::istream& in, Teacher& obj)
{
	in >> static_cast<Human&>(obj);
	cout << "Input post: ";
	in.getline(obj.post, 32);
	cout << "Input speciality: ";
	in.getline(obj.speciality, 32);
	int count = 0;
	cout << "Input count of scientific works: ";
	cin >> count;
	if (count <= 0)
	{
		strcpy_s(obj.scientific_works[0], "There are no scientific works");
	}
	else
	{
		for (int i = 0; i < count && i < 5; i++)
		{
			rewind(stdin);
			in.getline(obj.scientific_works[i], 32);
		}
	}
	return in;
}
