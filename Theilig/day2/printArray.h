#ifndef PRINTARRAY_H
#define PRINTARRAY_H

void printArray(int* a1, int rows, int cols)
{
	for(int i=0; i<(rows*cols); ++i)
	{
		int* ptr = &a1[i];
		std::cout << *ptr;
		if((i+1)%cols==0){std::cout << std::endl;}
		else {std::cout << "\t";}
	}
}

void printArray(int *array, int length)
{
	for(int i=0; i<length; ++i)
		std::cout << array[i] << " ";
	
	std::cout << std::endl;
}

#endif
