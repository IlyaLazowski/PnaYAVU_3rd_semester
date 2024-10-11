#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>  // для функций SetConsoleCP и SetConsoleOutputCP
#include <locale.h>   // для функции setlocale
using namespace std;

template <typename T>
struct RingNode
{
    T data{};
    RingNode<T>* prev{};
    RingNode<T>* next{};
};


template <typename T>
class RingList
{
    RingNode<T>* current;
public:
    RingList();
    void Push(T data);
    void RemoveCurrent();
    void Display();
    bool Empty();
    T FindMin();
    T FindMax();
    void Remove(T data);
    bool Searche(T x);
    RingList(const RingList& other);
    void RemoveAll();
    ~RingList();
};

template<typename T>
RingList<T>::RingList()
{
    this->current = nullptr;
}

template<typename T>
void RingList<T>::Push(T data) {
    RingNode<T>* tmp = new RingNode<T>;
    tmp->data = data;
    if (this->current == NULL) {
        this->current = tmp;
        tmp->next = tmp->prev = tmp;
    }
    else {
        tmp->next = this->current->next;
        tmp->prev = this->current;
        this->current->next->prev = tmp;
        this->current->next = tmp;
        this->current = tmp;
    }
}

template<typename T>
void RingList<T>::RemoveCurrent() {
    RingNode<T>* after_target = nullptr;
    T retval;
    if (this->current == nullptr) cout << "Удаление невозможно , кольцо пустое!" << endl;
    else
    {
    if (this->current->next == this->current) {
        retval = this->current->data;
        delete this->current;
        this->current = nullptr;
    }
    else {
        after_target = this->current->next;
        this->current->prev->next = after_target;
        after_target->prev = this->current->prev;
        retval = this->current->data;
        delete this->current;
        this->current = after_target->prev;
    }
    cout << "Удалён элемент со значением: " << retval << endl;
    }
}

template<typename T>
void RingList<T>::Display() {
    if (this->current==nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
    RingNode<T>* temp = this->current;
    do {
        cout << temp->data << setw(2);
        temp = temp->next;
    } while (temp != this->current);
    cout << endl;
    }
}

template<typename T>
bool RingList<T>::Empty()
{
    if (this->current == nullptr)return true;
    else return false;
}

template<typename T>
T RingList<T>::FindMin()
{
    if (this->current == nullptr)return 0;
    RingNode<T>* temp = this->current;
    T min = temp->data;
    do {
        if (min > temp->data)min = temp->data;
        temp = temp->next;
    } while (temp != this->current);
    return min;
}

template<typename T>
T RingList<T>::FindMax() {
    if (this->current == nullptr)return 0;
    RingNode<T>* temp = this->current;
    T max = temp->data;
    do {
        if (max < temp->data) max = temp->data;
        temp = temp->next;
    } while (temp != this->current);
    return max;
}

template<typename T>
void RingList<T>::Remove(T key)
{
    RingNode<T>* current = this->current;
    if (this->current==nullptr)
    {
        cout << "Кольцо пустое"<<endl;
        return;
    }
    else
    {
    while (current->data != key) {
        if (current->next == this->current) {
            cout << "Данный элемент не найден" << endl;
            return;
        }
        current = current->next;
    }
    if (current->next != current) {
        current->next->prev = current->prev;
        current->prev->next = current->next;
        if (current == this->current)
            this->current = this->current->next;
    }
    else {
        this->current = nullptr;
    }
    delete current;
    }
    cout << "Элемент успешно удален!" << endl;
}

template<typename T>
bool RingList<T>::Searche(T x)
{
    if (this->current==nullptr) return false;
    else
    {
    RingNode<T>* temp = this->current;
    do {
        if (temp->data == x) return true;

        temp = temp->next;
    } while (temp != this->current);
    cout << endl;
    return false;
    }
}

template<typename T>
RingList<T>::RingList(const RingList& other) : current(nullptr)
{
    RingNode<T>* current = other.current;
    do {
        Push(current->data);
        current = current->next;
    } while (current != other.current);
}

template<typename T>
void RingList<T>::RemoveAll()
{
    if (this->current != nullptr) {
        if (this->current->next == this->current) {
            delete this->current;
            this->current = nullptr;
            cout << "Кольцо успешно очищено!" << endl;
        }
        else
        {
        RingNode<T>* temp = this->current;
        do {
            RingNode<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != this->current);
        this->current = nullptr;
        cout << "Кольцо пусто" << endl;
        }
    }
    else
    {
        cout << "Кольцо пусто" << endl;
    }


           
}

template<typename T>
RingList<T>::~RingList() {
    if (this->current != nullptr) {
        RingNode<T>* temp = this->current;
        do {
            RingNode<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != this->current);
    }
}

template <>
string RingList<string>::FindMax() {
    if (this->current == nullptr)return "Кольцо пустое";
    RingNode<string>* temp = this->current;
    string max = temp->data;
    do {
        if (max.length() < temp->data.length()) max = temp->data;
        temp = temp->next;
    } while (temp != this->current);
    return max;
}

template <>
string RingList<string>::FindMin() {
    if (this->current == nullptr)return "Кольцо пустое";
    RingNode<string>* temp = this->current;
    string min = temp->data;
    do {
        if (min.length() > temp->data.length()) min = temp->data;
        temp = temp->next;
    } while (temp != this->current);
    return min;
}
