#include "UnionMember.h"

UnionMember::UnionMember()
{
	party_name[0] = '\0';
	post[0] = '\0';
}

UnionMember::UnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char post[]) :Human(name, surname, data_of_birdth)
{
	strcpy_s(this->party_name, 32, party_name);
	strcpy_s(this->post, 32, post);
}

UnionMember::UnionMember(const UnionMember& other) :Human(other)
{
	strcpy_s(this->party_name, 32, other.party_name);
	strcpy_s(this->post, 32, other.post);
}

UnionMember& UnionMember::operator=(const UnionMember& other)
{
	Human::operator=(other);
	strcpy_s(this->party_name, 32, other.party_name);
	strcpy_s(this->post, 32, other.post);
	return *this;
}

bool UnionMember::operator==(UnionMember& other)
{
	if (!Human::operator==(other)) return false;
	else return true;
}

char* UnionMember::GetPartyName()
{
	return this->party_name;
}

char* UnionMember::GetPost()
{
	return this->post;
}

void UnionMember::SetPartyName(char* party_name)
{
	strcpy_s(this->party_name, 32, party_name);
}

void UnionMember::SetPost(char* post)
{
	strcpy_s(this->post, 32, post);
}

UnionMember::~UnionMember() {}

void UnionMember::Cap() const
{
	std::string line(95, '-');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "NAME"
		<< std::setw(20) << "SURNAME"
		<< std::setw(20) << "YEAR"
		<< std::setw(20) << "PART NAME"
		<< std::setw(20) << "POST"
		<< std::endl;
	std::cout << line << std::endl;
}

fstream& operator<<(std::fstream& fs, UnionMember& obj)
{
	fs.write((char*)&obj, sizeof(UnionMember));
	return fs;
}

fstream& operator>>(std::fstream& fs, UnionMember& obj)
{
	fs.read((char*)&obj, sizeof(UnionMember));
	return fs;
}

ofstream& operator<<(std::ofstream& ofs, UnionMember& obj)
{
	ofs << static_cast<Human&>(obj);
	ofs << obj.GetPartyName() << '!' << obj.GetPost() << '!' << '\n';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, UnionMember& obj)
{
	char str[32];
	ifs >> static_cast<Human&>(obj);
	ifs.getline(str, 32, '!');
	obj.SetPartyName(str);
	ifs.getline(str, 32, '!');
	obj.SetPost(str);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const UnionMember& obj)
{
	os << static_cast<const Human&>(obj);
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << obj.party_name
		<< std::setw(20) << obj.post;
	return os;
}

std::istream& operator >> (std::istream& in, UnionMember& obj)
{
	in >> static_cast<Human&>(obj);
	ExaminationLine(obj.party_name, "¬ведите название партии: ");
	ExaminationLine(obj.post, "¬ведите должность: ");
	return in;
}
