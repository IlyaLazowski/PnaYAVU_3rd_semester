#include "Yrliz.h"

Yrliz::Yrliz()
{
	this->yr_name[0] = '\0';
	this->number_employees = 0;
	this->zaimu.clear();
	this->akvairu.clear();
}

Yrliz::Yrliz(const Yrliz& other) :Klient(other)
{
	strcpy_s(this->yr_name, 20, other.yr_name);
	this->number_employees = other.number_employees;
	this->zaimu = other.zaimu;
	this->akvairu = other.akvairu;
}

Yrliz::~Yrliz()
{
	this->akvairu.clear();
	this->zaimu.clear();
}

size_t Yrliz::GetZaimuSize()
{
	return this->zaimu.size();
}

size_t Yrliz::GetAkvairuSize()
{
	return this->akvairu.size();
}

vector<Zaim*>& Yrliz::GetZaimu()
{
	return this->zaimu;
}

vector<Akvair*>& Yrliz::GetAkvairu()
{
	return this->akvairu;
}

char* Yrliz::GetYrName()
{
	return this->yr_name;
}

Yrliz& Yrliz::operator=(const Yrliz& other)
{
	Klient::operator=(other);
	strcpy_s(this->yr_name, 20, other.yr_name);
	this->number_employees = other.number_employees;
	this->zaimu = other.zaimu;
	this->akvairu = other.akvairu;
	return *this;
}

int Yrliz::GetNumberEmployess()
{
	return this->number_employees;
}

void Yrliz::RegistrationZaim()
{
	Zaim obj;
	obj.Cap();
	ifstream ifs("Zaim.txt", ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << "Human.txt";
		system("pause");
	}
	int i = 0, choise{};
	vector<Zaim*> local;
	while (ifs >> obj)
	{
		obj.Output(++i);
		local.push_back(obj.clone());
		cout << endl;
	}
	ifs.close();
	if (i==0) cout << "К сожалению в банке сейчас нет доступных займов." << endl;
	else
	{
	choise = CreateInt(1, i);
	this->zaimu.push_back(local[choise - 1]->clone());
	this->zaimu[this->zaimu.size() - 1]->SetAccountNumber(GenerateCountingServices("GenerateSchet.txt"));
	this->balance = this->balance + this->zaimu[this->zaimu.size() - 1]->GetSum();
	this->zaimu[this->zaimu.size() - 1]->SetSum((this->zaimu[this->zaimu.size() - 1]->GetSum()+(this->zaimu[this->zaimu.size() - 1]->GetSum()* this->zaimu[this->zaimu.size() - 1]->GetInterestRate()/100)));
	}
}

void Yrliz::RegistrationAkvair()
{
	Akvair obj;
	obj.Cap();
	ifstream ifs("Akvair.txt", ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << "Human.txt";
		system("pause");
	}
	int i = 0, choise;
	vector<Akvair*> local;
	while (ifs >> obj)
	{
		obj.Output(++i);
		local.push_back(obj.clone());
		cout << endl;
	}
	ifs.close();
	if (i==0) cout << "К сожалению в банке сейчас нет доступных эквайрингов." << endl;
	else
	{
		choise = CreateInt(1, i);
		if (local[choise - 1]->GetSum() > this->GetBalance()) cout << "У вас не хватает средств!" << endl;
	else
	{
			this->akvairu.push_back(local[choise - 1]->clone());
			this->akvairu[this->akvairu.size() - 1]->SetAccountNumber(GenerateCountingServices("GenerateSchet.txt"));
			this->balance = this->balance - this->akvairu[this->akvairu.size() - 1]->GetSum();
	}
	}
}

void Yrliz::DeletionUnderIndex(int index)
{
	this->zaimu.erase(zaimu.begin() + index);
}

void Yrliz::SetYrName(char yr_name[])
{
	strcpy_s(this->yr_name, 20, yr_name);
}

void Yrliz::SetNumberEmployess(int number_employess)
{
	this->number_employees = number_employess;
}

