//Algorithm.cpp
#pragma once
#include"Algorithm.h"
template <typename T>
Algorithm<T>::Algorithm() {}
template <typename T>
Algorithm<T>::~Algorithm() {}

template<typename T>
RingList<T> Algorithm<T>::Search(Iterator<T> cur , T obj) //поиск элемента по нескольким параметрам
{
    RingList<T> local_list;
    if (cur == nullptr) cout << "Кольцо пусто!" << endl;
    else
    {
        Iterator<T> temp = cur;
        do
        {
            if ((*temp) == obj)// перегрузка оператора==
            {
                local_list.Push((*temp));
            }
            ++temp;
        } while (temp != cur);
    }
    if (!local_list.Empty())
    {
        (*cur).Cap();
        local_list.Display();//вывод всех совподающих объектов
    }
    else
    {
        cout << "Элементы с даннымми параметрами не найдены" << endl;
    }
    return local_list;
}

template<typename T>
bool ComparatorForSort(Iterator<T>node1, Iterator<T> node2, int index)  
{
    if (index == 1)return node1 > node2;                       // в клиентах по увеличению баланса , в услугах по увеличению суммы
    if (index == 2)return !(node1 > node2);                    // в клиентах по уменьшению баланса , в услугах по уменьшению сумму
    if (index == 3)return node1 < node2;                       // в клиентах по увеличению зарплаты , в услугах по увеличению процентной ставки
    if (index == 4)return !(node1 < node2);                    // в клиентах по уменьшению зарплаты , в услугах по уменьшению процентной ставки
    return false;
}

template<typename T>
void Algorithm<T>::sort(Iterator<T> cur , int index)
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
        if (!swapped) break; // Если в этом проходе не было выполнено ни одной замены, список уже отсортирован
    }
}

template<typename T>
RingList<T>GettingUserDataFromFile() //шаблонная функция занесения данных из файла в лист
{
    TEXTFILE f;
    RingList<T> list;
    std::string path = file_name<T>();
    f.ReadFromFile(path, list);
    return list;
}

template<typename T>
void ClearingInformationAboutAllClientsFromFiles()  // шаблонная функция очистки данных из файла
{
    TEXTFILE f;
    string path = file_name<T>();
    f.ClearFile(path);
}

template<typename T>
void WritingUpdatedCustomerInformationToFile(RingList<T> list) // шаблонная функция записи данных в файла
{
    TEXTFILE f;
    string path = file_name<T>();
    f.WriteToFile(path, list);
}

inline bool CheckingThePersonalAccountOfOrdinaryCustomers(RingList<Klient>& list, char card[], double sum_for_perevod) // поиск счета среди обычных клиентов
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
            if (strcmp(temp->data.GetPersonalAccount(), card) == 0)// поиск совпадения среди личной карты
            {
                flag = true;
                temp->data.SetBalance(temp->data.GetBalance() + sum_for_perevod);
                break;
            }
            for (int i = 0; i < temp->data.GetKredituSize(); i++)
            {
                if (strcmp(temp->data.GetKreditu()[i]->GetAccountNumber(), card) == 0)//поиск совпадения со счетом кредита
                {
                    flag = true;
                    if (temp->data.GetKreditu()[i]->GetSum() < sum_for_perevod) temp->data.DeletionUnderIndex(i);
                    else temp->data.GetKreditu()[i]->SetSum(temp->data.GetKreditu()[i]->GetSum() - sum_for_perevod);
                    break;
                }
            }
            for (int i = 0; i < temp->data.GetVkladuSize(); i++)
            {
                if (strcmp(temp->data.GetVkladu()[i]->GetAccountNumber(), card) == 0) // поиск совпадения со счетом вклада
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
            if (strcmp(temp->data.GetPersonalAccount(), card) == 0)// поиск совпадения среди личной карты
            {
                flag = true;
                temp->data.SetBalance(temp->data.GetBalance() + sum_for_perevod);
                break;
            }
            for (int i = 0; i < temp->data.GetZaimuSize(); i++)
            {
                if (strcmp(temp->data.GetZaimu()[i]->GetAccountNumber(), card) == 0)//поиск совпадения со счетом займа
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
    cout << "Введите счёт: ";
    cin.getline(card, 20);
    bool found = CheckingThePersonalAccountOfOrdinaryCustomers(klientu, card, sum_for_perevod);//смотрим по флагу найден ли счет
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
    else cout << "Такой счет не найден или перевод по нему невозможен" << endl;
}

template<typename T>
void Algorithm<T>::SearchForTheMostPopularServiceAmongIndividuals()
{
    int number = 0;
    vector<T*> local_uslug;
    vector<int> kol_vo;
    RingList<Fizliz> klientu = GettingUserDataFromFile<Fizliz>();
    cout << "1. Поиск самого популярного вклада\n";
    cout << "2. Поиск самого популярного кредита\n";
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
            cout << "Не удалось открыть файл: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Fizliz> it = klientu.GetCurrent();//инициализируем итераторы для прога по списку
            Iterator<Fizliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "Кольцо пусто!" << endl;
            else
            {
                do
                {
                    for (int i = 0; i < (*temp).GetVkladuSize(); i++)
                        if ((*(*temp).GetVkladu()[i]) == obj)kol_vo[number]++;// при совпадении инкрементируем вектор
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
            cout << "Не удалось открыть файл: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Fizliz> it = klientu.GetCurrent();
            Iterator<Fizliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "Кольцо пусто!" << endl;
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
    cout << "1. Поиск самого популярного займа\n";
    cout << "2. Поиск самого популярного эквайринга\n";
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
            cout << "Не удалось открыть файл: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Yrliz> it = klientu.GetCurrent();
            Iterator<Yrliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "Кольцо пусто!" << endl;
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
            cout << "Не удалось открыть файл: " << path << endl;
            system("pause");
        }
        while (ifs >> obj)
        {
            kol_vo.push_back(0);
            Iterator<Yrliz> it = klientu.GetCurrent();
            Iterator<Yrliz> temp = klientu.GetCurrent();
            if (it == nullptr) cout << "Кольцо пусто!" << endl;
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