#pragma once
#include "RingList.h"
#include"TeacherUnionMember.h"

class Menu
{
	int choise;
	int type;
public:
	void start();
	template<typename T>
	void OperatingRingList(RingList<T>& list);
};

void Menu::start()
{
	do
	{
		cout << "Выберите тип элементов\n";
		cout << "1. Teacher\n";
		cout << "2. UnionMember\n";
		cout << "3. TeacherUnionMember\n";
		cout << "4. Выход\n";
		cout << "Выберите действие:";
		type = CreateInt(1, 4);
		system("cls");
		switch (type)
		{
		case 1:
		{
			RingList<Teacher> RingList;
			OperatingRingList(RingList);
		}
		break;
		case 2:
		{
			RingList<UnionMember> RingList;
			OperatingRingList(RingList);
		}
		break;
		case 3:
		{
			RingList<TeacherUnionMember> RingList;
			OperatingRingList(RingList);
		}
		break;
		}
	} while (type != 4);
}

template<typename T>
void Menu::OperatingRingList(RingList<T>& list)
{
	T element{};
	do
	{
		cout << "Действия с кольцом\n";
		cout << "1.  Добавить элемент(ы)\n";
		cout << "2.  Вывести содержимое кольца\n";
		cout << "3.  Удалить текущий элемент\n";
		cout << "4.  Удалить все элементы\n";
		cout << "5.  Поиск элемента по фамилии\n";
		cout << "6.  Проверить пустое ли кольцо\n";
		cout << "7.  Найти элемент с максимальным возрастом\n";
		cout << "8.  Найти элемент с минимальным возрастом\n";
		cout << "9. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 10);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "Введите количество элементов:";
			int number = CreateInt(1 ,5 );
			rewind(stdin);
			for (int i = 0; i < number; i++)
			{
				cout << "Вводите объект:"<<endl;
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{
			if (list.Empty()) cout << "Кольцо пусто"<<endl;
			else
			{
			cout << "Содержимое кольца:"<<endl;
		    element.Cap();
			list.Display();
			}
			system("pause");
		}
		break;
		case 3:
		{
			list.RemoveCurrent();
			system("pause");
			system("cls");
		}
		break;
		case 4:
		{
			list.RemoveAll();
			system("pause");
			system("cls");
		}
		break;
		case 5:
		{
			cout << "Введите элемент , который вы хотите найти: ";
			system("cls");
			bool flag = true;
			T& a=list.FindBuSurname(flag);
			if (flag == true)
			{
				element.Cap();
				cout << element << endl;
			}
			system("pause");
		}
		break;
		case 6:
		{
			if (list.Empty())cout << "Кольцо пустое!" << endl;
			else cout << "В кольце содержатся элементы!" << endl;
			system("pause");
			system("cls");
		}
		break;
		case 7:
		{
			system("cls");
		    list.FindDataOfBirdthMax();
			system("pause");
		}
		break;
		case 8:
		{
			system("cls");
			list.FindDataOfBirdthMin();
			system("pause");
		}
		break;
		}
		system("cls");
	} while (choise != 9);
}

