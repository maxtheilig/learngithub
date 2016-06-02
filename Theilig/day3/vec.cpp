#include <iostream>
#include "vector.h"
#include "matrix.h"

int main()
{
	const int length1 = 4;
    const int length2 = 4;
	double vec1[length1] = {1.0,2.0,3.0,4.0};
    double vec2[length2] = {4.0,3.0,2.0,1.0};
	Vector vector1{length1,vec1};
	std::cout << vector1;
	double n = vector1.norm(4);
	std::cout << n << std::endl;
    Vector vector2{length2,vec2};
	double x = vector1 * vector2;
	std::cout << "v1*v2=" << x << std::endl;
    /*vector1.printVector();
	vector2.printVector();
	Vector plus = add(vector1, vector2);
	plus.printVector();
	Vector sumvec = vector1 - vector2;
	sumvec.printVector();*/
	return 0;
}
