//Algorithm.cpp
#pragma once
#include"Algorithm.h"
template <typename T>
Algorithm<T>::Algorithm() {}
template <typename T>
Algorithm<T>::~Algorithm() {}

template<typename T>
RingList<T> Algorithm<T>::Search(Iterator<T> cur , T obj) //����� �������� �� ���������� ����������
{
    RingList<T> local_list;
    if (cur == nullptr) cout << "������ �����!" << endl;
    else
    {
        Iterator<T> temp = cur;
        do
        {
            if ((*temp) == obj)// ���������� ���������==
            {
                local_list.Push((*temp));
            }
            ++temp;
        } while (temp != cur);
    }
    if (!local_list.Empty())
    {
        (*cur).Cap();
        local_list.Display();//����� ���� ����������� ��������
    }
    else
    {
        cout << "�������� � �������� ����������� �� �������" << endl;
    }
    return local_list;
}

template<typename T>
bool ComparatorForSort(Iterator<T>node1, Iterator<T> node2, int index)  
{
    if (index == 1)return node1 > node2;                       // � �������� �� ���������� ������� , � ������� �� ���������� �����
    if (index == 2)return !(node1 > node2);                    // � �������� �� ���������� ������� , � ������� �� ���������� �����
    if (index == 3)return node1 < node2;                       // � �������� �� ���������� �������� , � ������� �� ���������� ���������� ������
    if (index == 4)return !(node1 < node2);                    // � �������� �� ���������� �������� , � ������� �� ���������� ���������� ������
    return false;
}

template<typename T>
void Algorithm<T>::sort(Iterator<T> cur , int index)
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
        Iterator<T> node = it;
        Iterator<T> next_node = it; ++next_node;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ComparatorForSort(node, next_node, index))
            {
                std::swap(*node, *next_node);
                swapped = true; 
            }
            node = next_node;
            ++next_node;
        }
        if (!swapped) break; // ���� � ���� ������� �� ���� ��������� �� ����� ������, ������ ��� ������������
    }
}

template<typename T>
RingList<T>GettingUserDataFromFile() //��������� ������� ��������� ������ �� ����� � ����
{
    TEXTFILE f;
    RingList<T> list;
    std::string path = file_name<T>();
    f.ReadFromFile(path, list);
    return list;
}

template<typename T>
void ClearingInformationAboutAllClientsFromFiles()  // ��������� ������� ������� ������ �� �����
{
    TEXTFILE f;
    string path = file_name<T>();
    f.ClearFile(path);
}

template<typename T>
void WritingUpdatedCustomerInformationToFile(RingList<T> list) // ��������� ������� ������ ������ � �����
{
    TEXTFILE f;
    string path = file_name<T>();
    f.WriteToFile(path, list);
}

