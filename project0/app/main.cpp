#include <iostream>

int main()
{
	int i;
	std::cin >> i ;
	int a;
	int b;
	int c;
	int d;
	std::string s = "";
	b = 2*i + 1;
	for (a=1; a<=i; a++)
	{
		for (d=1; d<=i-a; d++)
		{
			std::cout << " ";
		}
		
		for (c=1; c<=2*a+1; c++)
		{

		    std::cout << "*";
		}
		std::cout << std::endl;

		for (d=1; d<=i-a; d++)
		{
			std::cout << " ";
		}
		for (c=1; c<=2*a+1; c++)
		{
			if (c%2 == 0)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << "*";
			}
		    
		}	
		std::cout << std::endl;
	}
	while (b!=0)
	{
		s+='*';
		b--;
	}
	std::cout << s << std::endl;
	return 0;
}


