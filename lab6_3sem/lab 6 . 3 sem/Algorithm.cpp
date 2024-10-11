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
    if (it == nullptr) cout << "������ �����!" << endl;
    else
    {
        do
        {
            size++;
            temp = ++temp;
        } while (temp != it);
        cout << endl;
    }
    if (cur == nullptr || ++cur == it)return; // ���� ������ ������ ��� �������� ������ ���� �������, ������ �� ������  
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
        if (!swapped) break; // ���� � ���� ������� �� ���� ��������� �� ����� ������, ������ ��� ������������
    }
}

template<typename T>
RingList<T> Algorithm<T>::poisk(Iterator<T> cur, T obj)
{
    RingList<T> local_list;
    if (cur == nullptr) cout << "������ �����!" << endl;
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
        cout << "�������� � �������� ����������� �� �������" << endl;
    }
    return local_list;
}
