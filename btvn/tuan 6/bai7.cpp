#include<iostream>
using namespace std;

void print_c (int m)
{
    for(int i=0;i<m;i++){
        cout<<" ";
    }
}

void print_s (int n)
{
    for(int i=0;i<n;i++){
        cout<<"*";
    }
}

int main()
{
    int a;
    cin>>a;
    int n=1;
    int m=a-1;
    while(n<=2*a-1)
    {
        print_c(m);
        print_s(n);
        print_c(m);
        n+=2;
        m-=1;
        cout<<endl;
    }
}
