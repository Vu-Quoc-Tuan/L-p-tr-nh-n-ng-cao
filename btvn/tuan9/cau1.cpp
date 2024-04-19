#include<bits/stdc++.h>
using namespace std;

char *reverse(const char* a){
    int len=strlen(a);
    char* result=new char [len];
    int dem=len-1;
    for(int i=0;i<len;i++){
        result[i]=a[dem-i];
    }
    return result;
}

char* delete_char(const char* a,const char c)
{
    int len=strlen(a);
    char* result=new char [len];
    int dem=0;
    for(int i=0;i<len;i++){
        if(a[i]!=c) {
            result[dem]=a[i];
            dem++;
        }
    }
    return result;
}

char* pad_right(char* a, int n){
    int len=strlen(a);
    if(n<=len){
        return a;
    }else{
        char* result=new char [n];
        for(int i=0;i<n-len;i++){
            result[i]=' ';
        }
        strcat(result,a);
        return result;
    }
}

char* pad_left(char* a, int n){
    int len=strlen(a);
    if(n<=len){
        return a;
    }else{
        char* result=new char [n];
        strcpy(result,a);
        for(int i=0;i<n-len+1;i++){
            result[i+len]=' ';
        }
        return result;
    }
}

char* truncate(char* a, int n)
{
    int len=strlen(a);
    if(n>=len){
        return a;
    }else{
        char* result=new char [n];
        strncpy(result,a,n);
        return result;
    }
}

char* trim_left(char *a)
{
    int len=strlen(a);
    int dem=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' ') break;
        dem++;
    }
    char* result=new char[len-dem];
    int temp=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '){
            result[temp]=a[i];
            temp++;
        }
    }
    return result;
}

char* trim_right(char *a)
{
    int len=strlen(a);
    int dem=0;
    for(int i=0;i<len;i++){
        if(a[i]=='_'){
            dem=i;
            break;
        }
    }
    char* result=new char[len-dem];
    int temp=0;
    for(int i=0;i<dem;i++){
        if(a[i]!='_'){
            result[temp]=a[i];
            temp++;
        }
    }
    return result;
}

int main()
{
    char* a={"ue oai"};
    char* kq1=reverse(a);
    cout<<kq1<<endl;

    char* kq2=delete_char(a,'e');
    cout<<kq2<<endl;

    char* kq3=pad_right(a,10);
    cout<<kq3<<endl;

    char* kq4=pad_left(a,10);
    cout<<kq4<<endl;

    char* kq5=truncate(a,3);
    cout<<kq5<<endl;

    char* b={"   abc___"};
    char* kq6=trim_left(b);
    cout<<kq6<<endl;

    char* kq7=trim_right(b);
    cout<<kq7<<endl;
}
