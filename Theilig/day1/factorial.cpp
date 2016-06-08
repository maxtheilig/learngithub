#include <iostream>
#include <climits>
#include <stdlib.h>

unsigned int factorial(unsigned int x)
{
	unsigned int result = 1;
	while(x > 0)
	{
		result *= x;
		--x;
	}
	if(result == 0)
	{
		std::cout << "Warning: cannot display result because it is equal or bigger than the biggest allowed unsigned integer number: " << UINT_MAX << "." << std::endl;
		exit (EXIT_FAILURE);
	}
	return result;
}
unsigned int getValue();
int main()
{
	unsigned int x = getValue();
	std::cout << "You entered: " << x << std::endl;
	std::cout << x << "!=" << factorial(x) << std::endl;
	return 0;
} 

unsigned int getValue()
{
	while(true)
	{
		int x;
		std::cout << "Enter a POSITIVE number: ";
		std::cin >> x;
		if(x > 0)
			return x;
	}
};
		
