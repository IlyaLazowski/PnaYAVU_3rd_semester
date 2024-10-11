#pragma once
#include"RingList.h"

template<typename T>
RingList<T>::RingList()
{
    this->current = nullptr;
}

template<typename T>
RingNode<T>* RingList<T>::Begin() const {
    return this->current;
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
            cout << temp->data << endl;
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

template<typename T>
int RingList<T>::GetSize() {
    int i = 0;
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = this->current;
        do {
            i++;
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
    }
    return i;
}

template<typename T>
void RingList<T>::Poisk()
{
    T obj;
    char str[32], data[11];
    cout << "Варианты поиска:\n";
    cout << "1.  По фамилии\n";
    cout << "2.  По имени\n";
    cout << "3.  По дате рождения\n";
    cout << "4.  По фамилии и имени\n";
    cout << "5.  По фамилии и дате рождения\n";
    cout << "6.  По имени и дате рождения\n";
    cout << "7.  По имени , дате рождения и фамилии\n";
    cout << "8.  Ваш выбор :";
    int choise = CreateInt(1, 9);
    switch (choise)
    {
    case 1:
    {
        CreateName(str, "Введите фамилию: ");
        obj.SetSurname(str);
    }
    break;
    case 2:
    {
        CreateName(str, "Введите имя: ");
        obj.SetName(str);
    }
    break;
    case 3:
    {
        CreateDate(data);
        obj.SetDataOfBirdth(data);

    }
    break;
    case 4:
    {
        CreateName(str, "Введите имя: ");
        obj.SetName(str);
        CreateName(str, "Введите фамилию: ");
        obj.SetSurname(str);
    }
    break;
    case 5:
    {
        CreateName(str, "Введите фамилию: ");
        obj.SetSurname(str);
        CreateDate(data);
        obj.SetDataOfBirdth(data);
    }
    break;
    case 6:
    {
        CreateName(str, "Введите имя: ");
        obj.SetName(str);
        CreateDate(data);
        obj.SetDataOfBirdth(data);
    }
    break;
    case 7:
    {
        CreateName(str, "Введите имя: ");
        obj.SetName(str);
        CreateName(str, "Введите фамилию: ");
        obj.SetSurname(str);
        CreateDate(data);
        obj.SetDataOfBirdth(data);
    }
    break;
    }
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = this->current;
        do
        {
            if (temp->data==obj)
            {
            cout << temp->data << endl;
            }
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
    }
}