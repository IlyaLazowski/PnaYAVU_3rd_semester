#pragma once
#include "Human.h"

class UnionMember :virtual public Human
{
protected:
	char party_name[32];
	char post[32];
public:
	UnionMember();
	UnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char post[]);
	UnionMember(const UnionMember& other);
	~UnionMember();
	virtual void Cap()const override;
	char* GetPartyName();
	char* GetPost();
	void SetPartyName(char* party_name);
	void SetPost(char* post);
	friend fstream& operator<<(std::fstream& fs, UnionMember& obj);
	friend fstream& operator>>(std::fstream& fs, UnionMember& obj);
	friend ofstream& operator<<(std::ofstream& ofs, UnionMember& obj);
	friend ifstream& operator>>(std::ifstream& ifs, UnionMember& obj);
	friend ostream& operator<<(std::ostream& os, const UnionMember& obj);
	friend istream& operator>>(std::istream& in, UnionMember& obj);
	UnionMember& operator=(const UnionMember& other);
	bool operator==(UnionMember& other);
};
