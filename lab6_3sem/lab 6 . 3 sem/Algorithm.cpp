#pragma once 
#include"Algorithm.h"

template <typename T>
Algorithm<T>::Algorithm() {}

template <typename T>
Algorithm<T>::~Algorithm() {}

template<typename T>
void Algorithm<T>::sort(Iterator<T> cur)
{
    Iterator<T> it = cur;
    Iterator<T> temp = cur;
    int size = 0;
    if (it == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        do
        {
            size++;
            temp = ++temp;
        } while (temp != it);
        cout << endl;
    }
    if (cur == nullptr || ++cur == it)return; // Если кольцо пустое или содержит только один элемент, ничего не делаем  
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        Iterator<T> node = it;//=it
        Iterator<T> next_node = ++it;//=++it
        for (int j = 0; j < size - i - 1; j++)
        {
            if (node > next_node)
            {
                std::swap((*node), (*next_node));
                swapped = true;
            }
            node = next_node;
            next_node = ++next_node;
        }
        if (!swapped) break; // Если в этом проходе не было выполнено ни одной замены, список уже отсортирован
    }
}

template<typename T>
RingList<T> Algorithm<T>::poisk(Iterator<T> cur, T obj)
{
    RingList<T> local_list;
    if (cur == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        Iterator<T> temp = cur;
        do
        {
            if ((*temp) == obj)
            {
                local_list.Push((*temp));
            }
            ++temp;
        } while (temp != cur);
    }
    if (!local_list.Empty())
    {
        local_list.Display();
    }
    else
    {
        cout << "Элементы с даннымми параметрами не найдены" << endl;
    }
    return local_list;
}
