//Interface.h
#pragma once
#include"RingList.cpp"
#include"TEXTFILE.cpp"
#include"Algorithm.cpp"
#include"StackOtmena.cpp"
#include<list>
class Interface
{
	void StartForAdmin();
	void StartforUser();
	template<typename T>
	void AdminOsperationsWithBankServices(RingList<T>& list);
	template<typename T>
	void OperationsWithClientObjects(RingList<T>& list);
	template<typename T>
	void OperationsWithObject(T& a, RingList<T>& list, Stack<T>& otmena, Stack<int>& deistvie);
	template<typename T>
	void STL();
	template<typename T>
	void AdminWorkWithClients(RingList<T>& list);
public:
	void opr_dostupa();
};