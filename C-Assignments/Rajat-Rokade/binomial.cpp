/*
*A recursive cpp program to print the binomial of given numbers
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int factorial(int num);

//main function
int main()
{
	int num;
	cout<<"Enter power of Binomial Expression : ";
	cin>>num;
	
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<=i;j++)
			cout<<factorial(i)/(factorial(j)*factorial(i-j))<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}

//Function to find the factorial
int factorial(int num)
{
	int res=1;
	for(int i=1;i<=num;i++)
		res=res*i;
	return res;
}
