#include <iostream>
#include <fstream>
#include <cmath>

double f(double x)
{
	return pow(x, 2);
}

double threePoint(double (*func)(double),double x, double h)
{
	return (func(x + h) - func(x - h)) / (2 * h);
}

int main()
{
	std::ofstream myfile;
	myfile.open ("derivate.txt");
	double h = 0.01;
	double x = 0.0;
	for (int i = 0; i < 101; ++i)
	{
		double x = x + h;
		myfile  << threePoint(f, x, h) << " " << x << "\n";
	}	
	myfile.close();
	return 0;
}
