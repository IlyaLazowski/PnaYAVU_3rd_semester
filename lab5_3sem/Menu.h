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
		cout << "�������� ��� ���������\n";
		cout << "1. Teacher\n";
		cout << "2. UnionMember\n";
		cout << "3. TeacherUnionMember\n";
		cout << "4. �����\n";
		cout << "�������� ��������:";
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
		cout << "�������� � �������\n";
		cout << "1.  �������� �������(�)\n";
		cout << "2.  ������� ���������� ������\n";
		cout << "3.  ������� ������� �������\n";
		cout << "4.  ������� ��� ��������\n";
		cout << "5.  ����� �������� �� �������\n";
		cout << "6.  ��������� ������ �� ������\n";
		cout << "7.  ����� ������� � ������������ ���������\n";
		cout << "8.  ����� ������� � ����������� ���������\n";
		cout << "9. �����\n";
		cout << "�������� ��������:";
		choise = CreateInt(1, 10);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "������� ���������� ���������:";
			int number = CreateInt(1 ,5 );
			rewind(stdin);
			for (int i = 0; i < number; i++)
			{
				cout << "������� ������:"<<endl;
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{
			if (list.Empty()) cout << "������ �����"<<endl;
			else
			{
			cout << "���������� ������:"<<endl;
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
			cout << "������� ������� , ������� �� ������ �����: ";
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
			if (list.Empty())cout << "������ ������!" << endl;
			else cout << "� ������ ���������� ��������!" << endl;
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

