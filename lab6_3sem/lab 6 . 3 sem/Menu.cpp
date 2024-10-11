#pragma once
#include"Menu.h"


inline void Menu::start()
{
	do
	{
		cout << "Выберите тип элементов\n";
		cout << "1. Teacher\n";
		cout << "2. UnionMember\n";
		cout << "3. TeacherUnionMember\n";
		cout << "4. Выход\n";
		cout << "Выберите действие:";
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
		cout << "Действия с кольцом\n";
		cout << "1.  Добавить элемент(ы)\n";
		cout << "2.  Вывести содержимое кольца\n";
		cout << "3.  Удалить текущий элемент\n";
		cout << "4.  Удалить все элементы\n";
		cout << "5.  Поиск по параметрам\n";
		cout << "6.  Проверить пустое ли кольцо\n";
		cout << "7.  Записать в текстовый файл\n";
		cout << "8.  Считать из текстового файла\n";
		cout << "9.  Очистить текстовый файл\n";
		cout << "10. Записать в бинарный файл\n";
		cout << "11. Считать из бинарного файла\n";
		cout << "12. Очистить бинарный файл\n";
		cout << "13. SORT\n";
		cout << "14. Выход\n";
		cout << "Выберите действие:";
		choise = enter_num<int>(cin, 1, 14);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "Введите количество элементов:";
			int number = CreateInt(1, 5);
			rewind(stdin);
			for (int i = 0; i < number; i++)
			{
				cout << "Вводите объект:" << endl;
				cin >> element;
				rewind(stdin);
				list.Push(element);
			}
			system("cls");
		}
		break;
		case 2:
		{  
			if (list.Empty()) cout << "Кольцо пусто" << endl;
			else
			{
				cout << "Содержимое кольца:" << endl;
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
				cout << "Варианты поиска:\n";
				cout << "1.  По фамилии\n";
				cout << "2.  По имени\n";
				cout << "3.  По дате рождения\n";
				cout << "4.  По фамилии и имени\n";
				cout << "5.  По фамилии и дате рождения\n";
				cout << "6.  По имени и дате рождения\n";
				cout << "7.  По имени , дате рождения и фамилии\n";
				cout << "8.  Ваш выбор :";
				int choise = CreateInt(1, 9);
				switch (choise)
				{
				case 1:
				{
					CreateName(str, "Введите фамилию: ");
					obj.SetSurname(str);
				}
				break;
				case 2:
				{
					CreateName(str, "Введите имя: ");
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
					CreateName(str, "Введите имя: ");
					obj.SetName(str);
					CreateName(str, "Введите фамилию: ");
					obj.SetSurname(str);
				}
				break;
				case 5:
				{
					CreateName(str, "Введите фамилию: ");
					obj.SetSurname(str);
					CreateDate(data);
					obj.SetDataOfBirdth(data);
				}
				break;
				case 6:
				{
					CreateName(str, "Введите имя: ");
					obj.SetName(str);
					CreateDate(data);
					obj.SetDataOfBirdth(data);
				}
				break;
				case 7:
				{
					CreateName(str, "Введите имя: ");
					obj.SetName(str);
					CreateName(str, "Введите фамилию: ");
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
			if (list.Empty())cout << "Кольцо пустое!" << endl;
			else cout << "В кольце содержатся элементы!" << endl;
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