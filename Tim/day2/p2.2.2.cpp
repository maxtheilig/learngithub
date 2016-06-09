# include <iostream>


int randnumb (unsigned const int maxnumber)
{
	unsigned const int output = rand() %(maxnumber+1) ;
	return output;
}

void matrixmultiplication( const int *matrixlhs, const int *matrixrhs, int *resultmatrix, unsigned const int colslhs, unsigned const int rowslhscolsrhs, unsigned const int rowsrhs)
{ 
	for (unsigned int i=1, i <= colslhs, ++i) 
	{
		for (unsigned int j=1, j <= rowsrhs, ++j)
		{ 
			for (unsigned int k=1 , k <= rowslhscolsrhs , ++k)
			{
				*(resultmatrix+(i*rowsrhs+j))  +=  *(matrixlhs+(i-1)*rowslhscolsrhs+k) * *(matrixrhs+(k-1)*rowsrhs+j);
			}
		}
	}
}					

void initMatrix( int *matrix, unsigned const int cols, unsigned const int rows, unsigned const int maxnumber)
{
	for (unsigned int i=1, i <= cols, ++i) 
        { 
                for (unsigned int j=1, j <= rows, ++j)
                {
			*(matrix+(i*rows+j))=randnumb(maxnumber);
		}
	} 
}

void printMatrix( int *matrix, unsigned const int cols, unsigned const int rows)
{
	for (unsigned int i=1, i <= cols, ++i)   
        {
                std::cout  <<
		for (unsigned int j=1, j <= rows, ++j)
                {
                        *(matrix+(i*rows+j))=randnumb(maxnumber);
                }
        }



}
int main()
{
	unsigned const int colslhs = randnumb(5);
	unsigned const int rowslhscolsrhs = randnumb(5);
	unsigned const int rowsrhs = randnumb(5); 
	int matrixlhs[colslhs][rowslhscolsrhs] = {0};
	int matrixrhs[rowslhscolsrhs][rowsrhs] = {0};
	int resultmatrix[colslhs][rowsrhs]= {0};
	initMatrix( matrixlhs, colslhs, rowslhscolsrhs, 10);
	initMatrix( matrixrhs, rowslhscolsrhs, rowsrhs, 10);
	const int matrixlhs=matrixlhs;
	const int matrixrhs=matrixrhs;
	matrixmultiplication( matrixlhs, matrixrhs, resultmatrix, colslhs, rowslhscolsrhs, rowsrhs);
	printMatrix(matrixlhs, colslhs, rowslhscolsrhs); printMatrix(matrixrhs, rowslhscolsrhs, rowsrhs); printMatrix(resultmatrix, colslhs, rowsrhs)
	


}





 
