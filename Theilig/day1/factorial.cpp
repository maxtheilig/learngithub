#include <iostream>

int factorial(int x)
{
	int y=1;
	while(x > 0)
	{
		y = y * x;
		--x;
	}
	return y;
}

int main()
{
	int x;
	std::cout << "Enter a number: ";
	std::cin >> x;
	std::cout << x << "!=" << factorial(x) << std::endl;
	return 0;
} 
