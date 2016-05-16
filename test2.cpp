#include <iostream>

int getValue()
{
        std::cout << "Gib eine Zahl ein!" << std::endl;
        int x;
        std::cin >> x;
        return x;
}


int factorial(int x)
{	int y = x;
	int outp = y;
	if(x==1)
	{ return 1; }
	else
	{ while(y>1) 	
	{y=y-1;
	outp=outp*y;
	 }
	return outp;
	}
}
 
int main ()
{std::cout << factorial( getValue () ) << std::endl;
 return 0;
}

