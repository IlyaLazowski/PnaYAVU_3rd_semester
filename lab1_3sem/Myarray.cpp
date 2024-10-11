#include "Myarray.h"


Myarray::Myarray(const Myarray& other)
{
	this->lenght = other.lenght;

	this->mas = new int[this->lenght];
	for (int i = 0; i < this->lenght; i++)
	{
		this->mas[i] = other.mas[i];
	}

	cout << "Object has been copied with address:  " << this << endl << endl;
}

Myarray::Myarray(int lenght)
{
	cout << "Constr  " << this << endl;
	this->lenght = lenght;
	mas = new int[lenght];
}


Myarray Myarray::Unit(Myarray ob2)
{
	Myarray ob(this->lenght + ob2.lenght);
	for (int i = 0, j = 0; i < this->lenght; i++)
	{
		ob.mas[i] = this->mas[i];
	}
	int counter = 0;
	bool flag;
	for (int i = 0; i < ob2.lenght; i++)
	{
		flag = true;
		for (int j = 0; j < this->lenght; j++)
		{
			if (this->mas[j] == ob2.mas[i])flag = false;
		}
		if (flag)
		{
			ob.mas[this->lenght + counter] = ob2.mas[i];
			counter++;
		}
	}
	ob.lenght = this->lenght + counter;
	return ob;
}

void Myarray::vvod_array()
{
	for (int i = 0; i < lenght; i++)
	{
		cout << "enter element:";
		cin >> mas[i];
	}
}

void Myarray::print_array()
{
	for (int i = 0; i < lenght; i++)
	{
		cout << mas[i] << " ";

	}
	cout << "\n\n";
}

Myarray::~Myarray()
{
	cout << "Destr  " << this << endl;
	delete[] mas;
	mas = nullptr;
}


