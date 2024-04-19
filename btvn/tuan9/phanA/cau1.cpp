#include<bits/stdc++.h>
using namespace std;
char* result;

void concat(const char* temp1, const char* temp2)
{
    int len1=strlen(temp1);
    int len2=strlen(temp2);
    int len=len1+len2;
    result=new char [len];
    strcpy(result,temp1);
    strcat(result,temp2);
}

int main()
{
    char * temp1={"helo"};
    char * temp2={" bongdua"};
    concat(temp1,temp2);
    cout<<result;
}
