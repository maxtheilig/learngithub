#include <iostream>
#include <cmath>
double fzero(double x)
{
	return x*x-1;
}

double newton(double (*f)(double), double x0, double eps, int maxiter)
{
	double x = x0;
	double xold = x0 - 0.1;
	double xnew;
	for (int i = 0; i < maxiter; ++i)
	{
		if ( fabs(x - xold) < eps)
			return x;
		xnew = x - ((x - xold) / (f(x) - f(xold))) * f(x);
		xold = x;
		x = xnew;
	}
	return x;
}

int main()
{
	double x0 = 0.5;
	double eps = 0.00001;
	int maxiter = 20;
	std::cout << "Nullstelle=" <<  newton(fzero, x0, eps, maxiter) << std::endl;
	return 0;
}
