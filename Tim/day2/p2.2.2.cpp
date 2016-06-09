#include <iostream>
#include <cstdlib>

int randnumb (unsigned const int maxnumber)
{
	unsigned const int output = rand() %(maxnumber+1) ;
	return output;
}

void matrixMultiplication( int *matrixlhs, int *matrixrhs, int *resultmatrix, unsigned const int colslhs, unsigned const int rowslhscolsrhs, unsigned const int rowsrhs)
{ 
	for (unsigned int i=1; i <= colslhs; ++i) 
	{
		for (unsigned int j=1; j <= rowsrhs; ++j)
		{ 
			for (unsigned int k=1 ; k <= rowslhscolsrhs ; ++k)
			{
				*(resultmatrix+(i-1)*rowsrhs+j)  +=  *(matrixlhs+(i-1)*rowslhscolsrhs+k) * *(matrixrhs+(k-1)*rowsrhs+j);
			}
		}
	}
}					

void initializeMatrix( int *matrix, unsigned const int cols, unsigned const int rows, unsigned const int maxnumber)
{
	for (unsigned int i=1; i <= cols; ++i) 
        { 
                for (unsigned int j=1; j <= rows; ++j)
                {
			*(matrix+(i-1)*rows+j)=randnumb(maxnumber);
		}
	} 
}

void printMatrix( int *matrix, unsigned const int cols, unsigned const int rows)
{
	for (unsigned int i=1; i <= cols; ++i)   
        {
		for (unsigned int j=1; j <= rows; ++j)
                {
                        std::cout << *(matrix+(i-1)*rows+j) << '\t';
                }
		std::cout << std::endl;
        }
	std::cout << '\n' << std::endl;
}

int main()
{
	const unsigned int colslhs = 2;
	const unsigned int rowslhscolsrhs = 4;
	const unsigned int rowsrhs = 2;
 
	int matrixlhs [colslhs][rowslhscolsrhs] = {0};
	int matrixrhs [rowslhscolsrhs][rowsrhs] = {0};
	int resultmatrix [colslhs][rowsrhs]= {0};

	initializeMatrix( *matrixlhs, colslhs, rowslhscolsrhs, 4);
	initializeMatrix( *matrixrhs, rowslhscolsrhs, rowsrhs, 4);
	matrixMultiplication( *matrixlhs, *matrixrhs, *resultmatrix, colslhs, rowslhscolsrhs, rowsrhs);

	printMatrix(*matrixlhs, colslhs, rowslhscolsrhs);
	printMatrix(*matrixrhs, rowslhscolsrhs, rowsrhs); 
	printMatrix(*resultmatrix, colslhs, rowsrhs);
	
	return 0;
}
