#pragma once
#include"RingList.cpp"

class BINFILE
{
public:
    BINFILE() {};
    ~BINFILE() {};
    void ClearFile(string filename)
    {
        filename += ".bin";
        fstream fs(filename, ios::out, ios::trunc);
        fs.close();
    }
    template<typename T>
    void WriteToFile(string filename, RingList<T>& list);
    template<typename T>
    void ReadFromFile(string filename, RingList<T>& list);
    template<typename T>
    int CheckCount(string filename);
};

template<typename T>
void BINFILE::WriteToFile(string filename, RingList<T>& list)
{
    std::fstream fs;
    filename += ".bin";
    fs.open(filename, std::ios::out | std::ios::binary | std::ios::app);
    if (list.Begin() == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = list.Begin();
        do 
        {
            fs << temp->data;
            temp = temp->next;
        } while (temp != list.Begin());
        cout << endl;
    }
    fs.close();
}

template<typename T>
void BINFILE::ReadFromFile(string filename, RingList<T>& list)
{
    list.RemoveAll();
    system("cls");
    filename += ".bin";
    fstream fs;
    fs.open(filename, std::ios::in | std::ios::binary);
    if (!fs.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }
    T obj{};
    while (fs >> obj)
    {
        list.Push(obj);
    }
    fs.close();
}

template<typename T>
int BINFILE::CheckCount(string filename)
{
    int i = 0;
    filename += ".bin";
    std::fstream file(filename , std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 0;
    }
    T obj{};
    while (file >>= obj)
    {
        i++;
    }
    file.close();
    return i;
}