/*
*A recursive cpp program to print the factorial of a number taken from user
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int factorial (int num);

//main function
int main()
{
	int num;
	cout<<"Enter a number : ";
	cin>>num;
	cout<<"Factorial of "<<num<<" is : ";
	num=factorial(num);
	cout<<num<<endl;
	system("pause");
	return 0;
}

//Function to calculate factorial
int factorial(int num)
{
	if(num==1)
		return 1;
	if(num>1)
		return num*factorial(num-1);
}
