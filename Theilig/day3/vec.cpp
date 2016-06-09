#include <iostream>
#include "vector.h"
#include "matrix.h"

int main()
{
	const int length1 = 4;
    const int length2 = 4;
	const int length3 = 4;
	double vec1[length1] = {1.0,2.0,3.0,4.0};
    double vec2[length2] = {4.0,3.0,2.0,1.0};
	double vec3[length3] = {1.0,3.0,5.0,7.0};
	Vector vector1{length1,vec1};
    Vector vector2{length2,vec2};
	Vector vector3{length3,vec3};
	//vector1.setToZero();
	Vector addition = vector1 + vector2;
	std::cout << addition;
	double combined = addition * vector3;
	std::cout << "(v1+v2)*v3=" << combined << std::endl;
    /*vector1.printVector();
	vector2.printVector();
	Vector plus = add(vector1, vector2);
	plus.printVector();
	Vector sumvec = vector1 - vector2;
	sumvec.printVector();*/
	return 0;
}
