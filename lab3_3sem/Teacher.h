#include "Human.h"

class Teacher :virtual public Human
{
protected:
	char post[32];     //должность 
	char speciality[32];
	char scientific_works[5][32]; // научные работы
public:
	Teacher();
	Teacher(char name[], char surname[], char data_of_birdth[], char post[], char speciality[], char scientific_works[][32]);
	Teacher(const Teacher& other);
	friend ostream& operator<<(std::ostream& os, const Teacher& obj);
	friend istream& operator>>(std::istream& in, Teacher& obj);
	char* GetPost();
	char* GetSpeciality();
	char(*GetScientificWorks())[32];
	void SetPost(char post[]);
	void SetSpeciality(char speciality[]);
	void SetScientificWorks(char scientific_works[][64]);
	~Teacher();
};
