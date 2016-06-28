#include <iostream>
#include <cmath>
#include "vector.h"

int main()
{
	const int length = 3;
	double array1[length]= {3.0,4.0,5.0};
	double array2[length]= {10.0,11.0,12.0};
	
	Vector vector1(length, array1);
	Vector vector2(length, array2);
	std::cout << "Vectorclass Functionalities:"<< '\n' << std::endl;	
	std::cout << "vec1 : " << vector1 << "vec2 : " << vector2;
	std::cout << "size of vec1: " << vector1.getSize() << std::endl;
	std::cout << "2-norm of vec1: " << vector1.norm(2) << std::endl;
	vector2.setToZero();
	std::cout << "3rd element of vec 1: " << vector1(3) << std::endl;
	std::cout << "set to zero vec2: " << vector2;
	vector2.identity(3);
	std::cout << "set to identity vec2: " << vector2;
	vector2.resize(5);
	vector1.resize(5);
	std::cout << "resize vec2 to 5: " << vector2;
	std::cout << "resize vec1 to 5: " << vector1;
	std::cout << "vec1 + vec2 = " << vector1 + vector2;
	std::cout << "vec1 - vec2 = " << vector1 - vector2;
	std::cout << "vec1 * vec2 = " << vector1 * vector2 << std::endl;
	std::cout << "vec2 * 3 = " << vector2*3;
	std::cout << "0.2 * vec2 = " << 0.2*vector2;
	std::cin >> vector2;
	std::cout << "you entered vector: " << vector2;
	return 0;
}
