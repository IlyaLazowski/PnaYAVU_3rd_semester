#pragma once
#include "RingList.cpp"

template <typename T>
class Algorithm
{
public:
    Algorithm();
    ~Algorithm();
    void sort(Iterator<T> cur);
    RingList<T> poisk(Iterator<T> cur, T obj);
};
