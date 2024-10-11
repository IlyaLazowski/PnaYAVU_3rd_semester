#include "Mystring.h"

Mystring::Mystring(const Mystring& other)
{
    this->lenght = other.lenght;
    this->str = new char[this->lenght+1];
    for (int i = 0; i < this->lenght; i++)this->str[i] = other.str[i];
    this->str[lenght] = '\0';
    cout << "Object has been COPIED with address:  " << this << endl << endl;
}

Mystring::Mystring()
{
    this->lenght =0;
    this->str = nullptr;
    cout << "Object has been CREATE with address:  " << this << endl << endl;
}

Mystring::Mystring(const char* str)
{
    this->lenght = strlen(str);
    this->str = new char[lenght+1];
    for (int i=0;i<this->lenght;i++)this->str[i] = str[i];
    this->str[lenght] = '\0';
}

void Mystring::input_obj()
{
    this->str = new char[255];
    cin.getline(this->str, 256);
    this->lenght = strlen(this->str);
}

Mystring& Mystring::operator=(Mystring& obj)
{
    if (this->str!=nullptr)delete[] this->str;
    this->lenght = strlen(obj.str);
    this->str = new char[lenght + 1];
    for (int i = 0; i < lenght; i++)this->str[i] = obj.str[i];
    this->str[lenght] = '\0';
    return *this;
}

Mystring Mystring::operator+(Mystring& obj)
{
    Mystring a;
    a.lenght = this->lenght + obj.lenght;
    a.str = new char[a.lenght + 2];
    int i = 0;
    for (; i < this->lenght; i++)a.str[i] = this->str[i];
    a.str[i] = ' ';
    ++i;
    for (int j = 0; j < obj.lenght; j++, i++)a.str[i] = obj.str[j];
    a.str[a.lenght+1]='\0';
    return a;
}

char& Mystring::operator[](int index)
{
    if (index>=0&&index<this->lenght) return this->str[index];
    else return this->str[0];
}

Mystring Mystring::operator-(Mystring& obj)
{
    Mystring a;
    bool flag = false;
    int start = 0, counter = 0;
    a.lenght = this->lenght;
    a.str = new char[a.lenght + 1];
    if (this->lenght>obj.lenght)
    {
        for (int i = 0; i < this->lenght; i++)
        {
            if (this->str[i]==obj.str[0])
            {
                for (int j1 = i, j2 = 0; j1 < this->lenght || j2 < obj.lenght; j1++, j2++)
                    if (this->str[j1] == obj.str[j2])counter++;
            }
            if (counter==obj.lenght)
            {
                flag = true;
                start = i;
                break;
            }
            else counter = 0;
        }
        if (flag)
        {
            for (int i = 0 , j=0; i < this->lenght; i++)
            {
                if ((i >= start) && (i <= (obj.lenght + start)))continue;
                a.str[j] = this->str[i];
                j++;
            }
            a.lenght = this->lenght - counter - 1;
            a.str[a.lenght] = '\0';
        }
        else
        {
            for (int i = 0; i < this->lenght; i++)
                a.str[i] = this->str[i];
            a.lenght = this->lenght;
            a.str[a.lenght] = '\0';
        }
    }
    else
    {
        for (int i = 0; i < this->lenght; i++)
            a.str[i] = this->str[i];
        a.lenght = this->lenght;
        a.str[a.lenght] = '\0';
    }
    return a;
}

Mystring Mystring::operator()(int start , int end)
{
    Mystring a;
    a.lenght = this->lenght;
    a.str = new char[lenght + 1];
    int counter = 0;
    for (int i = 0, j = 0; i<this->lenght; i++)
    {
        if (i >= (start - 1) && i < end)continue;
        a.str[j] = this->str[i];
        j++;
        counter++;
    }
    a.str[counter] = '\0';
    return a;
}

bool Mystring::operator<(Mystring& obj)
{
    return this->lenght < obj.lenght;
}

bool Mystring::operator>(Mystring& obj)
{
    return this->lenght > obj.lenght;
}

void Mystring::print()
{
    cout << str<<endl<<endl;
}

int Mystring::get_lenght()
{
    return this->lenght;
}

Mystring Mystring::set_str(char* str)
{
    this->str = new char[200];
    int i;
    for (i=0;str[i]!='\0';i++)
    {
        this->str[i] = str[i];
    }
    this->str[i] = '\0';
    this->lenght = strlen(str);
    return *this;
}

Mystring::~Mystring()
{
    cout << "Object has been DELETE with address:  " << this << endl << endl;
    delete[] str;
    str = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Mystring& obj)
{
    os << "your str: " << obj.str<<endl;
    return os;
}

std::istream& operator >> (std::istream& in, Mystring& obj)
{
    char* str;
    str = new char[256];
    in.getline(str, 256);
    obj.str = str;
    int lenght = strlen(obj.str);
    obj.lenght = lenght;
    return in;
}

void plus1()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    Mystring b;
    cout << "enter str:";
    b.input_obj();
    Mystring c = a + b+ a + b+ a + b;
    cout << "result:";
    c.print();
}

void ravno()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    Mystring b;
    b = a;
    cout << "result:";
    b.print();
}

void scobki()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    int index;
    cout << "enter index:";
    cin >> index;
    char sumbol;
    cout << "enter sumbol:";
    cin >> sumbol;
    a[index] = sumbol;
    cout << "result:";
    a.print();
}

void minus1()
{

    Mystring a;
    cout << "enter str:";
    a.input_obj();
    Mystring b;
    cout << "enter str:";
    b.input_obj();
    Mystring c = a - b;
    cout << "result:";
    c.print();
}

void scobki2()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    int end, start;
    cout << "enter start:";
    cin >> start;
    cout << "enter end:";
    cin >> end;
    Mystring b = a(start, end);
    cout << "result:";
    b.print();
}

void menche()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    Mystring b;
    cout << "enter str:";
    b.input_obj();
    if (a < b)cout << "TRUE"<<endl;
    else cout<< "FALSE"<<endl;
}

void bolche()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    Mystring b;
    cout << "enter str:";
    b.input_obj();
    if (a > b)cout << "TRUE" << endl;
    else cout << "FALSE" << endl;
}

void vivod()
{
    Mystring a;
    cout << "enter str:";
    a.input_obj();
    cout << a;
}

void vvod()
{
    Mystring a;
    cout << "enter str:";
    cin >> a;
    a.print();
}

void menu()
{
    cout<<"|----------------------------|\n"
        "|1. +                        |\n"
        "|2. =                        |\n"
        "|3. []                       |\n"
        "|4. -                        |\n"
        "|5. ()                       |\n"
        "|6. <                        |\n"
        "|7. >                        |\n"
        "|8. <<                       |\n"
        "|9. >>                       |\n"
        "|10. EXIT                    |\n"
        "|----------------------------|\n";
}
