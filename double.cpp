#include <iostream>

int getValue()
{
	std::cout << "Gib eine Zahl ein!" << std::endl;
	int x;
	std::cin >> x;
	return x;
}

int doubleNumber(int x)
{
	return 2*x;
}

int main()
{
	std::cout << doubleNumber( getValue() ) << std::endl;
}

