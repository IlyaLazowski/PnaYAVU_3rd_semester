#pragma once
#include"TeacherUnionMember.h"
using namespace std;

template<typename T>
 inline string file_name()
{
	return "C++";
}

template<>
inline string file_name<Human>()
{
	return "Human";
}

template<>
inline string file_name<Teacher>()
{
	return "Teacher";
}

template<>
inline string file_name<UnionMember>()
{
	return "UnionMember";
}

template<>
inline string file_name<TeacherUnionMember>()
{
	return "TeacherUnionMember";
}

