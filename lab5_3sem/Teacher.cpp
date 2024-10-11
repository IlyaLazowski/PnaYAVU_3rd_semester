#include "Teacher.h"

Teacher::Teacher()
{
	read_coorse[0] = '\0';
	speciality[0] = '\0';
}

Teacher::Teacher(char name[], char surname[], char data_of_birdth[],char speciality[] ,char read_coorse[]) :Human(name, surname, data_of_birdth)
{
	strcpy_s(this->read_coorse, 32, read_coorse);
	strcpy_s(this->speciality, 32, speciality);
}

Teacher::Teacher(const Teacher& other) :Human(other)
{
	strcpy_s(this->speciality, 32, other.speciality);
	strcpy_s(this->read_coorse, 32, other.read_coorse);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	Human::operator=(other);
	strcpy_s(this->speciality, 32, other.speciality);
	strcpy_s(this->read_coorse, 32, other.read_coorse);
	return *this;
}

char* Teacher::GetReadCoorse()
{
	return this->read_coorse;
}

char* Teacher::GetSpeciality()
{
	return this->speciality;
}

void Teacher::SetReadCoorse(char read_coorse[])
{
	strcpy_s(this->read_coorse, read_coorse);
}

void Teacher::SetSpeciality(char speciality[])
{
	strcpy_s(this->speciality, speciality);
}

Teacher::~Teacher() {}

void Teacher::Cap() const
{
	std::string line(95, '-');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "NAME"
		<< std::setw(20) << "SURNAME"
		<< std::setw(20) << "YEAR"
		<< std::setw(20) << "SPECIALITY"
		<< std::setw(20) << "COORSE"
		<< std::endl;
	std::cout << line << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	os << static_cast<const Human&>(obj);
	cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << obj.speciality
		<< std::setw(20) << obj.read_coorse;
	return os;
};

std::istream& operator >> (std::istream& in, Teacher& obj)
{
	in >> static_cast<Human&>(obj);
	ExaminationLine(obj.read_coorse, "¬ведите читаемый курс: ");
	ExaminationLine(obj.speciality, "¬ведите специальность: ");
	return in;
}
