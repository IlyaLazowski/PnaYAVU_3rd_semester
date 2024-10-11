#pragma once
#include "Teacher.h"
#include "UnionMember.h"

class TeacherUnionMember :public UnionMember, public Teacher
{
	char work_performed[32]; // работа в партии
public:
	TeacherUnionMember();
	TeacherUnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char post[], char speciality[], char read_coorse[], char work_performed[]);
	TeacherUnionMember(const TeacherUnionMember& other);
	virtual void Cap()const override;
	~TeacherUnionMember();
	char* GetWorkPerformed();
	void SetWorkPerformed(char work_performed[]);
	TeacherUnionMember& operator=(const TeacherUnionMember& other);
	friend ostream& operator<<(std::ostream& os, TeacherUnionMember& obj);
	friend istream& operator>>(std::istream& in, TeacherUnionMember& obj);
};