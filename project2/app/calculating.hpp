#include <iostream>
#include "input.hpp"

#ifndef CALCULATE_HPP
#define CALCULATE_HPP

// This header file contains declarations for functions "calculate_total" and "determing_grades"


double calculate_total(double* x, double* y, double* z, int size);
void determing_grades(student** stu,double* cutpoint,int size);

#endif