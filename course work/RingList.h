//RingList.h
#pragma once
#include"Fizliz.h"
#include"Yrliz.h"
#include"Vklad.h"
#include"Kredit.h"
#include"Zaim.h"
#include"Akvair.h"
#include"fname.h"

using namespace std;
template <typename T>//структура для реализации узла контейнера
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
    RingList(const RingList& other);
    ~RingList();
    RingList<T>& operator=(const RingList<T>& other);
    template <typename T>
    friend class Iterator;
    RingNode<T>* GetCurrent() const;
    int GetSize();
    T& Authorization(bool& flag);
    T& FindBuPersonalAccount(bool& flag);
    T& SearchForAServiceByIndex(bool& flag);
    void PrintIterator();
    void DeletingServiceByIndex();
    void Push(T data);
    void RemoveCurrent();
    void RemoveBuPersonalAccount(char personal_account[]);
    void Display();
    bool Empty();
    void RemoveAll();
};



template<typename T> // класс итератор для итерацию по контейнеру
class Iterator
{
private:
    RingNode<T>* ptr;
public:
    Iterator()
    {
        ptr = NULL;
    }
    Iterator(RingNode<T>* tmp)
    {
        ptr = tmp;
    }
    Iterator(const Iterator& tmp) : ptr(tmp.ptr) {}
    ~Iterator() { }
    RingNode<T>* operator->()
    {
        return ptr;
    }
    Iterator& operator++()
    {
        if (ptr->next == NULL)
        {
            ptr = NULL;
            return *this;
        }
        ptr = ptr->next;
        return *this;
    }
    Iterator& operator--()
    {
        if (ptr->prev == NULL)
        {
            ptr = NULL;
            return *this;
        }
        ptr = ptr->prev;
        return *this;
    }
    T& operator*()
    {
        return ptr->data;
    }
    RingNode<T>* operator&()
    {
        return ptr;
    }
    bool operator == (const Iterator& tmp)
    {
        if (this->ptr == tmp.ptr)
        {
            return true;
        }
        return false;
    }
    bool operator > (const Iterator& tmp)
    {
        if (this->ptr->data > tmp.ptr->data)//по убыванию года рождения
        {
            return true;
        }
        return false;
    }
    bool operator < (const Iterator& tmp)
    {
        if (this->ptr->data < tmp.ptr->data)//по убыванию длины фамилии
        {
            return true;
        }
        return false;
    }
    bool operator != (const Iterator& tmp)
    {
        if (this->ptr != tmp.ptr)
        {
            return true;
        }
        return false;
    }
    Iterator& operator=(const Iterator& tmp)
    {
        if (this->ptr != tmp.ptr)
        {
            ptr = tmp.ptr;
        }
        return *this;
    }
};
