#include<bits/stdc++.h>
using namespace std;

struct String
{
    int n;
    char *str;

    String(char* str_){
        n=strlen(str_);
        str=new char [n+1];
        strcpy(str,str_);
    }
    ~String()
    {
        delete[] str;
    }

    void print(){
        for(char *it=str; it<str+n;it++){
            cout<<*it;
        }
        cout<<endl;
    }
    void append(const char* temp){
        char* tg=str;
        n=n+strlen(temp);
        str= new char [n];
        strcpy(str,tg);
        strcat(str,temp);
    }
} ;

int main()
{
//    String s("Hello");
//    s.print();

    String greeting("Hi");
	greeting.append(" there");
	greeting.print();
}
