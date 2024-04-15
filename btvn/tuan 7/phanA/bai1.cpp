#include<iostream>
using namespace std;

int main()
{
    char a = 'a';
	char* p1 = &a;
	int* p2 = (int*)p1;
	*p2 = 'b';
cout<<*p1;

    char str[50]='Hello World';
    char *p1=str;
    char *p2=%str[0];
    if(p1==p2) cout<<"Equal";
    if(p1[5]==' ') *(p2+5)='_';
    p1=NULL;
    p2=NULL;
    str=NULL;
}
