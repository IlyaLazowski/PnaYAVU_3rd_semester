#pragma once
#include"RingList.cpp"

class TEXTFILE
{
public:
    TEXTFILE() {};
    ~TEXTFILE() {};
    void ClearFile(string filename)
    {
        filename += ".txt";
        ofstream ofs(filename, ios::out, ios::trunc);
        ofs.close();
    }
    template<typename T>
    void WriteToFile(string filename, RingList<T>& list);
    template<typename T>
    void ReadFromFile(string filename, RingList<T>& list);
    template<typename T>
    int CheckCount(string filename);
};

template<typename T>
void TEXTFILE::WriteToFile(string filename, RingList<T>& list)
{
    filename += ".txt";
    OpeningFile(filename);
    std::ofstream ofs(filename, std::ios::app);
    if (list.Begin() == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        RingNode<T>* temp = list.Begin();
        do
        {
            ofs << temp->data;
            //  cout << temp->data << endl;
            temp = temp->next;
        } while (temp != list.Begin());
        cout << endl;
    }
    ofs.close();
}

template<typename T>
void TEXTFILE::ReadFromFile(string filename, RingList<T>& list)
{
    list.RemoveAll();
    system("cls");
    filename += ".txt";
    if(OpeningFile(filename)==0)
    {
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }
    T obj{};
    while (file >> obj)
    {
        list.Push(obj);
    }
    file.close();
    }
}

template<typename T>
int TEXTFILE::CheckCount(string filename)
{
    int i = 0;
    filename += ".txt";
    OpeningFile(filename);
    std::ifstream file(filename);
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
    return i;
}

