#include <iostream>
#include <string>

#ifndef INPUT_HPP
#define INPUT_HPP


// This header file contains declarations for functions "build_array" and "student_info" and create a struct "student".

struct student
{
	unsigned int id;
	double score;
	std::string grade_option, name, grade;
};

void build_array(double* a, int size);
void student_info(student* s, int size);


#endif 