#include <iostream>

using namespace std;

int fact(int no)
{
    int f=1;
    for(int i=1;i<=no;i++){
        f=f*i;
    }
    return f;
}

int main()
{
    int m,n,per;
    cout<<"Enter the number:"<<endl;
    cin>>m>>n;
    per=fact(m)/fact(m-n);
    cout<<"Permutation of "<<m<<" and "<<n<<" is "<<per<<endl;
    return 0;
}
