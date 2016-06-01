#include <iostream>
#include "matrix.h"

int main()
{
	const int rows1 = 3; const int cols1 = 3;
    double a1[rows1][cols1] = { {6,-2,1},{4,6,3},{-2,7,-5} };
    double v1[rows1] = {-7,8,40};
	/*const int rows2 = 2; const int cols2 = 2;
	double a2[rows2][cols2] = { {1,2},{4,5} };*/
	double** ptr_a1 = new double* [rows1];
	for(int i=0; i<rows1; ++i){ptr_a1[i]= new double[cols1];
		for(int j=0; j<cols1; ++j){ptr_a1[i][j]=a1[i][j];}}
	Matrix matrix1{rows1,cols1,ptr_a1};
    Vector vector1{rows1,v1};
    //vector1.printVector();
	matrix1.print();
    Vector lu = matrix1 / vector1;
    lu.printVector();
	//std::cout << matrix1;
	/*double** ptr_a2 = new double* [rows2];
	for(int i=0; i<rows2; ++i){ptr_a2[i]= new double[cols2];
		for(int j=0; j<cols2; ++j){ptr_a2[i][j]=a2[i][j];}}
	Matrix matrix2{rows2,cols2,ptr_a2};
	matrix2.print();
	Matrix summat = matrix1 * matrix2;
	summat.print();
	int x = 2;
	Matrix scalar = x * matrix1;
	scalar.print();*/
	return 0;
}
