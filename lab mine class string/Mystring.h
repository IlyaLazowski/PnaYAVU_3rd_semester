#include <iostream>
using namespace std;

class Mystring 
{
	int lenght;
	char* str;
public:
	Mystring(const char* str);
	Mystring(const Mystring& other);
	void print();
	int get_lenght();
	Mystring set_str(char* str);
	Mystring();
	Mystring operator-(Mystring& obj);
	Mystring& operator=(Mystring& obj);
	Mystring operator+(Mystring& obj);
	char& operator[](int index);
	Mystring operator()(int start, int end);
	friend ostream& operator<<(std::ostream& os, const Mystring& obj);
	friend istream& operator>>(std::istream& in, Mystring& obj);
	bool operator<(Mystring& obj);
	bool operator>(Mystring& obj);
	void input_obj();
	~Mystring();
};

void menu();
void plus1();
void ravno();
void scobki();
void minus1();
void scobki2();
void menche();
void bolche();
void vivod();
void vvod();