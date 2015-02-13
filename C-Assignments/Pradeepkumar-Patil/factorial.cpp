#include <iostream>

using namespace std;

int main()
{
    int num,factorial=1;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    for(int i=1;i<=num;i++)
    {
        factorial=factorial*i;
    }
    cout<<"The factorial of "<<num<<" is:"<<factorial<<endl;
    return 0;
}
