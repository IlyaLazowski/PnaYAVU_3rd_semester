//TEXTFILE.h
#pragma once
#include"fname.h"
#include"RingList.cpp"
class TEXTFILE
{
    public:
	TEXTFILE() {};
	~TEXTFILE() {};
    template<typename T>
    void WriteToFile(const std::string& filename, RingList<T>& list);
    template<typename T>
    void ReadFromFile(const std::string& filename , RingList<T>& list);
    template<typename T>
    int CheckCount(const std::string& filename);
    void ClearFile(const std::string& filename);
};

