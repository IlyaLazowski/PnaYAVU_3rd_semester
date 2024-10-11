#pragma once
#include"TXTFILE.cpp"
#include"BINFILE.cpp"
#include"fname.h"
#include"Algorithm.cpp"
#include<list>
class Menu
{
	int choise;
	int type;
public:
	void start();
	template<typename T>
	void OperatingRingList(RingList<T>& list);
	template<typename T>
	void STL();
};
