#include "Mystring.h"

int main()
{
	//while (1)
	//{
	//	menu();
	//	int choose;
	//	cin >> choose;
	//	if (choose <= 0 || choose >= 10)break;
	//	cin.ignore();
	//	if (choose == 1)plus1();
	//	else if (choose == 2)ravno();
	//	else if (choose == 3)scobki();
	//	else if (choose == 4)minus1();
	//	else if (choose == 5)scobki2();
	//	else if (choose == 6)menche();
	//	else if (choose == 7)bolche();
	//	else if (choose == 8)vivod();
	//	else if (choose == 9)vvod();
	//}

	Mystring a, b;
	cout << "enter name:";
	cin >> a;
	cout << "enter name:";
	cin >> b;
	Mystring result=a+b;
	cout << result;
	return 0;
}
