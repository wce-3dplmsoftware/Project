/*
*A recursive cpp program to print the fibonacci series
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int fibonacci (int num);

//main function
int main()
{
	int num;
	cout<<"Enter a number : ";
	cin>>num;
	cout<<"Fibonacci Series : ";
	for(int i=1;i<=num;i++)
	{
		cout<<fibonacci(i)<<" ";
	}
	system("pause");
	return 0;
}

//Function to calculate fibonacci series
int fibonacci(int num)
{
	if(num==1 || num==2)
		return 1;
	if(num>2)
		return fibonacci(num-1)+fibonacci(num-2);
}
