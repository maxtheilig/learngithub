#include <iostream>
#include <cmath>

double simpsonIntegration( double (*function)(double), double xstart, double xend, double deltax)
{
	double result = 0;
	double functionparam = xstart;
	while ( functionparam < xend )
	{
		result += deltax/6 *(function(functionparam)+4*function(functionparam+deltax/2)+function(functionparam+deltax));
		functionparam += deltax;
	}
	return result;
}

double trapezIntegration(double (*function)(double), double xstart, double xend, double deltax)
{
         double result = 0;
         double functionparam = xstart;
         while ( functionparam < xend )
         {
                 result += deltax/2 *(function(functionparam)+function(functionparam+deltax));
                 functionparam += deltax;
         }
         return result;
}

double midpointIntegration(double (*function)(double), double xstart, double xend, double deltax)
{
         double result = 0;
         double functionparam = xstart;
         while ( functionparam < xend )
         {
                 result += deltax * function(functionparam+deltax/2);
                 functionparam += deltax;
         }
         return result;
}

double function1(double x) { return 8*x;}
double function2(double x) { return 3*x*x;}
double function3(double x) { return x*x*x;}

int main()
{
	double xstart = 0;
	double xend = 4;
	double deltax = 0.1;
	
	std::cout << "exact values: 64" << std::endl;
	std::cout << "simsonintegration:" << std::endl;
	std::cout << simpsonIntegration(function1, xstart, xend, deltax) << '\t' << simpsonIntegration(function2, xstart, xend, deltax) << '\t' << simpsonIntegration(function3, xstart, xend, deltax) << std::endl;
	std::cout << "trapezintegration:" << std::endl;
	std::cout << trapezIntegration(function1, xstart, xend, deltax) << '\t'<< trapezIntegration(function2, xstart, xend, deltax) << '\t' << trapezIntegration(function3, xstart, xend, deltax) << std::endl;
	std::cout << "midpointintegration:" << std::endl;
	std::cout << midpointIntegration(function1, xstart, xend, deltax) << '\t'<< midpointIntegration(function2, xstart, xend, deltax) << '\t' << midpointIntegration(function3, xstart, xend, deltax) << std::endl; 
	
	return 0;
}
