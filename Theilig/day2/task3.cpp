#include <iostream>
#include <utility>
#include "printArray.h"
	
int* reverseArray(int *array, const unsigned int length);
int searchArray(int *array, const unsigned int length, const int number);
int searchSortedArray(int* a, int start, int end, const int  x);
bool checkIfElementOfArray(int* a, const unsigned int length, const int number);

int main()
{
	const int length1 = 8;
	int a[length1] = {1,3,34,65,89,123,4221,42344};
	printArray(a,length1);
	int x = 123;
	int start(0), end(length1-1);
	int pos1 = searchSortedArray(a, start, end, x);
	if(pos1==-1){std::cout << x << " is not an element of the matrix." << std::endl;}
	else{std::cout << x << " is at position " << pos1+1 << ".\n";}
	
	const int length = 6;
	int array[length] = { 1,2,4,7,8,9 };
	printArray(array,length);
	int number=3;
    int pos = searchArray(array,length,number);
    if(pos==-1){std::cout << number << " is not an element of the matrix." << std::endl;}
    else{std::cout << number << " is at position " << pos << ".\n";}
	
	int *rArray = reverseArray(array,length);
    std::cout << "The reversed array is:" << std::endl;
	printArray(rArray,length);
	return 0;
}

bool checkIfElementOfArray(int* a, const unsigned int length, const int number)
{
	for(unsigned int i=0; i<length; ++i){
		if(a[i]==number)
			return true;}
	return false;
}
	
int searchSortedArray(int* a, int start, int end, const int  x)//x=number
{
	if(!checkIfElementOfArray(a,end-start,x))
		return -1;
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

int searchArray(int *array, const unsigned int length, const int number)
{
	if(!checkIfElementOfArray(array,length,number))
		return -1;	
	for(int i=0; i<length; ++i)
		if(array[i]==number)
			return i+1;
}

int* reverseArray(int *array, const unsigned int length)
{
	for(int i=0; i<length/2; ++i)
		std::swap(array[i],array[length-1-i]);
	return array;
}
