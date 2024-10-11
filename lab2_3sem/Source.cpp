#include "Myarray.h"

int main()
{
	int size1, size2;
	cout << "enter size first array:";
	cin >> size1;
	cout << "\nenter size second array:";
	cin >> size2;
	Myarray array1(size1), array2(size2);
	array1.vvod_array();
	cout << "your array:";
	array1.print_array();
	array2.vvod_array();
	cout << "your array:";
	array2.print_array();
	Myarray array3 = array1+array2;
	cout << "final array:";
	array3.print_array();
	return 0;
}
