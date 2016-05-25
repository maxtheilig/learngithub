#include <iostream>
#include "printArray.h"

void addArrays(int* res, int* a1, int* a2, int rows, int cols)
{
	for(int i=0; i<(rows*cols); ++i)
	{
		res[i] = 0;
		res[i] = a1[i]+a2[i];
	}
}

void multiQuadArrays(int* res, int *a1, int *a2, int rows, int cols)
{
	for(int j=0; j<cols; ++j)
	{
	for(int k=0; k<rows; ++k)
	{
		for(int i=0; i<cols; ++i)
		{																
		std::cout << a1[(j*cols)+i] << "\t" <<a2[(i*cols)+k] << std::endl;
		res[k+cols*j]=res[k+cols*j]+a1[(j*cols)+i]*a2[(i*cols)+k];
		}
	}
	}
}
	
int main()
{
	const int rows1 = 3;
	const int cols1 = 3;
	const int rows2 = 3;
	const int cols2 = 3;
	int a1[rows1][cols1] = { {1,2,3},{4,5,6},{1,3,7} };
	int a2[rows2][cols2] = { {1,2,3},{3,4,4},{5,6,4} };
	int res[rows1][cols2] = {0};
	multiQuadArrays(*res, *a1, *a2, rows1, cols1);
	printArray(*res, rows1, cols1);
}
