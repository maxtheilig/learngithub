#include <iostream>
#include "matrix.h"

int main()
{
	const int rows1 = 3; const int cols1 = 3;
    double a1[rows1][cols1] = { {6,-2,1},{4,6,3},{-2,7,-5} };
    double v1[rows1] = {-7,8,40};
	const int rows2 = 3; const int cols2 = 3;
	double a2[rows2][cols2] = { {1,2,3},{4,5,6},{7,8,9} };
	double** ptr_a1 = new double* [rows1];
	for(int i=0; i<rows1; ++i){ptr_a1[i]= new double[cols1];
		for(int j=0; j<cols1; ++j){ptr_a1[i][j]=a1[i][j];}}
	Matrix matrix1{rows1,cols1,ptr_a1};
	/*matrix1.setToZero();
	std::cout << matrix1;
	matrix1.setToUnity();
	std::cout << matrix1;*/
    Vector vector1{rows1,v1};
	double** ptr_a2 = new double* [rows2];
	for(int i=0; i<rows2; ++i){ptr_a2[i]= new double[cols2];
		for(int j=0; j<cols2; ++j){ptr_a2[i][j]=a2[i][j];}}
	Matrix matrix2{rows2,cols2,ptr_a2};
    //vector1.printVector();
	matrix1.print();
    Vector lu = matrix1 / vector1;
    lu.printVector();
	Matrix addition = matrix1 + matrix2;
	Matrix combined = addition * matrix1;//=(a1+a2)*a1
	std::cout<< combined;
	return 0;
}
