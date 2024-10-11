//StackOtmena.h
#pragma once
#include<iostream>
using namespace std;

template<class T>  // структура для реализации у
struct element
{
	T data{};
	element* next{};
};

template<class T>
class Stack
{
private:
	element<T>* first;
	int size;
public:
	Stack();
	Stack(const Stack<T>& obj);
	~Stack();
	T POP();
	void add_data(T data);
	void Prosmotr_elemntov();
	void RemoveAll();
	int show_size();
};
