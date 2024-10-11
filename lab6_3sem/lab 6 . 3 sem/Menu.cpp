#pragma once
#include"Menu.h"


inline void Menu::start()
{
	do
	{
		cout << "�������� ��� ���������\n";
		cout << "1. Teacher\n";
		cout << "2. UnionMember\n";
		cout << "3. TeacherUnionMember\n";
		cout << "4. �����\n";
		cout << "�������� ��������:";
		type = enter_num<int>(cin, 1, 4);
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
		cout << "5.  ����� �� ����������\n";
		cout << "6.  ��������� ������ �� ������\n";
		cout << "7.  �������� � ��������� ����\n";
		cout << "8.  ������� �� ���������� �����\n";
		cout << "9.  �������� ��������� ����\n";
		cout << "10. �������� � �������� ����\n";
		cout << "11. ������� �� ��������� �����\n";
		cout << "12. �������� �������� ����\n";
		cout << "13. SORT\n";
		cout << "14. �����\n";
		cout << "�������� ��������:";
		choise = enter_num<int>(cin, 1, 14);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "������� ���������� ���������:";
			int number = CreateInt(1, 5);
			rewind(stdin);
			for (int i = 0; i < number; i++)
			{
				cout << "������� ������:" << endl;
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{  
			if (list.Empty()) cout << "������ �����" << endl;
			else
			{
				cout << "���������� ������:" << endl;
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
			if (!list.Empty())
			{
				Iterator<T> cur = list.Begin();
				Algorithm<T> alg;
				T obj;
				char str[32], data[11];
				cout << "�������� ������:\n";
				cout << "1.  �� �������\n";
				cout << "2.  �� �����\n";
				cout << "3.  �� ���� ��������\n";
				cout << "4.  �� ������� � �����\n";
				cout << "5.  �� ������� � ���� ��������\n";
				cout << "6.  �� ����� � ���� ��������\n";
				cout << "7.  �� ����� , ���� �������� � �������\n";
				cout << "8.  ��� ����� :";
				int choise = CreateInt(1, 9);
				switch (choise)
				{
				case 1:
				{
					CreateName(str, "������� �������: ");
					obj.SetSurname(str);
				}
				break;
				case 2:
				{
					CreateName(str, "������� ���: ");
					obj.SetName(str);
				}
				break;
				case 3:
				{
					CreateDate(data);
					obj.SetDataOfBirdth(data);

				}
				break;
				case 4:
				{
					CreateName(str, "������� ���: ");
					obj.SetName(str);
					CreateName(str, "������� �������: ");
					obj.SetSurname(str);
				}
				break;
				case 5:
				{
					CreateName(str, "������� �������: ");
					obj.SetSurname(str);
					CreateDate(data);
					obj.SetDataOfBirdth(data);
				}
				break;
				case 6:
				{
					CreateName(str, "������� ���: ");
					obj.SetName(str);
					CreateDate(data);
					obj.SetDataOfBirdth(data);
				}
				break;
				case 7:
				{
					CreateName(str, "������� ���: ");
					obj.SetName(str);
					CreateName(str, "������� �������: ");
					obj.SetSurname(str);
					CreateDate(data);
					obj.SetDataOfBirdth(data);
				}
				break;
				}
				element.Cap();
				alg.poisk(cur , obj);
				system("pause");
			}
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
			TEXTFILE f;
			string path = file_name<T>();
			f.WriteToFile(path, list);
		}
		break;
		case 8:
		{
			TEXTFILE f;
			string path = file_name<T>();
			f.ReadFromFile(path, list);
		}
		break;
		case 9:
		{
			TEXTFILE f;
			string path = file_name<T>();
			f.ClearFile(path);
		}
		break;
		case 10:
		{
			BINFILE f;
			string path = file_name<T>();
			f.WriteToFile(path, list);
		}
		break;
		case 11:
		{
			BINFILE f;
			string path = file_name<T>();
			f.ReadFromFile(path, list);
		}
		break;
		case 12:
		{
			BINFILE f;
			string path = file_name<T>();
			f.ClearFile(path);
		}
		break;
		case 13:
		{
			Iterator<T> cur = list.Begin();
			Algorithm<T> alg;
			alg.sort(cur);
		}
		break;
		}
		system("cls");
	} while (choise != 14);
}