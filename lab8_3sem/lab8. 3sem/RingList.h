#pragma once
#include"TeacherUnionMember.h"
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
    RingNode<T>* Begin() const;
    RingList(const RingList& other);
    template <typename T>
    friend class Iterator;
    ~RingList();
    int GetSize();
    void Poisk();
    void Push(T data);
    void RemoveCurrent();
    void Display();
    bool Empty();
    void RemoveAll();
};

template<typename T>
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
