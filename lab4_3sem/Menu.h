#pragma once
#include "RingList.h"

class Menu
{
	int choise;
	int type;
public:
	void start();
	template<typename T>
	void OperatingRingList(RingList<T>& list);
};
#include "Menu.h"

void Menu::start()
{
	do
	{
		cout << "Выберите тип элементов\n";
		cout << "1. int\n";
		cout << "2. double\n";
		cout << "3. float\n";
		cout << "4. string\n";
		cout << "5. Выход\n";
		cout << "Выберите действие:";
		cin >> type;
		system("cls");
		switch (type)
		{
		case 1:
		{
			RingList<int> RingList;
			OperatingRingList(RingList);
		}
		break;
		case 2:
		{
			RingList<double> RingList;
			OperatingRingList(RingList);
		}
		break;
		case 3:
		{
			RingList<float> RingList;
			OperatingRingList(RingList);
		}
		case 4:
		{
			RingList<string> RingList;
			OperatingRingList(RingList);
		}
		break;
		}
	} while (type != 5);
}

template<typename T>
void Menu::OperatingRingList(RingList<T>& list)
{
	T element;
	do
	{
		cout << "Действия с кольцом\n";
		cout << "1.  Добавить элемент(ы)\n";
		cout << "2.  Вывести содержимое кольца\n";
		cout << "3.  Удалить текущий элемент\n";
		cout << "4.  Удалить все элементы\n";
		cout << "5.  Удалить определённый элемент\n";
		cout << "6.  Поиск элемента\n";
		cout << "7.  Проверить пустое ли кольцо\n";
		cout << "8.  Найти максимальный элемент\n";
		cout << "9.  Найти минимальный элемент\n";
		cout << "10. Выход\n";
		cout << "Выберите действие:";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "Введите количество элементов:";
			int number;
			cin >> number;
			for (int i = 0; i < number; i++)
			{
				cout << "Вводите элемент:";
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{
			cout << "Содержимое кольца:";
			list.Display();
			system("pause");
			system("cls");
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
			cout << "Введите элемент , который вы хотите удалить: ";
			cin >> element;
			list.Remove(element);
			system("pause");
			system("cls");
		}
		break;
		case 6:
		{
			cout << "Введите элемент , который вы хотите найти: ";
			cin >> element;
			system("cls");
			if (list.Searche(element)) cout << "Данный элемент содержится в кольце" << endl;
			else cout << "Данный элемент не содержится в кольце или оно пустое" << endl;
			system("pause");
		}
		break;
		case 7:
		{
			if (list.Empty())cout << "Кольцо пустое!" << endl;
			else cout << "В кольце содержатся элементы!" << endl;
			system("pause");
			system("cls");
		}
		case 8:
		{
			cout << "Максимальный элемент в кольце: " << list.FindMax() << endl;
			system("pause");
			system("cls");
		}
		break;
		case 9:
		{
			cout << "Минимальный элемент в кольце: " << list.FindMin() << endl;
			system("pause");
			system("cls");
		}
		break;
		}
		system("cls");
	} while (choise != 10);
}