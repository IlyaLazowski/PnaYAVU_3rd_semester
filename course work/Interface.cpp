//Interface.cpp
#pragma once
#include"Interface.h"

inline void Interface::opr_dostupa()
{
	int dostup;
	do
	{
		cout << "Как вы хотите войти:\n";
		cout << "1. Войти как администратор\n";
		cout << "2. Войти как пользователь\n";
		cout << "3. Выход\n";
		cout << "Выберите действие:";
		dostup = CreateInt(1, 3);
		rewind(stdin);
		system("cls");
		switch (dostup)
		{
		case 1:
		{
			string input_password, input_login;
			string login = "admin";
			string password = "123456";

			cout << "Введите логин: ";
			cin >> input_login;
			cout << "Введите пароль: ";
			cin >> input_password;
			if (input_login == login && input_password == password)
			{
			cout << "Авторизация прошла успешно." << endl;
			system("pause");
			system("cls");
			StartForAdmin();
			}
			else
			{
				cout << "Вы не имеете такого доступа." << endl;
			}
		}
		break;
		case 2:
		{
			StartforUser();
		}
		break;
		}
	} while (dostup != 3);
}
inline void Interface::StartForAdmin()
{
	int type;
	do
	{
		cout << "С чем вы хотите работать :\n";
		cout << "1. Клиенты\n";
		cout << "2. Физические лица\n";
		cout << "3. Юридические лица\n";
		cout << "4. Займы\n";
		cout << "5. Эквайринги\n";
		cout << "6. Вклады\n";
		cout << "7. Кредиты\n";
		cout << "8. Выход\n";
		cout << "Выберите действие:";
		rewind(stdin);
		type = CreateInt(1, 8);
		rewind(stdin);
		system("cls");
		switch (type)
		{
		case 1:
		{
			RingList<Klient> RingList;
			AdminWorkWithClients(RingList);
		}
		break;
		case 2:
		{
			RingList<Fizliz> RingList;;
			AdminWorkWithClients(RingList);
		}
		break;
		case 3:
		{
			RingList<Yrliz>  RingList;
			AdminWorkWithClients(RingList);
		}
		break;
		case 4:
		{
			RingList<Zaim>  RingList;
			AdminOsperationsWithBankServices(RingList);
		}
		break;
		case 5:
		{
			RingList<Akvair>  RingList;
			AdminOsperationsWithBankServices(RingList);
		}
		break;
		case 6:
		{
			RingList<Vklad>  RingList;
			AdminOsperationsWithBankServices(RingList);
		}
		break;
		case 7:
		{
			RingList<Kredit>  RingList;
			AdminOsperationsWithBankServices(RingList);
		}
		break;
		}
	} while (type != 8);
}
inline void Interface::StartforUser()
{
	int type;
	do
	{
		cout << "Определите кем вы являетесь:\n";
		cout << "1. Клиент\n";
		cout << "2. Физическое лицо\n";
		cout << "3. Юридическое лицо\n";
		cout << "4. Выход\n";
		cout << "Выберите действие:";
		type = CreateInt(1, 4);
		rewind(stdin);
		system("cls");
		switch (type)
		{
		case 1:
		{
			RingList<Klient> RingList = GettingUserDataFromFile<Klient>();
			OperationsWithClientObjects(RingList);
		}
		break;
		case 2:
		{
			RingList<Fizliz> RingList = GettingUserDataFromFile<Fizliz>();
			OperationsWithClientObjects(RingList);
		}
		break;
		case 3:
		{
			RingList<Yrliz>  RingList = GettingUserDataFromFile<Yrliz>();
			OperationsWithClientObjects(RingList);
		}
		break;
		}
	} while (type != 4);
}
template<typename T>
void Interface::AdminWorkWithClients(RingList<T>& list)
{
	int choise;
	do
	{
		T element{};
		cout << "Действия с кольцом\n";
		cout << "1.  Добавить элемент(ы)\n";
		cout << "2.  Вывести содержимое кольца\n";
		cout << "3.  Удалить текущий элемент\n";
		cout << "4.  Удалить все элементы\n";
		cout << "5.  Поиск элементов по параметрам\n";
		cout << "6.  Проверить пустое ли кольцо\n";
		cout << "7.  Очистить файл\n";
		cout << "8.  Записать в файл\n";
		cout << "9.  Считать из файла\n";
		cout << "10. Сортировки\n";
		cout << "11. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 11);
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
				T ex;
				cout << "Вводите объект:" << endl;
				cin >> ex;
				rewind(stdin);
				list.Push(ex);

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
				T a;
				a.Cap();
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
			Iterator<T> cur = list.GetCurrent();
			Algorithm<T> alg;
			double local1, local2;
			T obj;
			cout << "Варианты поиска:\n";
			cout << "1.  По балансу\n";
			cout << "2.  По зарплате\n";
			cout << "3.  По балансу и процентной ставке\n";
			cout << "Ваш выбор :";
			int choise = CreateInt(1, 3);
			switch (choise)
			{
			case 1:
			{
				cout << "Введите баланс : ";
				local1 = CreateDouble(0,1000000);
				obj.SetBalance(local1);
			}
			break;
			case 2:
			{
				cout << "Введите зарплату : ";
				local1 = CreateDouble(0, 10000);
				obj.SetSalary(local1);
			}
			break;
			case 3:
			{
				cout << "Введите баланс : ";
				local1 = CreateDouble(0, 1000000);
				obj.SetBalance(local1);
				cout << "Введите зарплату : ";
				local2 = CreateDouble(0, 10000);
				obj.SetSalary(local2);
			}
			break;
			}
			alg.Search(cur, obj);
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
			TEXTFILE f;
			string path = file_name<T>();
			f.ClearFile(path);
		}
		break;
		case 8:
		{
			TEXTFILE f;
			string path = file_name<T>();
			f.WriteToFile(path, list);
		}
		break;
		case 9:
		{
			TEXTFILE f;
			string path = file_name<T>();
			f.ReadFromFile(path, list);
		}
		break;
		case 10:
		{
			Iterator<T> cur = list.GetCurrent();
			Algorithm<T> alg;
			cout << "Выберите сортировку\n";
			cout << "1. По увеличению баланса\n";
			cout << "2. По уменьшению баланса\n";
			cout << "3. По увеличению зарплаты\n";
			cout << "4. По уменьшению зарплаты\n";
			cout << "5. Ваш выбор: \n";
			int index = CreateInt(1, 4);
			alg.sort(cur ,index );
		}
		break;
		}
		system("cls");
	} while (choise != 11);
}

