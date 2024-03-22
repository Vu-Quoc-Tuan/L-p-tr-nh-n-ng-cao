#include<iostream>
using namespace std;

int lamtron( double a)
{
    int result=a;
    const double threshold = 0.55555555555555555555;
    if(a-result<threshold) return result;
    else return result+1;
}

int main()
{
    double a;
    cin>>a;
    cout<<lamtron(a);
}
