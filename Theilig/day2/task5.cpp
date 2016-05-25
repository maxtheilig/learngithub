#include <iostream>
#include <cmath>

double simpsonInt(double (*func)(double), double start, double stop, double step_size)
{
	double val = 0;
	double x = start;
	int steps = fabs(stop-start) / step_size;
	for(int i=0; i<=steps; ++i)
	{
	val = val + step_size/6 * (func(x)+4*func(x+step_size/2)+func(x+step_size));
	x = x + step_size;
	}
	return val;
}


double square(double x)
{
	return x*x;
}

int main()
{
	double start = 1.0;
	double end = 2.0;
	double step_size = 0.1;
	double res = simpsonInt(square,start,end,step_size);
	std::cout << res << std::endl;
	return 0;
}	
