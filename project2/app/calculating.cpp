#include "calculating.hpp"

// This file contaisn the definition of "calculate_total" and "determing_grades"
// "calculate_total" is for calculating the total grades of the student and return it.
// "determing_grades" is to get the final grades of the student.


double calculate_total(double* x, double* y, double* z, int size)

{
    double r = 0;
    for (unsigned int i=0; i<size; i++)
    {
        r += (z[i+1]*y[i])/x[i];
    }
    return r;
}



void determing_grades(student** stu, double* cutpoint, int size)
{
    for (unsigned int j=0; j<size; j++)
        {
            if (stu[j]-> score > cutpoint[0])
            {
                if (stu[j]-> grade_option == "G")
                {
                    stu[j]-> grade = "A";
                }
            }
            else if (stu[j]-> score > cutpoint[1])
            {
                if (stu[j]-> grade_option == "G")
                {
                    stu[j]-> grade = "B";
                }
            }
            else if (stu[j]-> score > cutpoint[2])
            {
                if (stu[j]-> grade_option == "G")
                {
                    stu[j]-> grade = "C";
                }
            }
            else if (stu[j]-> score > cutpoint[3])
            {
                if (stu[j]-> grade_option == "G")
                {
                    stu[j]-> grade = "D";
                }
                else
                {
                    stu[j]-> grade = "NP";
                }
            }
            else
            {
                if (stu[j]-> grade_option == "G")
                {
                    stu[j]-> grade = "F";
                }
                else
                {
                    stu[j]-> grade = "NP";
                }
            }
        }   
}
