#include "Fizliz.h"

Fizliz::Fizliz()
{
	this->pasport[0] = '\0';
	this->phone[0] = '\0';
	this->vkladu.clear();
	this->kreditu.clear();
}

Fizliz::Fizliz(const Fizliz& other) :Klient(other)
{
	strcpy_s(this->pasport, 10, other.pasport);
	strcpy_s(this->phone, 10, other.phone);
	this->vkladu = other.vkladu;
	this->kreditu = other.kreditu;
}

Fizliz::~Fizliz()
{
	this->vkladu.clear();
	this->kreditu.clear();
}

char* Fizliz::GetPhone()
{
	return this->phone;
}

char* Fizliz::GetPasport()
{
	return this->pasport;
}

void Fizliz::SetPhone(char phone[])
{
	strcpy_s(this->phone, 10, phone);
}

void Fizliz::SetPasport(char pasport[])
{
	strcpy_s(this->pasport, 10, pasport);
}

size_t Fizliz::GetKredituSize()
{
	return this->kreditu.size();
}

size_t Fizliz::GetVkladuSize()
{
	return this->vkladu.size();
}

vector<Kredit*>& Fizliz::GetKreditu()
{
	return this->kreditu;
}

vector<Vklad*>& Fizliz::GetVkladu()
{
	return this->vkladu;
}

void Fizliz::RegistrationVklad()
{
	Vklad obj;
	obj.Cap();
	ifstream ifs("Vklad.txt", ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << "Human.txt";
		system("pause");
	}
	int i = 0 ,choise;
	vector<Vklad*> local;
	while (ifs >> obj)
	{
		obj.Output(++i);
		local.push_back(obj.clone());
		cout << endl;
	}
	ifs.close();
	if (i==0) cout << "К сожалению в банке сейчас нет доступных вкладов." << endl;
	else
	{
	choise = CreateInt(1, i);
	if (local[choise - 1]->GetSum() > this->GetBalance()) cout << "У вас не хватает средств!" << endl;
	else
	{
		this->vkladu.push_back(local[choise - 1]->clone());
		this->vkladu[this->vkladu.size() - 1]->SetAccountNumber(GenerateCountingServices("GenerateSchet.txt"));
		this->balance = this->balance - this->vkladu[this->vkladu.size() - 1]->GetSum();
	}
	}
}

void Fizliz::RegistrationKredit()
{

	Kredit obj;
	obj.Cap();
	ifstream ifs("Kredit.txt", ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << "Human.txt";
		system("pause");
	}
	int i = 0, choise;
	vector<Kredit*> local;
	while (ifs >> obj)
	{
		obj.Output(++i);
		local.push_back(obj.clone());
		cout << endl;
	}
	ifs.close();
	if(i==0) cout << "К сожалению в банке сейчас нет доступных кредитов." << endl;
	else
	{
	choise = CreateInt(1, i);
	if (local[choise - 1]->GetMonthlyFee() > (this->GetSalary() * 0.4)) cout << "У вас не соответствует зароботная плата!" << endl;
	else
	{
		this->kreditu.push_back(local[choise - 1]->clone());
		this->kreditu[this->kreditu.size() - 1]->SetAccountNumber(GenerateCountingServices("GenerateSchet.txt"));
		this->balance = this->balance + this->kreditu[this->kreditu.size() - 1]->GetSum();
		this->kreditu[this->kreditu.size() - 1]->SetSum((this->kreditu[this->kreditu.size() - 1]->GetSum() + (this->kreditu[this->kreditu.size() - 1]->GetSum() * this->kreditu[this->kreditu.size() - 1]->GetInterestRate() / 100)));
	}
	}
}

void Fizliz::DeletionUnderIndex(int index)
{
	this->vkladu.erase(vkladu.begin()+index);
}

