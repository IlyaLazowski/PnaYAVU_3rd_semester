#include "Human.h"

class UnionMember :virtual public Human
{
protected:
	char party_name[32];
	char autobiography[3][64];
public:
	UnionMember();
	UnionMember(char name[], char surname[], char data_of_birdth[], char party_name[], char autobiografi[][64]);
	UnionMember(const UnionMember& other);
	friend ostream& operator<<(std::ostream& os, const UnionMember& obj);
	friend istream& operator>>(std::istream& in, UnionMember& obj);
	char* GetPartyName();
	char(*GetAutobiography())[64];
	void SetPartyName(char* party_name);
	void SetAutobiography(char autobiography[][64]);
	~UnionMember();
};

