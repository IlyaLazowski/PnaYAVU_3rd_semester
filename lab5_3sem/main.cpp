#include"Menu.h"
#include <windows.h>  

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	system("color 6");
	Menu a{};
	a.start();

	return 0;
}








