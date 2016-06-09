#include <iostream>

void *reverseArray(const int *array, int *reversearray,unsigned const int length)
{
	for (unsigned int i=0; i<length; ++i)
	{
		*(reversearray+(length-1-i))=*(array+i);
	} 
}

int main()
{
	unsigned const int length = 3; 
	const int array[length] = {10,20,30};
	int reversearray[length]={0};
	reverseArray(array, reversearray, length);
	for (unsigned int i=0; i<length; ++i)
	{
		std::cout<<array[i]<<"\t"<<reversearray[i]<<"\n";
	} 
	return 0;
}
