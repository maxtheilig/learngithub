#include <iostream>
#include <cstdlib>


/*int randvec (int n, int rndv[] )
{
	int rndv[n] = rndv[];
	for (int i=0 ; i<n ; ++i)
	{
		rndv[i] = rand() %(n+1);
	}
}
*/
int main()
{
	int N, a;
	std::cout << "dimension of random vector: " << std::endl;
	std::cin >> N;
	std::cout << "number you look for in the vector, lower than dimension" << std::endl;
	std::cin >> a;
	int randvec[N];
	
	for (int i=0 ; i<N ; ++i)
        {
                randvec[i] = rand() %(N+1);
        }

	for (int i=0; i<N; ++i){ std::cout << randvec[i]<< " "; }
	
	std::cout<<" "<<std::endl;
	
	for (int i=0; i<N; ++i)
	{
		if (randvec[i]==a)
		{
			std::cout <<" # you looked for is @ position: " << i+1 << std::endl;
			return 0;
		}	
	}
	std::cout << "# not found" <<std::endl;
	return 0;
}
