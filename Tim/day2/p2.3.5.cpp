#include <iostream>
#include <cstdlib>

int main()
{
	int N, randint;
	std::cout << "dimension of random vector: " << std::endl;
	std::cin >> N;
	std::cout << "maximum component difference: " << std::endl;
	std::cin >> randint; 
	int randvec[N]; int j = 0;
	
	for (int i=0 ; i<N ; ++i)
        {
                randvec[i] = j+ 1 + (rand() %randint) ;
		j=randvec[i];
        }

	for (int i=0; i<N; ++i){ std::cout << randvec[i]<< " "; }   // display vector to check result
	std::cout << std::endl;
	
	int a;
	std::cout << "number you look for in the vector, lower than "<< N*randint  << std::endl;
        std::cin >> a;
		
	int k=-1; int n; int b=0; int c=N-1;			// k= marker , n= index where we compare the values
								// b,c edges of interval
	while (k==-1)
	{	
		if ( (b+c)%2 == 0){n=(b+c)/2;}					
		else {n=((b+c+1)/2);}						// make n an integer
		if ( c-b == 1 && randvec[b] != a && randvec[c] != a ) {break;}  // break condition for not havin found a
		else if (randvec[b] == a) {k=b; break;}				// check the edges of the interval
		else if (randvec[c] == a) {k=c; break;}
		if ( randvec[n] < a) {b=n;}					// update edges of interval
                else if (randvec[n] > a) {c=n;}
                else {k=n; break;}						// check if we found a luckily
	} 

	if (k==-1)
	{	
		std::cout << "# not found" <<std::endl;	
		return 0;
	}
	
	else
	{
		std::cout <<"# you looked for is @ position: " << k+1 << std::endl;		
		return 0;
	}
}
