#pragma once
//Algorithm.h
#pragma once
#include "TEXTFILE.h"
template <typename T>
class Algorithm
{
public:
    Algorithm();
    ~Algorithm();
    void SearchForTheMostPopularServiceAmongIndividuals();
    void SearchForTheMostPopularServiceAmongLegalEntities();
    RingList<T> Search(Iterator<T> cur , T obj);
    void sort(Iterator<T> cur, int index);
    void TransferOfFundsToTheAccount(double sum_for_perevod);
};