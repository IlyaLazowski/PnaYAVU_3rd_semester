//Interface.cpp
#pragma once
#include"Interface.h"

inline void Interface::opr_dostupa()
{
	int dostup;
	do
	{
		cout << "��� �� ������ �����:\n";
		cout << "1. ����� ��� �������������\n";
		cout << "2. ����� ��� ������������\n";
		cout << "3. �����\n";
		cout << "�������� ��������:";
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

			cout << "������� �����: ";
			cin >> input_login;
			cout << "������� ������: ";
			cin >> input_password;
			if (input_login == login && input_password == password)
			{
			cout << "����������� ������ �������." << endl;
			system("pause");
			system("cls");
			StartForAdmin();
			}
			else
			{
				cout << "�� �� ������ ������ �������." << endl;
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
		cout << "� ��� �� ������ �������� :\n";
		cout << "1. �������\n";
		cout << "2. ���������� ����\n";
		cout << "3. ����������� ����\n";
		cout << "4. �����\n";
		cout << "5. ����������\n";
		cout << "6. ������\n";
		cout << "7. �������\n";
		cout << "8. �����\n";
		cout << "�������� ��������:";
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
		cout << "���������� ��� �� ���������:\n";
		cout << "1. ������\n";
		cout << "2. ���������� ����\n";
		cout << "3. ����������� ����\n";
		cout << "4. �����\n";
		cout << "�������� ��������:";
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
		cout << "�������� � �������\n";
		cout << "1.  �������� �������(�)\n";
		cout << "2.  ������� ���������� ������\n";
		cout << "3.  ������� ������� �������\n";
		cout << "4.  ������� ��� ��������\n";
		cout << "5.  ����� ��������� �� ����������\n";
		cout << "6.  ��������� ������ �� ������\n";
		cout << "7.  �������� ����\n";
		cout << "8.  �������� � ����\n";
		cout << "9.  ������� �� �����\n";
		cout << "10. ����������\n";
		cout << "11. �����\n";
		cout << "�������� ��������:";
		choise = CreateInt(1, 11);
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
				T ex;
				cout << "������� ������:" << endl;
				cin >> ex;
				rewind(stdin);
				list.Push(ex);

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
			cout << "�������� ������:\n";
			cout << "1.  �� �������\n";
			cout << "2.  �� ��������\n";
			cout << "3.  �� ������� � ���������� ������\n";
			cout << "��� ����� :";
			int choise = CreateInt(1, 3);
			switch (choise)
			{
			case 1:
			{
				cout << "������� ������ : ";
				local1 = CreateDouble(0,1000000);
				obj.SetBalance(local1);
			}
			break;
			case 2:
			{
				cout << "������� �������� : ";
				local1 = CreateDouble(0, 10000);
				obj.SetSalary(local1);
			}
			break;
			case 3:
			{
				cout << "������� ������ : ";
				local1 = CreateDouble(0, 1000000);
				obj.SetBalance(local1);
				cout << "������� �������� : ";
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
			cout << "�������� ����������\n";
			cout << "1. �� ���������� �������\n";
			cout << "2. �� ���������� �������\n";
			cout << "3. �� ���������� ��������\n";
			cout << "4. �� ���������� ��������\n";
			cout << "5. ��� �����: \n";
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
		cout << "�������� � �������\n";
		cout << "1.  �������� �������(�)\n";
		cout << "2.  ������� ���������� ������\n";
		cout << "3.  ������� ������� �������\n";
		cout << "4.  ������� ��� ��������\n";
		cout << "5.  �������� �� �������\n";
		cout << "6.  ����� �� �������\n";
		cout << "7.  ����� �� ����������\n";
		cout << "8.  ��������� ������ �� ������\n";
		cout << "9.  �������� ����\n";
		cout << "10. �������� � ����\n";
		cout << "11. ������� �� �����\n";
		cout << "12. ����������\n";
		cout << "13. STL\n";
		cout << "14. ����� ����� ���������� ������\n";
		cout << "15. �����\n";
		cout << "�������� ��������:";
		choise = CreateInt(1, 15);
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
				T ex;
				cout << "������� ������:" << endl;
				cin >> ex;
				rewind(stdin);
				list.Push(ex);

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
			cout << "�������� ������:\n";
			cout << "1.  �� ���������� ������\n";
			cout << "2.  �� �����\n";
			cout << "3.  �� ���������� ������ � �����\n";
			cout << "��� ����� :";
			int choise = CreateInt(1, 3);
			switch (choise)
			{
			case 1:
			{
				cout << "������� ���������� ������ : ";
				local1 = CreateDouble(0.1, 20);
				obj.SetInterestRate(local1);
			}
			break;
			case 2:
			{
				cout << "������� ����� : ";
				local1 = CreateDouble(2.6, 100000);
				obj.SetSum(local1);
			}
			break;
			case 3:
			{
				cout << "������� ���������� ������ : ";
				local1 = CreateDouble(0.1, 20);
				obj.SetInterestRate(local1);
				cout << "������� ����� : ";
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
			if (list.Empty())cout << "������ ������!" << endl;
			else cout << "� ������ ���������� ��������!" << endl;
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
			cout << "�������� ����������\n";
			cout << "1. �� ���������� �����\n";
			cout << "2. �� ���������� �����\n";
			cout << "3. �� ���������� ����������� ������\n";
			cout << "4. �� ���������� ���������� ������\n";
			cout << "5. ��� �����: \n";
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
			cout << "�������� ������:\n";
			cout << "1.  ����� ����� ����� ��� ���������� ���\n";
			cout << "2.  ����� ����� ����� ����������� ���\n";
			cout << "��� ����� :";
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
		cout << "1. ������������������\n";   //� �������� ��������� 1
		cout << "2. ����������������\n";     //���� ����� ����������� ������ ������� ������� , �� � �������� ���������� 0
		cout << "3. ������ ���������� ��������\n";
		cout << "4. �����\n";
		cout << "�������� ��������:";
		choise = CreateInt(1, 4);
		rewind(stdin);
		system("cls");
		switch (choise)
		{
		case 1:
		{
			cout << "������� ���� ������:" << endl;
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
				cout << "����������� ������ �������" << endl;
				system("pause");
				OperationsWithObject(a, list, otmena, deistvie);
			}
			else
			{
				cout << "����������� �� �������" << endl;
				system("pause");
			}
		}
		break;
		case 3:
		{
			if (otmena.show_size() == 0)
			{
				cout << "������ ���������� �������� ����������." << endl;
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
		cout << "�������� ��� \n";
		cout << "1. ���������� ����� ������\n";
		cout << "2. ���������� ��� ������\n";
		cout << "3. ��������� ������� ����\n";
		cout << "4. ������� �� �������� �����\n";
		cout << "5. �������� ���-���\n";
		cout << "6. ������� �������\n";
		cout << "7. ������ ��������\n";
		cout << "8. ������ � ��������\n";
		cout << "9. �����\n";
		cout << "�������� ��������:";
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
			cout << "������� ���� ��� ����������(2.6,100000): ";
			double temp = CreateDouble(2.6, 100000);
			a.SetBalance(a.GetBalance() + temp);
			ClearingInformationAboutAllClientsFromFiles<T>();
			WritingUpdatedCustomerInformationToFile<T>(list);
		}
		break;
		case 4:
		{
			cout << "������� ���� ��� ��������(2.6,100000): ";
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
				cout << "� ��� ������������ ������� ��� ��������" << endl;
				system("pause");
			}
		}
		break;
		case 5:
		{
			cout << "������� ����� ���-���:";
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
			cout << "������� ���� ��� c�����(2.6,100000): ";
			double temp = CreateDouble(2.6, 100000);
			if (a.GetBalance() >= temp)
			{
				a.SetBalance(a.GetBalance() - temp);
				ClearingInformationAboutAllClientsFromFiles<T>();
				WritingUpdatedCustomerInformationToFile<T>(list);
			}
			else
			{
				cout << "� ��� ������������ ������� ��� ������ ������ �����" << endl;
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
		cout << "�������� ��� \n";
		cout << "1. �������� � ����� List\n";
		cout << "2. �������� � ������ List\n";
		cout << "3. �������� List\n";
		cout << "4. ������� �������\n";
		cout << "5. �������� List\n";
		cout << "6. ������ ���������\n";
		cout << "7. ������ ������ List\n";
		cout << "8. �������� ������� � List\n";
		cout << "9. �����\n";
		cout << "�������� ��������:";
		choise = CreateInt(1, 9);
		switch (choise)
		{
		case 1:
		{
			system("cls");
			cin >> ex;
			a.push_back(ex);
			cout << "������ ������� ��������!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cin >> ex;
			a.push_front(ex);
			cout << "������ ������� ��������!" << endl;
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
			cout << "����� ������� �������?(���������� ������)" << endl;
			double t;
			cin >> t;
			for (at = a.begin(); at != a.end(); at++)
			{
				if ((at->GetInterestRate()) == t)
				{
					a.erase(at);
					cout << "������ �����!" << endl;
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
			cout << "List ������!" << endl;
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
			cout << "����� ������� ��� ������� ��������: " << endl;
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
			cout << "������� ��������!" << endl;
			system("cls");
			system("pause");
			break;
		}
		}
	} while (choise != 9);
}
