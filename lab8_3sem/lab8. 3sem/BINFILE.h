#pragma once
#include"RingList.cpp"
#include"fname.h"

class BINFILE
{
public:
    BINFILE() {};
    ~BINFILE() {};
    template<typename T>
    void WriteToFile(string filename, RingList<T>& list);
    template<typename T>
    void ReadFromFile(string filename, RingList<T>& list);
    template<typename T>
    int CheckCount(const std::string filename);
    void ClearFile(string filename);
};