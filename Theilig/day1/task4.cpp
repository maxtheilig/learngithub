#include <iostream>

void primeFactorisation(int);

int main()
{
	int x;
	int flag=0;
	std::cout << "Enter a number: ";
	std::cin >> x;
	for (int i = 2; i <= x/2; ++i)
	{
		if (x%i==0)
		{
			flag=1;
			break;
		}
	}
	if (x==1)
		std::cout << 1 << "is not a prime number." << std::endl;
	else if (flag==0)
		std::cout << x << " is a prime number." << std::endl;
	else
		{
		std::cout << x << " is not a prime number." << std::endl;
		primeFactorisation(x);
		}
	return 0;
}

void primeFactorisation(int x)
{
	std::cout << "The number can be factorised to: ";
	int div = 2;
	while(x!=0)
	{
		if(x%div!=0)
			++div;
		else
		{
			x = x / div;
			std::cout << div << " ";
			if(x==1)
				break;
		}
	}
	std::cout << std::endl;
}
