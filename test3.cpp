#include <iostream>
#include <cmath>

int main()
{
int a[20];
int b[20][20];
for (int i=0; i<20; ++i)
{ 
	a[i]=i+1;
}
for (int j=0; j<20; ++j)
{
	for (int k=0; k<20; ++k)
	{
		b[j][k]=a[j]*a[k];	
	}
}
for (int j=0; j<20; ++j)
{
         for (int k=0; k<20; ++k)
         {
	 	if (b[j][k]<10)
		{
        		std::cout << b[j][k] << "   ";
         	}
	 	else if (b[j][k]<100)
		{
			std::cout << b[j][k] << "  ";
		}
		else
		{
			std::cout << b[j][k] << " ";
		} 
	}
	std::cout << std::endl;
}
return 0;
}
