#include <iostream>
#include "vector.h"

int main()
{
	const int length1 = 4;
    const int length2 = 4;
	int vec1[length1] = {1,2,3,4};
    int vec2[length2] = {4,3,2,1};
	Vector vector1{length1,vec1};
	std::cout << vector1;
    Vector vector2{length2,vec2};
    vector1.printVector();
	vector2.printVector();
	Vector plus = add(vector1, vector2);
	plus.printVector();
	Vector sumvec = vector1 - vector2;
	sumvec.printVector();
	return 0;
}
