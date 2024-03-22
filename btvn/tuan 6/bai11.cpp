#include<bits/stdc++.h>
using namespace std;

bool check(int n, int k)
{
     if(k>=0 && k<=n){
        if(n<=20 && n>=1){
            return true;
        }
     }
     return false;
}

int giaithua(int a)
{
    int kq=1;
    for(int i=a;i>0;i--){
        kq*=i;
    }
    return kq;
}

int toHop(int n, int k){
    int result=giaithua(n)/(giaithua(k)*giaithua(n-k));
    return result;
}

int main()
{
    while(1){
        int n,k;
        cin>>k>>n;
        bool falg=check(n,k);
        if(n==-1&&k==-1){
            break;
        }
        if(!falg){
            cout<<"0";
            continue;
        }
        cout<<toHop(n,k)<<endl;
    }
}
