#include <iostream>

using namespace std;

int fact(int no)
{
    int f=1;
    for(int i=1;i<=no;i++){
        f=f*i;
    }
    //cout<<"f is"<<f<<endl;
    return f;

}

int comb(int m,int n)
{
    return fact(m)/(fact(m-n)*fact(n));
}


int main()
{
    int no,bfact;
    cout<<"Enter the number for binomial function:"<<endl;
    cin>>no;

    cout<<"The binomial factors are:"<<endl;
    for(int i=0;i<=no;i++){
        bfact=comb(no,i);
        cout<<bfact<<endl;
    }
    return 0;
}
