//fname.h
#pragma once
#include"Yrliz.h"
#include"Fizliz.h"
using namespace std;
template<typename T>
inline string file_name()
{
	return "C++";
}
template<>
inline string file_name<Klient>()//получение имени файла через специализацию шаблона
{
	return "Klient.txt";
}
template<>
inline string file_name<Yrliz>()
{
	return "Yrliz.txt";
}
template<>
inline string file_name<Fizliz>()
{
	return "Fizliz.txt";
}
template<>
inline string file_name<Akvair>()
{
	return "Akvair.txt";
}
template<>
inline string file_name<Kredit>()
{
	return "Kredit.txt";
}
template<>
inline string file_name<Vklad>()
{
	return "Vklad.txt";
}
template<>
inline string file_name<Zaim>()
{
	return "Zaim.txt";
}

