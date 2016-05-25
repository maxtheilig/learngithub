#include <iostream>

int * reverseArray(int *array,int length)
{	int * p = &length;
	const int pp = *p;
	const int l=3;
	static int rarray[3];
	for (int i=0; i<length; ++i)
	{
		rarray[length-1-i]=array[i];
	}
	return rarray; 
}

int main()
{
	const int length = 3; 
	int a[length] = {10,20,30};
	int *b;
	b = reverseArray(a,length);
	for (int i=0; i<length; ++i)
	{
	std::cout<<a[i]<<"\t"<<reverseArray(a,length)[i]<<"\t"<<b[i]<<"\n";
	} 
	return 0;
}



