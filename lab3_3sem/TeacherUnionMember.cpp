#include "TeacherUnionMember.h"

TeacherUnionMember::TeacherUnionMember()
{
	work_performed[0] = '\0';
	cout << "called the class TeacherUnionMember constructor with the address "<< endl;
}

TeacherUnionMember::TeacherUnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char autobiografi[][64], char post[], char speciality[], char scientific_works[][32], char work_performed[]) :Human(name, surname, data_of_birdth), UnionMember(name, surname, data_of_birdth, party_name, autobiografi), Teacher(name, surname, data_of_birdth, post, speciality, scientific_works)
{
	strcpy_s(this->work_performed,32, work_performed);
}

TeacherUnionMember::TeacherUnionMember(const TeacherUnionMember& other):Human(other),Teacher(other),UnionMember(other)
{
	strcpy_s(this->work_performed,32, other.work_performed);
}

char* TeacherUnionMember::GetWorkPerformed()
{
	return this->work_performed;
}

void TeacherUnionMember::SetWorkPerformed(char work_performed[])
{
	strcpy_s(this->work_performed, work_performed);
}

TeacherUnionMember::~TeacherUnionMember()
{
	cout << "called the class TeacherUnionMember destructor with the address " << endl;
}

std::ostream& operator<<(std::ostream& os, TeacherUnionMember& obj)
{
	os << static_cast<const Teacher&>(obj);
	os << left << setw(15) << "Party name:" << setw(15) << "Autobiography:"<<setw(15) << "Worfk performed:" << endl;
	os << left << setw(15) << obj.GetPartyName() << right << setw(14) << obj.GetAutobiography()[0]<<right<<setw(17)<<obj.work_performed << endl;
	for (int i = 1; i < 3; i++)
	{
		os << right << setw(29) << obj.GetAutobiography()[i] << endl;
	}
	return os;
}

std::istream& operator >> (std::istream& in, TeacherUnionMember& obj)
{
	in >> static_cast<Teacher&>(obj);
	cout << "Input party name: ";
	char str[32];
	rewind(stdin);
	in.getline(str, 32);
	obj.SetPartyName(str);
	cout << "Input your biografi: " << endl;
	char autobiography[3][64]{};
	for (int i = 0; i < 3; i++)
	{
		rewind(stdin);
		cin.getline(autobiography[i], 64);
	}
	obj.SetAutobiography(autobiography);
	cout << "Input work performed: ";
	in.getline(obj.work_performed, 32);
	return in;
}