template<typename T>
inline void Interface::AdminOsperationsWithBankServices(RingList<T>& list)
{
	int choise;
	do
	{
		T element{};
		cout << "Действия с кольцом\n";
		cout << "1.  Добавить элемент(ы)\n";
		cout << "2.  Вывести содержимое кольца\n";
		cout << "3.  Удалить текущий элемент\n";
		cout << "4.  Удалить все элементы\n";
		cout << "5.  Удаление по индексу\n";
		cout << "6.  Поиск по индексу\n";
		cout << "7.  Поиск по параметрам\n";
		cout << "8.  Проверить пустое ли кольцо\n";
		cout << "9.  Очистить файл\n";
		cout << "10. Записать в файл\n";
		cout << "11. Считать из файла\n";
		cout << "12. Сортировка\n";
		cout << "13. STL\n";
		cout << "14. Поиск самой популярной услуги\n";
		cout << "15. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 15);
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
				T ex;
				cout << "Вводите объект:" << endl;
				cin >> ex;
				rewind(stdin);
				list.Push(ex);

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
				T a;
				a.Cap();
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
			list.DeletingServiceByIndex();
			system("pause");
		}
		break;
		case 6:
		{
			bool flag = false;
			T& obj = list.SearchForAServiceByIndex(flag);
			if (flag)obj.ChangingServiceFields();
		}
		break;
		case 7:
		{
			Iterator<T> cur = list.GetCurrent();
			Algorithm<T> alg;
			double local1, local2;
			T obj;
			cout << "Варианты поиска:\n";
			cout << "1.  По процентной ставке\n";
			cout << "2.  По сумме\n";
			cout << "3.  По процентной ставке и сумме\n";
			cout << "Ваш выбор :";
			int choise = CreateInt(1, 3);
			switch (choise)
			{
			case 1:
			{
				cout << "Введите процентную ставку : ";
				local1 = CreateDouble(0.1, 20);
				obj.SetInterestRate(local1);
			}
			break;
			case 2:
			{
				cout << "Введите сумму : ";
				local1 = CreateDouble(2.6, 100000);
				obj.SetSum(local1);
			}
			break;
			case 3:
			{
				cout << "Введите процентную ставку : ";
				local1 = CreateDouble(0.1, 20);
				obj.SetInterestRate(local1);
				cout << "Введите сумму : ";
				local2 = CreateDouble(2.6, 100000);
				obj.SetSum(local2);
			}
			break;
			}  
			alg.Search(cur, obj);
			system("pause");
		}
		break;
		case 8:
		{
			if (list.Empty())cout << "Кольцо пустое!" << endl;
			else cout << "В кольце содержатся элементы!" << endl;
			system("pause");
			system("cls");
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
			TEXTFILE f;
			string path = file_name<T>();
			f.WriteToFile(path, list);
		}
		break;
		case 11:
		{
			TEXTFILE f;
			string path = file_name<T>();
			f.ReadFromFile(path, list);
		}
		break;
		case 12:
		{
			Iterator<T> cur = list.GetCurrent();
			Algorithm<T> alg;
			cout << "Выберите сортировку\n";
			cout << "1. По увеличению суммы\n";
			cout << "2. По уменьшению суммы\n";
			cout << "3. По увеличению процентоной ставки\n";
			cout << "4. По уменьшению процентной ставки\n";
			cout << "5. Ваш выбор: \n";
			int index = CreateInt(1, 4);
			alg.sort(cur, index);
		}
		break;
		case 13:
		{
			STL<T>();
		}
		break;
		case 14:
		{
			Algorithm<T> alg;
			cout << "Варианты поиска:\n";
			cout << "1.  Поиск среди услуг для физических лиц\n";
			cout << "2.  Поиск среди услуг юридических лиц\n";
			cout << "Ваш выбор :";
			int choise = CreateInt(1, 2);
			switch (choise)
			{
			case 1:
			{
				alg.SearchForTheMostPopularServiceAmongIndividuals();
				cout << endl;
			}
			break;
			case 2:
			{
				alg.SearchForTheMostPopularServiceAmongLegalEntities();
				cout << endl;
			}
			break;
			}
			system("pause");
		}
		break;
		}
		system("cls");
	} while (choise != 15);
}

