#include "stdafx.h"
#include <iostream>

using namespace std;

class Employee
{
	long empcode;
	double salary;
	char *name;
	
public:
	//Constructor to initialize data
	Employee(long emp,double sal,char *nm)
	{
		empcode=emp;
		salary=sal;
		name=nm;
	}

	long getEmpCode()
	{
		return empcode;
	}
	double getSalary()
	{
		return salary;
	}
	char *getName()
	{
		return name;
	}

	//Display function to display employee data
	void display()
	{
		cout<<"Employee Details :"<<endl;
		cout<<"Code : "<<empcode<<endl<<"Salary : "<<salary<<endl<<"Name : "<<name<<endl;
	}
//Destructor
	~Employee()
	{}
};

//main function
int main()
{
	{
	Employee e1(10023,20000,"Rajat");
	e1.display();
	}
	system("pause");
	return 0;
}
