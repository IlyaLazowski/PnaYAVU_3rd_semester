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
		cout << "�������� ��� ���������\n";
		cout << "1. int\n";
		cout << "2. double\n";
		cout << "3. float\n";
		cout << "4. string\n";
		cout << "5. �����\n";
		cout << "�������� ��������:";
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
		cout << "�������� � �������\n";
		cout << "1.  �������� �������(�)\n";
		cout << "2.  ������� ���������� ������\n";
		cout << "3.  ������� ������� �������\n";
		cout << "4.  ������� ��� ��������\n";
		cout << "5.  ������� ����������� �������\n";
		cout << "6.  ����� ��������\n";
		cout << "7.  ��������� ������ �� ������\n";
		cout << "8.  ����� ������������ �������\n";
		cout << "9.  ����� ����������� �������\n";
		cout << "10. �����\n";
		cout << "�������� ��������:";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "������� ���������� ���������:";
			int number;
			cin >> number;
			for (int i = 0; i < number; i++)
			{
				cout << "������� �������:";
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{
			cout << "���������� ������:";
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
			cout << "������� ������� , ������� �� ������ �������: ";
			cin >> element;
			list.Remove(element);
			system("pause");
			system("cls");
		}
		break;
		case 6:
		{
			cout << "������� ������� , ������� �� ������ �����: ";
			cin >> element;
			system("cls");
			if (list.Searche(element)) cout << "������ ������� ���������� � ������" << endl;
			else cout << "������ ������� �� ���������� � ������ ��� ��� ������" << endl;
			system("pause");
		}
		break;
		case 7:
		{
			if (list.Empty())cout << "������ ������!" << endl;
			else cout << "� ������ ���������� ��������!" << endl;
			system("pause");
			system("cls");
		}
		case 8:
		{
			cout << "������������ ������� � ������: " << list.FindMax() << endl;
			system("pause");
			system("cls");
		}
		break;
		case 9:
		{
			cout << "����������� ������� � ������: " << list.FindMin() << endl;
			system("pause");
			system("cls");
		}
		break;
		}
		system("cls");
	} while (choise != 10);
}