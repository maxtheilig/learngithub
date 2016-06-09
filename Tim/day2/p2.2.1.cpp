
#include <iostream>
#include <cstdlib>
#define SIZE 3
using namespace std;

int Random (int)
{
int i =rand () %20;
return i;
}

void MatrixAdd (int myarray1[SIZE][SIZE], int myarray2[SIZE][SIZE])
{
int myarray3 [SIZE][SIZE];
for (int i = 0; i < SIZE ; i++)
	{
	for (int j = 0; j < SIZE; j++)
		{	
		myarray3 [i][j] = myarray1 [i][j] + myarray2 [i][j];
		cout << myarray3 [i][j] << "\t";
		}
		cout << endl;
	}
cout << endl;
return;
}

int main (void)
{
srand (time(NULL));
int myarray1 [SIZE][SIZE];
int myarray2 [SIZE][SIZE];
for (int i = 0; i < SIZE ; i++)
	{
	for (int j = 0; j < SIZE; j++)
		{
		myarray1[i][j] = Random (0);	
		cout << myarray1 [i][j] << "\t";
		}
		cout << endl;
	}
cout << endl;
for (int i = 0; i < SIZE ; i++)
	{
	for (int j = 0; j < SIZE; j++)
		{	
		myarray2[i][j] = Random (0);	
		cout << myarray2 [i][j] << "\t";
		}
		cout << endl;
	}
cout << endl;
MatrixAdd (myarray1, myarray2);
return 1;
}







// sheet 2 task 2

//#include <iostream>

//int addmatrices(int a[2][2], int b[2][2], int rows, int cols)
//{	
//	int c[cols][rows];
//	for (int i=0; i<cols; ++i){ for (int j=0; j<rows; ++j)
//	{
//	c[i][j]=a[i][j]+b[i][j];
//	return *c;
//	}}
//}

//int main()
//{
//	int rows=2; int cols=2;
//	int A[cols][rows]= {{2,0},{0,2}}; int B[cols][rows]= {{0,1},{1,0}};
//	addmatrices(A,B,rows,cols)
//	return 0;	
//}