template<typename T>
void Interface::OperationsWithClientObjects(RingList<T>& list)
{
	int choise;
	Stack<T> otmena;
	Stack<int> deistvie;
	T ex{};
	bool flag_otmenu = false;
	do
	{
		cout << "1. Зарегистрироваться\n";   //в действие заносится 1
		cout << "2. Авторизироваться\n";     //если после авторизации нажать удалить аккаунт , то в действие заноситься 0
		cout << "3. Отмена последнего действия\n";
		cout << "4. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 4);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "Введите свои данные:" << endl;
			cin >> ex;
			list.Push(ex);
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
			deistvie.add_data(1);
			otmena.add_data(ex);
			rewind(stdin);
			system("cls");
		}
		break;
		case 2:
		{
			bool flag = true;
			T& a = list.Authorization(flag);
			if (flag == true)
			{
				cout << "Авторизация прошла успешно" << endl;
				system("pause");
				OperationsWithObject(a, list, otmena, deistvie);
			}
			else
			{
				cout << "Авторизация не удалась" << endl;
				system("pause");
			}
		}
		break;
		case 3:
		{
			if (otmena.show_size() == 0)
			{
				cout << "Отмена последнего действия невозможна." << endl;
				system("pause");
				system("cls");
			}
			else
			{
				if (deistvie.POP() == 0)
				{
					list.Push(otmena.POP());
					ClearingInformationAboutAllClientsFromFiles<T>();
					WritingUpdatedCustomerInformationToFile<T>(list);
				}
				else
				{
					T a = otmena.POP();
					list.RemoveBuPersonalAccount(a.GetPersonalAccount());
					ClearingInformationAboutAllClientsFromFiles<T>();
					WritingUpdatedCustomerInformationToFile<T>(list);
				}
			}
		}
		}
	} while (choise != 4);
}