inline bool CheckingThePersonalAccountOfOrdinaryCustomers(RingList<Klient>& list, char card[], double sum_for_perevod) // ����� ����� ����� ������� ��������
{
    auto current = list.GetCurrent();
    auto temp = current;
    bool flag = false;
    if (current == nullptr) flag = false;
    else
    {
        do
        {
            if (strcmp(temp->data.GetPersonalAccount(), card) == 0)
            {
                flag = true;
                temp->data.SetBalance(temp->data.GetBalance() + sum_for_perevod);
                break;
            }
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }
    return flag;
}

inline bool CheckingAccountsWithIndividuals(RingList<Fizliz>& list, char card[], double sum_for_perevod)
{
    bool flag = false;
    auto current = list.GetCurrent();
    auto temp = current;
    if (current == nullptr) flag = false;
    else
    {
        do
        {
            if (strcmp(temp->data.GetPersonalAccount(), card) == 0)// ����� ���������� ����� ������ �����
            {
                flag = true;
                temp->data.SetBalance(temp->data.GetBalance() + sum_for_perevod);
                break;
            }
            for (int i = 0; i < temp->data.GetKredituSize(); i++)
            {
                if (strcmp(temp->data.GetKreditu()[i]->GetAccountNumber(), card) == 0)//����� ���������� �� ������ �������
                {
                    flag = true;
                    if (temp->data.GetKreditu()[i]->GetSum() < sum_for_perevod) temp->data.DeletionUnderIndex(i);
                    else temp->data.GetKreditu()[i]->SetSum(temp->data.GetKreditu()[i]->GetSum() - sum_for_perevod);
                    break;
                }
            }
            for (int i = 0; i < temp->data.GetVkladuSize(); i++)
            {
                if (strcmp(temp->data.GetVkladu()[i]->GetAccountNumber(), card) == 0) // ����� ���������� �� ������ ������
                {
                    flag = true;
                    if (temp->data.GetVkladu()[i]->GetPermission()) temp->data.GetVkladu()[i]->SetSum(temp->data.GetVkladu()[i]->GetSum() + sum_for_perevod);
                    else return false;
                    break;
                }
            }
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }
    return flag;
}

inline bool CheckingAccountsWithLegalEntities(RingList<Yrliz>& list, char card[], double sum_for_perevod)
{
    bool flag = false;
    auto current = list.GetCurrent();
    auto temp = current;
    if (current == nullptr) flag = false;
    else
    {
        do
        {
            if (strcmp(temp->data.GetPersonalAccount(), card) == 0)// ����� ���������� ����� ������ �����
            {
                flag = true;
                temp->data.SetBalance(temp->data.GetBalance() + sum_for_perevod);
                break;
            }
            for (int i = 0; i < temp->data.GetZaimuSize(); i++)
            {
                if (strcmp(temp->data.GetZaimu()[i]->GetAccountNumber(), card) == 0)//����� ���������� �� ������ �����
                {
                    flag = true;
                    if (temp->data.GetZaimu()[i]->GetSum() < sum_for_perevod) temp->data.DeletionUnderIndex(i);
                    else temp->data.GetZaimu()[i]->SetSum(temp->data.GetZaimu()[i]->GetSum() - sum_for_perevod);
                    break;
                }
            }
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }
    return flag;
}

template<typename T>
void Algorithm<T>::TransferOfFundsToTheAccount(double sum_for_perevod)
{
    char card[20];
    RingList<Klient> klientu = GettingUserDataFromFile<Klient>();
    RingList<Fizliz> fizliza = GettingUserDataFromFile<Fizliz>();
    RingList<Yrliz> yrliza = GettingUserDataFromFile<Yrliz>();
    cout << "������� ����: ";
    cin.getline(card, 20);
    bool found = CheckingThePersonalAccountOfOrdinaryCustomers(klientu, card, sum_for_perevod);//������� �� ����� ������ �� ����
    if (!found) found = CheckingAccountsWithIndividuals(fizliza, card, sum_for_perevod);
    if (!found) found = CheckingAccountsWithLegalEntities(yrliza, card, sum_for_perevod);
    if (found)
    {
        ClearingInformationAboutAllClientsFromFiles<Klient>();
        ClearingInformationAboutAllClientsFromFiles<Fizliz>();
        ClearingInformationAboutAllClientsFromFiles<Yrliz>();
        WritingUpdatedCustomerInformationToFile<Klient>(klientu);
        WritingUpdatedCustomerInformationToFile<Fizliz>(fizliza);
        WritingUpdatedCustomerInformationToFile<Yrliz>(yrliza);
    }
    else cout << "����� ���� �� ������ ��� ������� �� ���� ����������" << endl;
}

template<typename T>
void Algorithm<T>::SearchForTheMostPopularServiceAmongIndividuals()
{
    int number = 0;
    vector<T*> local_uslug;
    vector<int> kol_vo;
    RingList<Fizliz> klientu = GettingUserDataFromFile<Fizliz>();
    cout << "1. ����� ������ ����������� ������\n";
    cout << "2. ����� ������ ����������� �������\n";
    int choise = CreateInt(1, 2);
    switch (choise)
    {
    case 1:
    {
        Vklad obj , most_popular;
        string path = file_name<Vklad>();
        ifstream ifs(path, ifstream::in);
        if (!ifs)
        {
            cout << "�� ������� ������� ����: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Fizliz> it = klientu.GetCurrent();//�������������� ��������� ��� ����� �� ������
            Iterator<Fizliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "������ �����!" << endl;
            else
            {
                do
                {
                    for (int i = 0; i < (*temp).GetVkladuSize(); i++)
                        if ((*(*temp).GetVkladu()[i]) == obj)kol_vo[number]++;// ��� ���������� �������������� ������
                    ++temp;
                } while (temp != it);
            }
            if (number!=0)
            {
                if (kol_vo[number]>kol_vo[number-1])
                {
                    most_popular = obj;
                }
            }
            else
            {
                most_popular = obj;
            }
            number++;

        };
        most_popular.Cap();
        most_popular.Output(0);
        ifs.close();
    }
    break;
    case 2:
    {
        Kredit obj, most_popular;
        string path = file_name<Kredit>();
        ifstream ifs(path, ifstream::in);
        if (!ifs)
        {
            cout << "�� ������� ������� ����: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Fizliz> it = klientu.GetCurrent();
            Iterator<Fizliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "������ �����!" << endl;
            else
            {
                do
                {
                    for (int i = 0; i < (*temp).GetKredituSize(); i++)
                        if ((*(*temp).GetKreditu()[i]) == obj)kol_vo[number]++;
                    ++temp;
                } while (temp != it);
            }
            if (number != 0)
            {
                if (kol_vo[number] > kol_vo[number - 1])
                {
                    most_popular = obj;
                }
            }
            else
            {
                most_popular = obj;
            }
            number++;

        };
        most_popular.Cap();
        most_popular.Output(0);
        ifs.close();
    }
    break;
    }
}

template<typename T>
void Algorithm<T>::SearchForTheMostPopularServiceAmongLegalEntities()
{
    int number = 0;
    vector<T*> local_uslug;
    vector<int> kol_vo;
    RingList<Yrliz> klientu = GettingUserDataFromFile<Yrliz>();
    cout << "1. ����� ������ ����������� �����\n";
    cout << "2. ����� ������ ����������� ����������\n";
    int choise = CreateInt(1, 2);
    switch (choise)
    {
    case 1:
    {
        Zaim obj, most_popular;
        string path = file_name<Zaim>();
        ifstream ifs(path, ifstream::in);
        if (!ifs)
        {
            cout << "�� ������� ������� ����: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Yrliz> it = klientu.GetCurrent();
            Iterator<Yrliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "������ �����!" << endl;
            else
            {
                do
                {
                    for (int i = 0; i < (*temp).GetZaimuSize(); i++)
                        if ((*(*temp).GetZaimu()[i]) == obj)kol_vo[number]++;
                    ++temp;
                } while (temp != it);
            }
            if (number != 0)
            {
                if (kol_vo[number] > kol_vo[number - 1])
                {
                    most_popular = obj;
                }
            }
            else
            {
                most_popular = obj;
            }
            number++;

        };
        most_popular.Cap();
        most_popular.Output(0);
        ifs.close();
    }
    break;
    case 2:
    {
        Akvair obj, most_popular;
        string path = file_name<Akvair>();
        ifstream ifs(path, ifstream::in);
        if (!ifs)
        {
            cout << "�� ������� ������� ����: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Yrliz> it = klientu.GetCurrent();
            Iterator<Yrliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "������ �����!" << endl;
            else
            {
                do
                {
                    for (int i = 0; i < (*temp).GetAkvairuSize(); i++)
                        if ((*(*temp).GetAkvairu()[i]) == obj)kol_vo[number]++;
                    ++temp;
                } while (temp != it);
            }
            if (number != 0)
            {
                if (kol_vo[number] > kol_vo[number - 1])
                {
                    most_popular = obj;
                }
            }
            else
            {
                most_popular = obj;
            }
            number++;

        };
        most_popular.Cap();
        most_popular.Output(0);
        ifs.close();
    }
    break;
    }
}