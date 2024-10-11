#include "TeacherUnionMember.h"

int main()
{
	
	system("color 9");
	TeacherUnionMember a;
	cin >> a;
	cout << "\n___________________________________________________________\n\n";
	cout << a;
	char str[32] = "VMSIS";
	a.SetSpeciality(str);
	cout << "___________________________________________________________" << endl;
	cout << "Object after set speciality:" << endl << endl;
	cout << a << endl;

	return 0;
}