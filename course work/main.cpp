#include"Interface.cpp"
#include <typeinfo>
int main()
{
	system("color 80");
	setlocale(LC_ALL, "RUS");
	Interface a{};
	a.opr_dostupa();   //запуск начального меню
	return 0;
}