#include <iostream>
#include <cstdlib>

void printArray(int *array, unsigned int length)
{
	for (unsigned int i=0; i<length; ++i)
	{
		std::cout << *(array+i) << " "; 
	} 
	std::cout << std::endl;
}

void initializeArray(int *array, unsigned int length, unsigned int randinterval) 
{
	unsigned int j = 0;
	for (int i=0 ; i<length ; ++i)
        {
                array[i] = j+ 1 + (rand() %randinterval) ;
		j=array[i];
        }
}

int findIntSortet( int *array, unsigned int length, unsigned int numbersearchedfor)
{
	int position =-1; unsigned int index; unsigned int loweredge=0; unsigned int upperedge=length-1;
	while (position==-1)
	{	
		if ( (loweredge+upperedge)%2 == 0){index=(loweredge+upperedge)/2;}					
		else {index=((loweredge+upperedge+1)/2);}// make index an integer
		if ( upperedge-loweredge == 1 && array[loweredge] != numbersearchedfor && array[upperedge] != numbersearchedfor ) {break;}  // break condition for not havin found number at all
		else if (array[loweredge] == numbersearchedfor) {position=loweredge; break;}	// check the edges of the interval
		else if (array[upperedge] == numbersearchedfor) {position=upperedge; break;}
		if (array[index] < numbersearchedfor) {loweredge=index;}	// update edges of interval
                else if (array[index] > numbersearchedfor) {upperedge=index;}
                else {position=index; break;}				// check if we found a luckily
	} 
	if (index==-1)
	{	
		std::cout << "# not found" <<std::endl;	
		return 0;
	}
	
	else
	{
		std::cout <<"# you looked for is @ position: " << index+1 << std::endl;		
		return 0;
	}
}




int main() 
{
	unsigned int length, randinterval, numbersearchedfor ;
	std::cout << "dimension of random vector: " << std::endl;
	std::cin >> length;
	int array[length];

	std::cout << "maximum component difference: " << std::endl;
	std::cin >> randinterval;

	initializeArray( array, length, randinterval);
	printArray( array, length);

	std::cout << "number you look for in the vector, lower than "<< length*randinterval  << std::endl;
        std::cin >> numbersearchedfor; 	
	findIntSortet( array, length, numbersearchedfor);
	
	return 0;
}
