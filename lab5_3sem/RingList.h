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
    RingList(const RingList& other);
    ~RingList();
    T& FindBuSurname(bool& flag);
    void FindDataOfBirdthMin();
    void FindDataOfBirdthMax();
    void Push(T data);
    void RemoveCurrent();
    void Display();
    bool Empty();
    void RemoveAll();
};

template<typename T>
RingList<T>::RingList()
{
    this->current = nullptr;
}

template<typename T>
void RingList<T>::Push(T data)
{
    RingNode<T>* tmp = new RingNode<T>;
    tmp->data = data;
    if (this->current == NULL)
    {
        this->current = tmp;
        tmp->next = tmp->prev = tmp;
    }
    else
    {
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
        if (this->current->next == this->current)
        {
            retval = this->current->data;
            delete this->current;
            this->current = nullptr;
        }
        else 
        {
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
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = this->current;
        do
        {
            cout << temp->data <<endl;
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
T& RingList<T>::FindBuSurname(bool& flag)
{
    char str[32];
    CreateName(str, "Введите фамилию: ");
    if (this->current == nullptr) flag = false;
    else
    {
    auto temp = this->current;
        do
        {
            if (strcmp(temp->data.GetSurname(), str) == 0)
            {
                flag = true;
                return temp->data;
            }
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
        flag = false;
    }
    cout << "Элемент не найден!";
    return this->current->data;
}

template<typename T>
void RingList<T>::FindDataOfBirdthMin()
{
    if (this->current == nullptr)
    {
        cout << "Кольцо пусто"<<endl;
        return;
    }
    else
    {
        T search = this->current->data;
        auto temp = this->current;
        do
        {
            char* str1 = temp->data.GetDataOfBirdth();
            char* str2 = temp->next->data.GetDataOfBirdth();
            if (compareBirthDates(str1, str2) == -1) search = temp->next->data;
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
        search.Cap();
        cout << search<<endl;
    }
}

template<typename T>
void RingList<T>::FindDataOfBirdthMax()
{
    if (this->current == nullptr)
    {
        cout << "Кольцо пусто" << endl;
        return;
    }
    else
    {
    T search = this->current->data;
        auto temp = this->current;
        do
        {
            char* str1 = temp->data.GetDataOfBirdth();
            char* str2 = temp->next->data.GetDataOfBirdth();
            if (compareBirthDates(str1, str2) == 1) search = temp->next->data;
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
        search.Cap();
        cout << search << endl;
    }
}

template<typename T>
RingList<T>::RingList(const RingList& other) : current(nullptr)
{
    RingNode<T>* current = other.current;
    do
    {
        Push(current->data);
        current = current->next;
    } while (current != other.current);
}

template<typename T>
void RingList<T>::RemoveAll()
{
    if (this->current != nullptr)
    {
        if (this->current->next == this->current) 
        {
            delete this->current;
            this->current = nullptr;
            cout << "Кольцо успешно очищено!" << endl;
        }
        else
        {
            RingNode<T>* temp = this->current;
            do 
            {
                RingNode<T>* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } while (temp != this->current);
            this->current = nullptr;
            cout << "Кольцо пусто" << endl;
        }
    }
    else cout << "Кольцо пусто" << endl;
}

template<typename T>
RingList<T>::~RingList() {
    if (this->current != nullptr) 
    {
        RingNode<T>* temp = this->current;
        do
        {
            RingNode<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != this->current);
    }
}
