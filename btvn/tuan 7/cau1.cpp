#include<iostream>
using namespace std;

char* reverser(char* a)
{
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }

    char * result=new char;
    int dem=0;
    for(int i=len-1;i>=0;i--){
        result[dem]=a[i];
        dem++;
    }
    return result;
}

char* delete_char(char* a, char c)
{
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
    char * result=new char;
    int dem=0;
    for(int i=0;i<len;i++){
        if(a[i]!=c){
            result[dem]=a[i];
            dem++;
        }
    }
    return result;
}

char* pad_right(char* a, int n)
{
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
            if(len>=n) return a;
    char *result=new char[n];
    for(int i=0;i<len;i++){
        result[i]=a[i];
    }
    for(int i=len;i<n;i++){
        result[i]='_';
    }
    result[n]='\0';
    return result;
}

char* pad_left(char* a, int n)
{
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
    if(len>=n) return a;
    char *result=new char[n];
    int dem=0;
    for(int i=0;i<n-len;i++){
         result[i]='_';
    }
    for(int i=n-len;i<n;i++){
        result[i]=a[dem];
        dem++;
    }
    result[n]='\0';
    return result;
}

char* truncate(char* a, int n)
{
    int len=0;
    while(a[len]!='\0'){
        len++;
    }
    if(len<=n) return a;
    char *result=new char[n];
    int dem=0;
    for(int i=0;i<n;i++){
         result[i]=a[i];
    }
    result[n]='\0';
    return result;
}

bool is_palindrome(char* a)
{
    int len=0;
    while(a[len]!='\0'){
        len++;
    }
    int mid=len/2;
    for(int i=0;i<mid;i++){
        if(a[i]!=a[len-i-1]) return false;
    }
    return true;
}

char* trim_left(char* a)
{
    int len=0;
    while(a[len]!='\0'){
        len++;
    }
    int check=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' ') {
                check=i;
        break;}
    }
    int dem=0;
    char *result=new char[len-check];
    for(int i=check;i<len;i++){
        result[dem]=a[i];
        dem++;
    }
    return result;
}

char* trim_right(char* a)
{
    int len=0;
    while(a[len]!='\0'){
        len++;
    }
    int check=0;
    for(int i=len-1;i>=0;i--){
        if(a[i]!='_') {
                check=i;
        break;}
    }
    char *result=new char[len-check];
    for(int i=0;i<=check;i++){
        result[i]=a[i];
    }
    result[check+1]='\0';
    return result;
}

int main()
{
    char * a="  ueoai___";

//    char*kq=reverser(a);
//    char*kq=delete_char(a,'e');
//    char*kq=pad_right(a, 10);
//    char*kq=pad_left(a, 10);
//    char*kq=truncate(a,3);

//bool kq=is_palindrome(a);
//char* kq=trim_left(a);
char* kq=trim_right(a);
    cout<<kq;
}
