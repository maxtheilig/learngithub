#include <iostream>
#include <stdlib.h> 

int main ()
{

int a[4];
for (int i = 1; i < 5; ++i) {a[i-1] = rand() % 8;}

std::cout << "Welcome to Mastermind :) " << std::endl;
for (int i = 0; i<4; ++i)  {std::cout << a[i]<< "  ";} std::cout << std::endl; 
std::cout << "result is combination of 4 numbers from 0-7" << std::endl;

int sum, f, g, counter, m ;
m=1;

while (m<14)  
{	
	std::cout << "your guess for step: " << m << std::endl;
	int b[4]; int B;
	//for (int i=0; i<4; ++i) {std::cin >> b[i];}
	std::cin >> B;
	b[3]=(((B%1000)%100)%10); b[2]=(((B-b[3])%1000)%100)/10;
	b[1]=((B-b[3]-b[2])%1000)/100; b[0]=(B-b[3]-b[2]-b[1])/1000;
	char c[5] = "FFFF"; int d[4] = {0,0,0,0};
	for (int i=0; i<4; ++i) { for (int j=0; j<4; ++j)
	{
			if (a[j]==b[i] && i==j) {d[i]=10;}
			if (a[j]==b[i] && i!=j) {d[i]=1;}}
	}
	sum = 0;
	for (int i=0; i<4; ++i) {sum=sum+d[i];}
	if (sum==40) 
	{ std::cout << "CONGRATS!!! You won in step " << m << std::endl; return 0;}
	
	f=sum%10; g=(sum-f)/10;
	counter=0;

	for (int i=1; i<=g; ++i) {c[i-1]='X'; counter = counter+1;}
	for (int i=1; i<=f; ++i) {c[counter+i-1]='O'; }
	
	std::cout << "result for step " << m << std::endl;
	for (int i=0; i<4; ++i) 
	{ std::cout << c[i]<< "  "; } std::cout << std::endl; 
	m=m+1;
	if (m==13) 
	{std::cout << "You lose, maximum step# exceeded" << std::endl; return 0;}
}
return 0;
}
