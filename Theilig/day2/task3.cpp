#include <iostream>
#include <utility>
#include "printArray.h"
	
int* reverseArray(int *array, int length);
int searchArray(int *array, int length, int number);
int searchSortedArray(int* a, int start, int end, int  x);

int main()
{
	const int length1 = 8;
	int a[length1] = {1,3,34,65,89,123,4221,42344};
	printArray(a,length1);
	int x = 4221;
	int start(0), end(length1-1);
	int pos1 = searchSortedArray(a, start, end, x);
	std::cout << x << " is at position " << pos1+1 << ".\n";
	
	const int length = 5;
	int array[length] = { 1,2,4,7,8 };
	printArray(array,length);
	int number=7;
    int pos = searchArray(array,length,number);
    if(pos==-1){std::cout << number << "is not an element of the matrix." << std::endl;}
    else{std::cout << number << " is at position " << pos << ".\n";}
	
	int *rArray = reverseArray(array,length);
    std::cout << "The reversed array is:" << std::endl;
	printArray(rArray,length);
	return 0;
}

int searchSortedArray(int* a, int start, int end, int  x)//x=number
{
	const int mid = start + ((end-start)/2);
	
	if(a[mid] == x)
	{
		return mid;
	}
	else if(a[mid] > x)
	{
		return searchSortedArray(a, start, mid-1, x);
	}
	
	return searchSortedArray(a, mid+1, end, x);
}

int searchArray(int *array, int length, int number)
{
	for(int i=0; i<length; ++i)
		if(array[i]==number)
			return i+1;
	
	return -1;
}

int* reverseArray(int *array, int length)
{
	if (length%2==0)
	{
		for(int i=0; i<length/2; ++i)
			std::swap(array[i],array[length-1-i]);
	}
	else 
	{
		for(int i=0; i<(length-1)/2; ++i)
			std::swap(array[i],array[length-1-i]);
	}
	return array;
}
