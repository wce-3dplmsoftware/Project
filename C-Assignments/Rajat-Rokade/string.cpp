/*
* A Program to implement string
*/

#include "stdafx.h"
#include <iostream>

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
		str=c+'\0';
	}

	Cstring(char *c)
	{
		str=c;
	}

	//string copy
	void operator=(Cstring c)
	{
	str=c.getStr();
	}

	//concatenation operator
	void operator+=(Cstring c)
	{
		
		char *a=(char*)malloc(size(str)+size(c.getStr())+1);
		memcpy(a,str,size(str));
		memcpy(a+(size(str)),c.getStr(),size(c.getStr()));
		memcpy(a+size(str)+size(c.getStr()),"",size(a)-(size(str)+size(c.getStr())));
		str=a;
	}

	//check equality of strings
	bool operator==(Cstring c)
	{
		if(size(str)!=size(c.getStr()))
			return false;
		else
		{
			for(int i=0;i<size(str);i++)
			{
				if(str[i]!=c.getStr()[i])
					return false;
			}
			return true;
		}
	}

	//< operator to compare strings
	bool operator<(Cstring c)
	{
		int len=0;
		for(int i=0;i<size(str);i++)
		{
			if(str[i]=='\0')
			{
				len=i;
				break;
			}
		}

		if(len<size(c.getStr()))
			return true;

		return false;
	}

	//return size of string
	int size(char *c)
	{
		int i=0;
		while(c[i]!='\0')
		{
			i++;
		}
		return i;
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

	//Get String
	char* getStr()
	{
		return str;
	}
	
};

//main function
int main()
{
	Cstring cstr;
	Cstring cstr1(10);
	Cstring cstr2("*",20);
	Cstring cstr3("Computer Science");
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
