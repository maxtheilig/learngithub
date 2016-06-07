#include <iostream>
#include <cmath>
#include <climits>

void primeFactorisation(int);
bool isPrime(const unsigned int x);
int getValue();
void checkIfNumberIsPrimeAndIfNotPrintItsPrimeFactorisation(unsigned int x);

int main()
{
	checkIfNumberIsPrimeAndIfNotPrintItsPrimeFactorisation(getValue());
	return 0;
}

int getValue()
{
	std::cout << "Enter a positive number: ";
	unsigned int x;
	std::cin >> x;
	if(x==UINT_MAX)
		std::cout << "Error: number is too big" << std::endl;
	return x;
}

bool isPrime(const unsigned int x)
{
	if(x==1)
		return false;
	for(unsigned int i=2; i<sqrt(x); ++i)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

void primeFactorisation(int x)
{
	std::cout << "The number can be factorised to: ";
	unsigned int div = 2;
	while(x!=0)
	{
		if(x%div!=0)
			++div;
		else
		{
			x /= div;
			std::cout << div << " ";
			if(x==1)
				break;
		}
	}
	std::cout << std::endl;
}

void checkIfNumberIsPrimeAndIfNotPrintItsPrimeFactorisation(unsigned int x)
{
	if(isPrime(x))
		std::cout << x << " is prime." << std::endl;
	else
	{
		std::cout << x << " is not prime." << std::endl;
		primeFactorisation(x);
	}
}