void Fizliz::Cap() const
{
	std::string line(170, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "SURNAME"
		<< std::setw(21) << "CARD NUMBER"
		<< std::setw(6)  << "CODE"
		<< std::setw(10) << "BALANCE"
		<< std::setw(10) << "SALARY"
		<< std::setw(12) << "PASPORT"
		<< std::setw(12) << "PHONE"
		<< std::setw(10) << "TYPE"
		<< std::setw(21) << "CHECK"
		<< std::setw(9) << "PROCENT"
		<< std::setw(11) << "SUM"
		<< std::setw(6) << "TIME"
		<< std::setw(14) << "PAYMENT"
		<< std::setw(8) << "REFILL"
		<< std::endl;
	std::cout << line << std::endl;
}

double Fizliz::TotalBalance() const
{
	double balance=this->balance;
	for (int i=0;i<this->kreditu.size();i++)
	{
		balance = balance - this->kreditu[i]->GetSum();
	}
	for (int i = 0; i < this->vkladu.size(); i++)
	{
		balance = balance + this->vkladu[i]->GetSum();
	}

	return balance;
}

void Fizliz::RegistrationOfServices()
{
	int choise;
	do
	{
		cout << "Выберите тип услуги\n";
		cout << "1. Оформить вклад\n";
		cout << "2. Оформить кредит\n";
		cout << "3. Выход\n";
		cout << "Выберети действие: ";
		choise = CreateInt(1, 3);
		system("pause");
		system("cls");
		if ((this->kreditu.size() + this->vkladu.size()) >= 4)
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
			if (this->vkladu.size() >= 2)cout << "Вы превысили лимит оформления вкладов" << endl;
			else this->RegistrationVklad();
		}
		break;
		case 2:
		{
			if (this->kreditu.size() >= 2)cout << "Банк не предоставляет более двух кредитов" << endl;
			else this->RegistrationKredit();
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

Fizliz& Fizliz::operator=(const Fizliz& other)
{
	Klient::operator=(other);
	strcpy_s(this->pasport, 10, other.pasport);
	strcpy_s(this->phone, 10, other.phone);
	this->vkladu = other.vkladu;
	this->kreditu = other.kreditu;
	return *this;
}

std::ofstream& operator<<(std::ofstream& ofs, Fizliz& obj)
{
	ofs << obj.surname << '!' << obj.personal_account << '!' << obj.pin_code << '!' << obj.balance << '!' << obj.salary << '!'
		<< obj.pasport << '!' << obj.phone << '!'
		<< obj.vkladu.size() << '!' << obj.kreditu.size() << '!'<<'\n';
	for (int i = 0; i < obj.vkladu.size(); i++)
	{
		WriteSpaces(ofs);
		ofs << static_cast<Vklad&>(*obj.vkladu[i]);
	}
	for (int i = 0; i < obj.kreditu.size(); i++)
	{
		WriteSpaces(ofs);
		ofs << static_cast<Kredit&>(*obj.kreditu[i]);
	}
	//ofs << '\n';
	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Fizliz& obj)
{
	char str[32];
	int count_vkladu = 0, count_kreditu = 0;
	int in_type;
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
	obj.vkladu.clear();
	obj.kreditu.clear();
	ifs.getline(str, 10, '!');
	obj.SetPasport(str);
	ifs.getline(str, 10, '!');
	obj.SetPhone(str);
	ifs >> count_vkladu;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs >> count_kreditu;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '!');
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < count_vkladu; i++)
	{
		SkipSpaces(ifs);
		Vklad a;
		obj.vkladu.push_back(a.clone());
		ifs >> static_cast<Vklad&>(*obj.vkladu[i]);
	}
	for (int i = 0; i < count_kreditu; i++)
	{
		SkipSpaces(ifs);
		Kredit a;
		obj.kreditu.push_back(a.clone());
		ifs >> static_cast<Kredit&>(*obj.kreditu[i]);
	}
	//ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

ostream& operator<<(std::ostream& os, const Fizliz& obj)
{
	int i=0, j=0;
	os << static_cast<const Klient&>(obj);
	cout << setiosflags(ios::left)
		<< setw(12) << obj.pasport
		<< setw(12) << obj.phone<<endl;
	for (i = 0; i < obj.kreditu.size(); i++) 
	{
		cout << setiosflags(ios::left)
			<< setw(91) << i + 1;
		std::cout << (*obj.kreditu[i]) << endl;
		j = i+1;
	}
	for (i = 0; i < obj.vkladu.size(); i++)
	{
		cout << setiosflags(ios::left)
			<< setw(91) << j + 1+i;
		std::cout << (*obj.vkladu[i]) << endl;
	}
	std::string line(170, '-');
	std::cout << line << std::endl;
	return os;
}

istream& operator>>(std::istream& in, Fizliz& obj)
{
	in >> static_cast<Klient&>(obj);
	CheckTelefon(obj.phone);
	CheckPassport(obj.pasport);
	int choise, count_kredit = 0, count_vklad = 0;
	do
	{
		cout << "Выберите тип услуги\n";
		cout << "1. Оформить вклад\n";
		cout << "2. Оформить кредит\n";
		cout << "3. Выход\n";
		cout << "Выберети действие: ";
		choise = CreateInt(1, 3);
		system("pause");
		system("cls");
		if ((obj.kreditu.size()+obj.vkladu.size()) >= 4)
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
			if (obj.vkladu.size() >= 2)cout << "Вы превысили лимит оформления вкладов" << endl;
			else obj.RegistrationVklad();
		}
		break;
		case 2:
		{
			if (obj.kreditu.size()>=2)cout << "Банк не предоставляет более двух кредитов"<<endl;
			else obj.RegistrationKredit();
		}
		break;
		case 3:
		{
			break;
		}
		break;
		}
	} while (choise != 3);
	return in;
}
