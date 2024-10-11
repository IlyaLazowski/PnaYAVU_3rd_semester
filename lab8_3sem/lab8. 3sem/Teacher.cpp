#include "Teacher.h"

Teacher::Teacher()
{
	read_coorse[0] = '\0';
	speciality[0] = '\0';
}

Teacher::Teacher(char name[], char surname[], char data_of_birdth[], char speciality[], char read_coorse[]) :Human(name, surname, data_of_birdth)
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

bool Teacher::operator==(Teacher& other)
{
	if (!Human::operator==(other)) {
		return false;
	}
	else
	{
		return true;
	}
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

fstream& operator<<(std::fstream& fs, Teacher& obj)
{
	fs.write((char*)&obj, sizeof(Teacher));
	return fs;
}

fstream& operator>>(std::fstream& fs, Teacher& obj)
{
	fs.read((char*)&obj, sizeof(Teacher));
	return fs;
}

ofstream& operator<<(std::ofstream& ofs, Teacher& obj)
{
	ofs << static_cast<Human&>(obj);
	ofs << obj.GetSpeciality() << '!' << obj.GetReadCoorse() << '!' << '\n';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, Teacher& obj)
{
	char str[32];
	ifs >> static_cast<Human&>(obj);
	ifs.getline(str, 32, '!');
	obj.SetSpeciality(str);
	ifs.getline(str, 32, '!');
	obj.SetReadCoorse(str);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	os << static_cast<const Human&>(obj);
	os << std::setiosflags(std::ios::left)
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
