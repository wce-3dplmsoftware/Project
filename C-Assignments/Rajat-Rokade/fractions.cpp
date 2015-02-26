/*
* A Program to add and subtract two fractions
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fractional
{
	int numerator;
	int denum;

public:

	Fractional()
	{
		numerator=1;
		denum=1;
	}

	Fractional(int num,int den)
	{
		numerator=num;
		denum=den;
	}


	//add two fractions
	void add(Fractional f2)
	{
		numerator=numerator*f2.getDenum()+f2.getNumerator()*denum;
		denum=denum*f2.getDenum();
		int gcd=getGCD(numerator,denum);
		numerator=numerator/gcd;
		denum=denum/gcd;
	}

	//subtract two fractions
	void subtract(Fractional f2)
	{
		numerator=numerator*f2.denum-f2.numerator*denum;
		denum=denum*f2.denum;
		int gcd=getGCD(numerator,denum);
		numerator=numerator/gcd;
		denum=denum/gcd;
	}

	void display()
	{
		cout<<"The Fraction is : "<<numerator<<"/"<<denum<<endl;
	}

	int getDenum()
	{
		return denum;
	}

	int getGCD(int a,int b)
	{
		int min=(a>b)?b:a;
		int gcd=1;
		for(int i=min;i>1;i--)
		{
			if(a%i==0&&b%i==0)
				return i;
		}
		return gcd;
	}

	int getNumerator()
	{
		return numerator;
	}

	

	~Fractional()
	{}
};


//main function
int main()
{
	{
		Fractional f1(5,7),f2(2,4);
		f1.add(f2);
		f1.subtract(f2);
		f1.display();
	}
	system("pause");
	return 0;
}
