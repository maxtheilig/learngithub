#include <iostream>
#include "printArray.h"

int main()
{
	const int rows = 20;
	const int cols = 20;
	int array[rows][cols];
	for(int i=0; i<rows; ++i)
	{
		for(int j=0; j<20; ++j)
			array[i][j]=(i+1)*(j+1);
	}
	printArray(*array, rows, cols);
	return 0;
}


