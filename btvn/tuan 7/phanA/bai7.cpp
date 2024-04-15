#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char* a={"abc"};
    char* b={"abcabcabcccsdhg"};
    int len=0;
    while(b[len]!='\0') len++;
    int kq=0;
    for(int i=0;i<len-3;i++){
//        for(int j=i;j<len;j++){
//            for(int k=j;k<len;k++){
//                if(k!=j ||j!=i ||k!=i){
                    char *tg=new char[4];
                    tg[0]=b[i]; tg[1]=b[i+1]; tg[2]=b[i+2]; tg[3]='\0';
                    int dem=strcmp(a,tg);
                    if(dem==0) kq++;
//                }
//            }
//        }
    }

    cout<<kq;
}