template<typename T>
void Interface::OperationsWithObject(T& a, RingList<T>& list, Stack<T>& otmena, Stack<int>& deistvie)
{
	int choise;
	do
	{
		cout << "Выберите тип \n";
		cout << "1. Посмотреть общий баланс\n";
		cout << "2. Посмотреть мои данные\n";
		cout << "3. Пополнить лицевой счет\n";
		cout << "4. Перевод по лицевому счёту\n";
		cout << "5. Изменить пин-код\n";
		cout << "6. Удалить аккаунт\n";
		cout << "7. Выдача наличных\n";
		cout << "8. Работа с услугами\n";
		cout << "9. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 9);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout<< a.TotalBalance()<<endl;
			a.TotalBalance();
			system("pause");
		}
		break;
		case 2:
		{
			a.Cap();
			cout << a << endl;
		}
		break;
		case 3:
		{
			cout << "Введите суму для пополнение(2.6,100000): ";
			double temp = CreateDouble(2.6, 100000);
			a.SetBalance(a.GetBalance() + temp);
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
		}
		break;
		case 4:
		{
			cout << "Введите суму для перевода(2.6,100000): ";
			double temp = CreateDouble(2.6, 100000);
			if (a.GetBalance() >= temp)
			{
				Algorithm<T> alg;
				a.SetBalance(a.GetBalance() - temp);
				ClearingInformationAboutAllClientsFromFiles<T>();
				WritingUpdatedCustomerInformationToFile<T>(list);
				alg.TransferOfFundsToTheAccount(temp);
			}
			else
			{
				cout << "У вас недостаточно средств для перевода" << endl;
				system("pause");
			}
		}
		break;
		case 5:
		{
			cout << "Введите новый пин-код:";
			int pin = CreateInt(1000, 9999);
			a.SetPinCode(pin);
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
		}
		break;
		case 6:
		{
			deistvie.add_data(0);
			otmena.add_data(a);
			list.RemoveBuPersonalAccount(a.GetPersonalAccount());
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
			choise = 8;
		}
		break;
		case 7:
		{
			cout << "Введите суму для cнятия(2.6,100000): ";
			double temp = CreateDouble(2.6, 100000);
			if (a.GetBalance() >= temp)
			{
				a.SetBalance(a.GetBalance() - temp);
				ClearingInformationAboutAllClientsFromFiles<T>();
				WritingUpdatedCustomerInformationToFile<T>(list);
			}
			else
			{
				cout << "У вас недостаточно средств для снятия данной суммы" << endl;
				system("pause");
			}
		}
		break;
		case 8:
		{
			a.RegistrationOfServices();
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
		}
		break;
		}
	} while (choise != 9);
}

template<typename T>
void Interface::STL()
{
	system("cls");
	list<T> a;
	int choise;
	T ex;
	do {
		cout << "Выберите тип \n";
		cout << "1. Добавить в конец List\n";
		cout << "2. Добавить в начало List\n";
		cout << "3. Показать List\n";
		cout << "4. Удалить элемент\n";
		cout << "5. Очистить List\n";
		cout << "6. Реверс элементов\n";
		cout << "7. Узнать размер List\n";
		cout << "8. Вставить элемент в List\n";
		cout << "9. Выход\n";
		cout << "Выберите действие:";
		choise = CreateInt(1, 9);
		switch (choise)
		{
		case 1:
		{
			system("cls");
			cin >> ex;
			a.push_back(ex);
			cout << "Объект успешно добавлен!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cin >> ex;
			a.push_front(ex);
			cout << "Объект успешно добавлен!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			ex.Cap();
			list<T>::template iterator at;
			int i;
			for (at = a.begin(), i = 1; at != a.end(); at++, i++)
			{
				(*at).Output(i);
				cout << endl;
			}
			break;
		}
		case 4:
		{
			system("cls");
			ex.Cap();
			list<T>::template iterator at;
			int i;
			for (at = a.begin(), i = 1; at != a.end(); at++, i++)
			{
				(*at).Output(i);
				cout << endl;
			}
			cout << "Какой элемент удалить?(Процентная ставка)" << endl;
			double t;
			cin >> t;
			for (at = a.begin(); at != a.end(); at++)
			{
				if ((at->GetInterestRate()) == t)
				{
					a.erase(at);
					cout << "Объект удалён!" << endl;
					system("pause");
					system("cls");
					break;
				}
			}
			break;
		}
		case 5:
		{
			a.clear();
			cout << "List очищен!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			a.reverse();
			system("cls");
			break;
		}
		case 7:
		{
			cout << "SIZE = " << a.size() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			system("cls");
			cin >> ex;
			cout << "Введи позицию для вставки элемента: " << endl;
			int position, count = 0;
			cin >> position;
			list<T>::template iterator at;
			for (at = a.begin(); at != a.end(); at++)
			{
				count++;
				if (count == position)
				{
					a.insert(at, ex);
					break;
				}
			}
			cout << "Элемент добавлен!" << endl;
			system("cls");
			system("pause");
			break;
		}
		}
	} while (choise != 9);
}
