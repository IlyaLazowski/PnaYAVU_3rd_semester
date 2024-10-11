#include "Klient.h"

char Klient::count_klient[20] = "6000 0000 0000 0000";
char Klient::count_schet[20] = "7711 0000 0000 0000";


Klient::Klient()
{
	this->balance = 0;
	this->surname[0] = '\0';
	this->personal_account[0] = '\0';
	this->pin_code = 0;
	this->salary = 0;
}



Klient::Klient(const Klient& other)
{
	strcpy_s(this->personal_account, 20, other.personal_account);
	strcpy_s(this->surname, 32, other.surname);
	this->balance = other.balance;
	this->pin_code = other.pin_code;
	this->salary = other.salary;
}

Klient::Klient(char surname[], char personal_account[], double balance , int pin_code , double salary)
{
	strcpy_s(this->personal_account, 20, personal_account);
	strcpy_s(this->surname, 32, surname);
	this->balance = balance;
	this->pin_code = pin_code;
	this->salary = salary;
}

Klient::~Klient()
{

}

char* Klient::GetPersonalAccount()
{
	return this->personal_account;
}

char* Klient::GetSurname()
{
	return this->surname;
}

double Klient::GetBalance()
{
	return this->balance;
}

double Klient::GetSalary()
{
	return this->salary;
}

int Klient::GetPinCode()
{
	return this->pin_code;
}

void Klient::SetPersonalAccount(char personal_account[])
{
	strcpy_s(this->personal_account,20, personal_account);
}

void Klient::SetSurname(char surname[])
{
	strcpy_s(this->surname, 32, surname);
}

void Klient::SetSalary(double salary)
{
	this->salary=salary;
}

void Klient::SetBalance(double balance)
{
	this->balance = balance;
}

void Klient::Cap() const
{
	std::string line(65, '~');
	std::cout << line << std::endl;
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(20) << "SURNAME"
		<< std::setw(21) << "CARD NUMBER"
		<< std::setw(6) << "CODE"
		<< std::setw(10) << "BALANCE"
		<< std::setw(10) << "SALARY"
		<< std::endl;
	std::cout << line << std::endl;
}

void Klient::SetPinCode(int pin_code)
{
	this->pin_code = pin_code;
}

void Klient::RegistrationOfServices()
{
	cout << "Вы не можете работать с услугами так как вы обычный клиент" << endl;
}

double Klient::TotalBalance() const
{
	return this->balance;
}

bool Klient::operator<(Klient& other)
{
	if (this->salary > other.salary) return true;
	else return false;
}

bool Klient::operator>(Klient& other)
{
	if (this->balance>other.balance) return true;
	else return false;
}

Klient& Klient::operator=(const Klient& other)
{
	strcpy_s(this->personal_account, 20, other.personal_account);
	strcpy_s(this->surname, 32, other.surname);
	this->balance = other.balance;
	this->pin_code = other.pin_code;
	this->salary = other.salary;
	return *this;
}

bool Klient::operator==(Klient& other)
{
	if (other.salary != 0)
		if (this->salary != other.salary)
			return false;
	if (other.balance != 0)
		if (this->balance!= other.balance)
			return false;
	return true;
}

std::ofstream& operator<<(std::ofstream& ofs, Klient& obj)
{
	ofs << obj.surname << '!' << obj.personal_account << '!' << obj.pin_code<<'!'<<obj.balance << '!' << obj.salary << '!' << '\n';
	return ofs;
}

ifstream& operator>>(std::ifstream& ifs, Klient& obj)  // изменить!!!!!
{
	char str[32];
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
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ifs;
}

std::ostream& operator<<(std::ostream& os, const Klient& obj)
{
	cout << setiosflags(ios::left)
		<< setw(20) << obj.surname
		<< setw(21) << obj.personal_account
		<< setw(6) << obj.pin_code
		<< setw(10) << obj.balance
	    << setw(10) << obj.salary;
	return os;
}

std::istream& operator >> (std::istream& in, Klient& obj)
{
	CreateName(obj.surname, "Введите фамилию: ");
	incrementNumber(obj.count_klient);
	strcpy_s(obj.personal_account, 20, GenerateCountingServices("GeneratePersonalAccount.txt"));
	cout << "Вам сгенерирован лицевой счёт: "<<obj.personal_account << endl;
	std::srand(static_cast<unsigned int>(std::time(0)));
	obj.pin_code = std::rand() % 9001 + 1000;
	cout << "Вам сгенерирован пин-код: "<<obj.pin_code << endl;
	cout << "Введите начальную сумму для загрузки на лицевой счет(от 100 до 4500): ";
	obj.balance = CreateDouble(100.0, 4500.0);
	cout << "Введите вашу зарплату(0 до 10 000): ";
	obj.salary = CreateDouble(0.0, 10000.0);
	return in;
}

