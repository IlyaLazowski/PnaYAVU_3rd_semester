#pragma once
#include"TXTFILE.h"

template<typename T>
void TEXTFILE::WriteToFile(const std::string& filename, RingList<T>& list)
{
    std::ofstream ofs(filename, std::ios::app);
    if (list.Begin() == nullptr) cout << "������ �����!" << endl;
    else
    {
        RingNode<T>* temp = list.Begin();
        do {
            ofs << temp->data;
            temp = temp->next;
        } while (temp != list.Begin());
        cout << endl;
    }
    ofs.close();
}

template<typename T>
void TEXTFILE::ReadFromFile(const std::string& filename, RingList<T>& list)
{
    list.RemoveAll();
    system("cls");
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "�� ������� ������� ����: " << filename << std::endl;
        return;
    }
    T obj{};
    while (file >> obj)
    {
        list.Push(obj);

    }
    file.close();
}

template<typename T>
int TEXTFILE::CheckCount(const std::string& filename)
{
    int i = 0;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "�� ������� ������� ����: " << filename << std::endl;
        return 0;
    }
    T obj{};
    while (file >>= obj)
    {
        i++;
    }
    return i;
}

inline void TEXTFILE::ClearFile(string& filename)
{
    ofstream ofs(filename, ios::out, ios::trunc);
    ofs.close();
}