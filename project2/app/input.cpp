#include "input.hpp"

// This file contaisn the definition of "build_array" and "student_info"
// "build_array" is for building a array.
// "student_infos" is to give some information to the struct.


void build_array(double* a, int size)
{	
    for (unsigned int i=0; i<size; i++)
	{
		std::cin >> a[i];
    }
}


void student_info(student* s, int size)
{
	std::cin >> s->id;
	std::cin >> s->grade_option;
	std::cin.ignore(1);
	std::getline(std::cin,s->name);
	s->score = 0;
	s->grade = "P";
}