void Yrliz::Cap() const
{
	std::string line(170, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "SURNAME"
		<< std::setw(21) << "CARD NUMBER"
		<< std::setw(6) << "CODE"
		<< std::setw(10) << "BALANCE"
		<< std::setw(10) << "SALARY"
		<< std::setw(12) << "EMPLOYESS"
		<< std::setw(15) << "UR NAME"
		<< std::setw(10) << "TYPE"
		<< std::setw(21) << "CHECK"
		<< std::setw(9) << "PROCENT"
		<< std::setw(11) << "SUM"
		<< std::setw(15) << "MODEL"
		<< std::setw(14) << "DATE"
		<< std::endl;
	std::cout << line << std::endl;
}

double Yrliz::TotalBalance() const
{
	double balance = this->balance;
	for (int i=0;i<this->zaimu.size();i++)
	{
		balance = balance - this->zaimu[i]->GetSum();
	}
	return balance;
}

void Yrliz::RegistrationOfServices()
{
	int choise;
	do
	{
		cout << "Выберите тип услуги\n";
		cout << "1. Оформить Эквайринг\n";
		cout << "2. Оформить займ\n";
		cout << "3. Выход\n";
		cout << "Выберети действие: ";
		choise = CreateInt(1, 3);
		system("pause");
		system("cls");
		if ((this->zaimu.size() + this->akvairu.size()) >= 4)
		{
			cout << "Вы превысили лимит услуг!" << endl;
			system("pause");
			system("cls");
			break;
		}
		switch (choise)
		{
		case 1:
		{
			if (this->akvairu.size() >= 2)cout << "Вы превысили лимит оформления эквайринга" << endl;
			else this->RegistrationAkvair();
		}
		break;
		case 2:
		{
			if (this->zaimu.size() >= 2)cout << "Вы превысили лимит оформления кредитов" << endl;
			else this->RegistrationZaim();
		}
		break;
		case 3:
		{
			break;
		}
		break;
		}
	} while (choise != 3);
}

std::ifstream& operator>>(std::ifstream& ifs, Yrliz& obj)
{
	char str[32];
	int in_type, count_zaimu = 0, count_akvairu = 0;
	double doubl_type;
	ifs.getline(str, 32, '!');
	obj.SetSurname(str);
	ifs.getline(str, 20, '!');
	obj.SetPersonalAccount(str);
	ifs >> in_type;
	obj.SetPinCode(in_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> doubl_type;
	obj.SetBalance(doubl_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> doubl_type;
	obj.SetSalary(doubl_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	obj.zaimu.clear();
	obj.akvairu.clear();
	ifs.getline(str, 20, '!');
	obj.SetYrName(str);
	ifs >> in_type;
	obj.SetNumberEmployess(in_type);
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> count_zaimu;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> count_akvairu;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < count_zaimu; i++)
	{
		SkipSpaces(ifs);
		Zaim a;
		obj.zaimu.push_back(a.clone());
		ifs >> static_cast<Zaim&>(*obj.zaimu[i]);
	}
	for (int i = 0; i < count_akvairu; i++)
	{
		SkipSpaces(ifs);
		Akvair a;
		obj.akvairu.push_back(a.clone());
		ifs >> static_cast<Akvair&>(*obj.akvairu[i]);
	}
	//ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

ofstream& operator<<(std::ofstream& ofs, Yrliz& obj)
{
	ofs << obj.surname << '!' << obj.personal_account << '!' << obj.pin_code << '!' << obj.balance << '!' << obj.salary << '!'
		<< obj.yr_name << '!' << obj.number_employees << '!'
		<< obj.zaimu.size() << '!' << obj.akvairu.size() << '!'<<'\n';
	for (int i = 0; i < obj.zaimu.size(); i++)
	{
		WriteSpaces(ofs);
		ofs << static_cast<Zaim&>(*obj.zaimu[i]);
	}
	for (int i = 0; i < obj.akvairu.size(); i++)
	{
		WriteSpaces(ofs);
		ofs << static_cast<Akvair&>(*obj.akvairu[i]);
	}
//	ofs << '\n';
	return ofs;
}

ostream& operator<<(std::ostream& os, const Yrliz& obj)
{
	int i =0, j=0;
	os << static_cast<const Klient&>(obj);
	cout << setiosflags(ios::left)
		<< setw(12) << obj.number_employees
		<< setw(15) << obj.yr_name<<endl;
	for (i = 0; i < obj.zaimu.size(); i++)
	{
		cout << setiosflags(ios::left)
			<< setw(94) << i + 1;
		std::cout << (*obj.zaimu[i]) << endl;
		j = i + 1;
	}
	for (i = 0; i < obj.akvairu.size(); i++)
	{
		cout << setiosflags(ios::left)
			<< setw(94) << j + 1 + i;
		std::cout << (*obj.akvairu[i]) << endl;
	}
	std::string line(170, '-');
	std::cout << line << std::endl;
	return os;
}

istream& operator>>(std::istream& in, Yrliz& obj)
{
	in >> static_cast<Klient&>(obj);
	ExaminationLine(obj.yr_name, "Название компании: ");
	cout << "Введите количество сотрудников(1-15): ";
	obj.number_employees = CreateInt(1, 15);
	int choise, count_zaim = 0, count_akvair = 0;
	do
	{
		cout << "Выберите тип услуги\n";
		cout << "1. Оформить Эквайринг\n";
		cout << "2. Оформить займ\n";
		cout << "3. Выход\n";
		cout << "Выберети действие: ";
	 choise = CreateInt(1, 3);
	 system("pause");
	 system("cls");
	 if ((obj.zaimu.size() + obj.akvairu.size()) >= 4)
	 {
		 cout << "Вы превысили лимит услуг!"<<endl;
		 system("pause");
		 system("cls");
		 break;
	 }
	switch (choise)
	{
	case 1:
	{
		if (obj.akvairu.size() >= 2)cout << "Вы превысили лимит оформления эквайринга" << endl;
		else obj.RegistrationAkvair();
	}
	break;
	case 2:
	{
		if (obj.zaimu.size() >= 2)cout << "Вы превысили лимит оформления займов"<< endl;
		else obj.RegistrationZaim();
	}
	break;
	case 3:
	{
		break;
	}
	break;
	}
}while (choise != 3);
	return in;
}
