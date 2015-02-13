#include <iostream>

using namespace std;

int fact(int no)
{
    int f=1;
    for(int i=1;i<=no;i++){
        f=f*i;
    }
    cout<<"f is"<<f<<endl;
    return f;

}

int main()
{
    int m,n,comb,a,c,b;
    cout<<"Enter the number:"<<endl;
    cin>>m>>n;
    a=fact(m);
    b=fact(m-n);
    c=fact(n);
    comb=a/(b*c);
    cout<<"Combination of "<<m<<" and "<<n<<" is "<<comb<<endl;
    return 0;
}
