#pragma once
#include"StackOtmena.h"

template<typename T>
Stack<T>::~Stack()
{
	RemoveAll();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& obj)
{
	first = obj.first;
	size = obj.size;
}

template<typename T>
Stack<T>::Stack()
{
	first = nullptr;
	size = 0;
}

template<class T>
int Stack<T>::show_size()
{
	return size;
}

template<class T>
void Stack<T>::add_data(T data)
{
	++size;
	element<T>* new_element = new element<T>;
	new_element->data = data;
	new_element->next = nullptr;
	if (!first)
	{
		first = new_element;
	}
	else
	{
		new_element->next = first;
		first = new_element;
	}
}

template<class T>
void Stack<T>::Prosmotr_elemntov()
{
	if (!first)
	{
		cout << "\nСтек пустой" << endl;
		return;
	}
	element<T>* n = first;
	while (n)
	{
		cout << endl << n->data;
		n = n->next;
	}
	cout << endl;
}

template<class T>
T Stack<T>::POP()
{
	size--;
	T str;
	element<T>* n = first;
	first = first->next;
	str = n->data;
	delete n;
	return str;
}

template <class T>
void Stack<T>::RemoveAll()
{
	while (first != nullptr)
	{
		element<T>* n = first->next;
		delete first;
		first = n;
	}
	size = 0;
}
