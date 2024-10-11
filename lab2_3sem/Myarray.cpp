#include "Myarray.h"

Myarray::Myarray(int lenght)
{
	this->lenght = lenght;
	mas = new int[lenght];
}

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

Myarray Myarray::operator+(const Myarray &other) {
    Myarray result(this->lenght + other.lenght);
    for (int i = 0; i < this->lenght; i++) {
        result.mas[i] = this->mas[i];
    }
    int counter = 0;
    bool flag;
    for (int i = 0; i < other.lenght; i++) {
        flag = true;
        for (int j = 0; j < this->lenght; j++) {
            if (this->mas[j] == other.mas[i]) {
                flag = false;
            }
        }
        if (flag) {
            result.mas[this->lenght + counter] = other.mas[i];
            counter++;
        }
    }
    result.lenght = this->lenght + counter;
    return result;
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
	delete[] mas;
	mas = nullptr;
}


