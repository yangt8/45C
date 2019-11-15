#include "output.hpp"

// This file contaisn the definition of "print_scores" and "print_grades"
// "print_scores" is for printing the students information and total scores.
// "print_grades" is for printing the students information andfinal grades.

void print_scores(student** stu,int size)
{
	std::cout << "TOTAL SCORES" << std::endl;
    for (unsigned int j=0; j<size; j++)
	{
		std::cout << stu[j]-> id << " " << stu[j]-> name << " " << stu[j]-> score <<std::endl;
	}
}



void print_grades(student** stu,int size)
{
    for (unsigned int j=0; j<size; j++)
		{
			std::cout << stu[j]->id << " " << stu[j]->name << " " << stu[j]-> grade <<std::endl;
		}
}
