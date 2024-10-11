#pragma once
#include"TXTFILE.h"
#include"BINFILE.h"
#include"fname.h"
#include"Algorithm.cpp"
class Menu
{
	int choise;
	int type;
public:
	void start();
	template<typename T>
	void OperatingRingList(RingList<T>& list);
};
