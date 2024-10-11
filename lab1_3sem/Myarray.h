#include <iostream>
using namespace std;

class Myarray
{
	int lenght;
	int* mas;
public:
	Myarray(int n);
	Myarray(const Myarray& other);
	Myarray Unit(Myarray ob2);
	void print_array();
	void vvod_array();
	~Myarray();
};