#include "TeacherUnionMember.h"

TeacherUnionMember::TeacherUnionMember()
{
	work_performed[0] = '\0';
}

TeacherUnionMember::TeacherUnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char post[], char speciality[],char read_coorse[], char work_performed[]) :Human(name, surname, data_of_birdth), UnionMember(name, surname, data_of_birdth, party_name, post), Teacher(name, surname, data_of_birdth, speciality , read_coorse)
{
	strcpy_s(this->work_performed, 32, work_performed);
}

TeacherUnionMember::TeacherUnionMember(const TeacherUnionMember& other) :Human(other), Teacher(other), UnionMember(other)
{
	strcpy_s(this->work_performed, 32, other.work_performed);
}

void TeacherUnionMember::Cap() const
{
	std::string line(160, '-');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "NAME"
		<< std::setw(20) << "SURNAME"
		<< std::setw(20) << "YEAR"
		<< std::setw(20) << "SPECIALITY"
		<< std::setw(20) << "COORSE"
		<< std::setw(20) << "PART NAME"
		<< std::setw(20) << "POST"
		<< std::setw(20) << "WORK PERWORMED"
		<< std::endl;
	std::cout << line << std::endl;
}


TeacherUnionMember& TeacherUnionMember::operator=(const TeacherUnionMember& other)
{
	Human::operator=(other);
	Teacher::operator=(other);
	UnionMember::operator=(other);
	strcpy_s(this->work_performed, 32, other.work_performed);
	return *this;
}

char* TeacherUnionMember::GetWorkPerformed()
{
	return this->work_performed;
}

void TeacherUnionMember::SetWorkPerformed(char work_performed[])
{
	strcpy_s(this->work_performed, work_performed);
}

TeacherUnionMember::~TeacherUnionMember(){}

std::ostream& operator<<(std::ostream& os, TeacherUnionMember& obj)
{
	os << static_cast<const Teacher&>(obj);
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << obj.party_name
		<< std::setw(20) << obj.post
	    << std::setw(20) << obj.work_performed;
	return os;
}

std::istream& operator >> (std::istream& in, TeacherUnionMember& obj)
{
	in >> static_cast<Teacher&>(obj);
	ExaminationLine(obj.party_name, "¬ведите название партии: ");
	ExaminationLine(obj.post, "¬ведите должность: ");
	ExaminationLine(obj.work_performed, "¬ведите работу в партии: ");

	return in;
}
