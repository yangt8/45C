#include <iostream>
#include <string>

#include "input.hpp"
#include "output.hpp"
#include "calculating.hpp"


int main()
{
	unsigned int number1, number2,number3,number4;

	std::cin >> number1;
    double* x = new double[number1];
    double* y = new double[number1];
    build_array(x, number1);
    build_array(y, number1);


    std::cin >> number2;
    student** stu = new student*[number2];
    for (unsigned int i=0; i<number2; i++)
	{
		stu[i] = new student;
		student_info(stu[i], number1);
    }


    std::cin >> number3;
    double** scores = new double*[number3];
    for (unsigned int i=0; i<number3; i++)
	{
		scores[i] = new double[number1+1];
		build_array(scores[i], number1+1);

		for (unsigned int j=0; j<number2; j++)
		{
			if (stu[j]-> id == scores[i][0])
				stu[j]-> score = calculate_total(x, y, scores[i], number1);
		}
		delete[] scores[i];
    }
    print_scores(stu,number2);


	std::cin >> number4;
    for (unsigned int i=1; i<=number4; i++)
	{
		double *cutpoint = new double[4];
		build_array(cutpoint, 4);
        determing_grades(stu,cutpoint,number2);
		std::cout << "CUTPOINT SET " << i << std::endl;
		print_grades(stu,number2);
		delete[] cutpoint;
    }  

    for (unsigned int i=0; i<number2; i++)
	{
		delete stu[i];
    }

    delete[] x;
    delete[] y;
    delete[] scores;
    delete[] stu;
    return 0;
}