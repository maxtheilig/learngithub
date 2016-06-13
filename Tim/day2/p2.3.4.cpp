#include <iostream>
#include <cstdlib>

int searchInteger(int *array, unsigned int length, unsigned int numbersearchedfor,int position)
{
	for (unsigned int j=0; j<length; ++j)
        {	
                if ( array[j] == numbersearchedfor )
                {
			std::cout << "# you looked for is @ position  " << j+1 << std::endl;
			return 0;     
                }
   	}
	std::cout << "number not found" << std::endl;
	return 0;
} 

void printArray(int *array, unsigned int length)
{
	for (unsigned int i=0; i<length; ++i)
	{
		std::cout << *(array+i) << " "; 
	} 
	std::cout << std::endl;
}

void initializeArray(int *array, unsigned int length)
{
	for (unsigned int i=0 ; i<length ; ++i)
        {
        	*(array+i) = rand() %(length+1);
        }
}


int main()
{
	unsigned int length;
	unsigned int numbersearchedfor;
	int position;
	std::cout << "dimension of random vector: " << std::endl;
	std::cin >> length;
	std::cout << "number you look for in the vector, not higher than dimension" << std::endl;
	std::cin >> numbersearchedfor;
	int array[length];
	initializeArray( array, length);	
	printArray( array, length);
	searchInteger( array, length, numbersearchedfor, position);
	return 0;
}
