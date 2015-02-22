/*
*A Program to implement string
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

class Cstring
{
	char *str;

public:
	Cstring()
	{
		str=new char[10];
	}

	Cstring(int n)
	{
		str=new char[n];
	}

	Cstring(char *c ,int n)
	{
		str=new char[n];
		str=c;
	}

	Cstring(char *c)
	{
		str=c;
	}

	//string copy
	void operator=(const Cstring &c)
	{
		str=c.str;
	}

	//concatenation operator
	void operator+=(const Cstring &c)
	{
		char *a=(char*)malloc(strlen(str)+strlen(c.str)+1);
		strcpy(a,str);
		strcat(a,c.str);
		str=a;
		
	}

	//check equality of strings
	bool operator==(const Cstring &c)
	{
		if(str==c.str)
			return true;

		return false;
	}

	//< operator to compare strings
	bool operator<(const Cstring &c)
	{
		int len=0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='\0')
			{
				len=i;
				break;
			}
		}

		if(len<size(c))
			return true;

		return false;
	}

	//return size of string
	int size(Cstring c)
	{
		for(int i=0;i<strlen(c.str);i++)
		{
			if(c.str[i]=='\0')
				return i;
		}
	}

	//[] to return character
	char operator[](int i)
	{
		return str[i];

	}

	//Display function
	void display()
	{
		cout<<"String : "<<str<<endl;
	}

};

//main function
int main()
{
	Cstring cstr;
	Cstring cstr1(10);
	Cstring cstr2("*",20);
	Cstring cstr3("Computer");
	Cstring cstr4;

	//= operator
	cstr4=cstr3;
	cstr4.display();
	
	//concatenation operator
	cstr2+=cstr3;
	cstr2.display();
	
	//equality check operator
	if(cstr4==cstr3)
		cout<<"Equal Strings"<<endl;
	
	//relational operator
	if(cstr2<cstr3)
		cout<<"String 1 is smaller"<<endl;

	//get character at given position
	cout<<cstr3[3]<<endl;
	
	system("pause");
	return 0;
}
