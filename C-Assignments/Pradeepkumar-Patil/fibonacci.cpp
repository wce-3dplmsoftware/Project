#include<iostream>

using namespace std;

int main(){
    int a=0,b=1,c,num;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    cout<<"The fibonacci series is:"<<endl;
    cout<<a;
    cout<<b;

    for(int i=0;i<num;i++){
        c=a+b;
        cout<<c;
        a=b;
        b=c;
    }

}
