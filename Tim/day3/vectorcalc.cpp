#include <iostream>
#include <cmath>
#include "vector.h"

int main()
{
	const int length = 3;
	double array1[length]= {3.0,4.0,5.0} ;
	double array2[length]= {10.0,11.0,12.0} ;
	
	Vector vector1(length, array1);
	Vector vector2(length, array2);
	
	std::cout << vector1;

	return 0;
}
