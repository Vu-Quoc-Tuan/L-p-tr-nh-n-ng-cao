#include<iostream>
using namespace std;

string ya1;
//char yb1[3]="abcd";
char yc1[]="abcd";
int main()
{
    string ya2;
    cout<<ya1;
    for(char x:ya1) cout<<x;
    cout<<ya2;
    for(char x:ya2) cout<<x;
    cout<<endl;

//    cout<<yb1;
//    for(char x:yb1) cout<<x;
//    char yb2[3]="abcd";
//    cout<<yb2;
//    for(char x:yb2) cout<<x;
cout<<sizeof(yc1);
}

