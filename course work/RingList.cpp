//RingList.cpp
#pragma once
#include"RingList.h"

template<typename T>
RingNode<T>* RingList<T>::GetCurrent() const {
    return this->current;
}

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
inline void RingList<T>::RemoveBuPersonalAccount(char personal_account[])
{
    RingNode<T>* target = this->current;
    RingNode<T>* after_target = nullptr;
    T retval;
    if (target == nullptr) {
        cout << "Удаление невозможно , кольцо пустое!" << endl;
    }
    else
    {
        // Поиск элемента с совпадающим personal_account
        do {
            if (strcmp(target->data.GetPersonalAccount(), personal_account) == 0) {
                break;
            }
            target = target->next;
        } while (target != this->current);

        // Если элемент не найден
        if (strcmp(target->data.GetPersonalAccount(), personal_account) != 0) {
            cout << "Элемент с указанным personal_account не найден!" << endl;
            return;
        }

        // Удаление найденного элемента
        after_target = target->next;
        target->prev->next = after_target;
        after_target->prev = target->prev;
        retval = target->data;
        if (this->current == target) {
            this->current = after_target;
        }
        delete target;
    }
}
template<typename T>
void RingList<T>::Display() {
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = this->current;
        do {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
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
bool RingList<T>::Empty()
{
    if (this->current == nullptr)return true;
    else return false;
}
template<typename T>
T& RingList<T>::FindBuPersonalAccount(bool& flag)
{
    char str[20];
    cout << "Введите номер карточки: ";
    cin.getline(str, 20);
    if (this->current == nullptr) flag = false;
    else
    {
        auto temp = this->current;
        do
        {
            if (strcmp(temp->data.GetPersonalAccount(), str) == 0)
            {
                flag = true;
                return temp->data;
            }
            temp = temp->next;
        } while (temp != this->current);
        cout << endl;
        flag = false;
    }
    RingNode<T>* temp = nullptr;
    return current->data;
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
RingList<T>& RingList<T>::operator=(const RingList<T>& other)
{
    this->RemoveAll();
    Iterator<T> it = other.GetCurrent();
    Iterator<T> temp = it;
    int size = 0;
    if (it != nullptr)

    {
        do
        {
            this->Push((*temp));
            temp = ++temp;
        } while (temp != it);
    //    cout << endl;

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
template<typename T>
T& RingList<T>::Authorization(bool& flag)
{
    cout << "Введите пин-код: ";
    int pin_code = CreateInt(1000, 9999);
    char card[20];
    cout << "Введите номер карточки: ";
    cin.getline(card, 20);
    if (this->current == nullptr) flag = false;
    else
    {
        auto temp = this->current;
        do
        {
            if ((strcmp(temp->data.GetPersonalAccount(), card) == 0) && (temp->data.GetPinCode() == pin_code))
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

    static T default_value{}; // Создание статической переменной, содержащей значение по умолчанию для типа T
    return default_value;


}
template<>
inline void RingList<Akvair>::Display() {
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<Akvair>* temp = this->current;
        int  i = 1;
        do {
            temp->data.Output(i++);
            temp = temp->next;
            cout << endl;
        } while (temp != this->current);
        cout << endl;
    }
}
template<>
inline void RingList<Zaim>::Display() {
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<Zaim>* temp = this->current;
        int  i = 1;
        do {
            temp->data.Output(i++);
            temp = temp->next;
            cout << endl;
        } while (temp != this->current);
        cout << endl;
    }
}
template<>
inline void RingList<Vklad>::Display() {
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<Vklad>* temp = this->current;
        int  i = 1;
        do {
            temp->data.Output(i++);
            temp = temp->next;
            cout << endl;
        } while (temp != this->current);
        cout << endl;
    }
}
template<>
inline void RingList<Kredit>::Display() {
    if (this->current == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<Kredit>* temp = this->current;
        int  i = 1;
        do {
            temp->data.Output(i++);
            temp = temp->next;
            cout << endl;
        } while (temp != this->current);
        cout << endl;
    }
}
template<typename T>
void RingList<T>::PrintIterator()
{

    //Iterator<TYPE> it;
    //for (it = this->Begin(); it != this->End()->next; ++it)
    //{
    //    cout << *it;
    //    cout << endl;
    //}

    Iterator<T> it;
    it = this->current;
    if (it == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        Iterator<T> temp;
        temp = it;   //?   temp=this->current
        //RingNode<T>* temp = this->current;
        do {
            cout << *temp << endl;
            ++temp;
            // temp = temp->next;
        } while (temp != it);
        cout << endl;
    }
}
template<typename T>
T& RingList<T>::SearchForAServiceByIndex(bool& flag)
{
    T obj{};
    int i = 1, choise{};
    string path = file_name<T>();
    obj.Cap();
    ifstream ifs(path, ifstream::in);
    if (!ifs)
    {
        cout << "Не удалось открыть файл: " << path;
        system("pause");
    }
    this->Display();
    if (this->current != nullptr)
    {
        cout << "Выберите услугу: ";
        int choise = CreateInt(1, this->GetSize());
        RingNode<T>* temp = this->current;
        do {
            if (choise == i)
            {
                flag = true;
                return temp->data;
            }
            i++;
            temp = temp->next;
        } while (temp != this->current);
    }
    static T default_value{}; // Создание статической переменной, содержащей значение по умолчанию для типа T
    return default_value;
}
template<typename T>
void RingList<T>::DeletingServiceByIndex()
{
    T obj{};
    vector<T*> local;
    int choise{};
    string path = file_name<T>();
    obj.Cap();
    ifstream ifs(path, ifstream::in);
    if (!ifs)
    {
        cout << "Не удалось открыть файл: " << path;
        system("pause");
    }
    this->Display();
    if (this->current != nullptr)
    {
        cout << "Выберите услугу: ";
        int choise = CreateInt(1, this->GetSize());
        RingNode<T>* temp = this->current;
        do {
            local.push_back(temp->data.clone());
            temp = temp->next;
        } while (temp != this->current);
    }
    this->RemoveAll();
    for (int i = 0; i < local.size(); i++)
    {
        if (i == choise - 1)continue;
        else this->Push(*local[i]);
    }
}
