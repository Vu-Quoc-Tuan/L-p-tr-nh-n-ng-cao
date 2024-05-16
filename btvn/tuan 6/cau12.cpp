#include<bits/stdc++.h>
using namespace std;

long long result[10000][10000];

int toHop(int k, int n)
{
    if(result[k][n]!=0) return result[k][n];
    if(k==0 || k==n){
        result[k][n]=1;
        return 1;
    }
    result[k][n]=toHop(k,n-1)+toHop(k-1,n-1);
    return result[k][n];
}

int kiemTra(int k, int n)
{
    if(k>=0 && k<=n && n>=1 && n<=20) return 1;
    return 0;
}

void nhapKN(int k[], int n[], int *soPhanTu)
{
    *soPhanTu=0;
    bool check=false;
    while(!check)
    {
        cin>>k[*soPhanTu]>>n[*soPhanTu];
        if(k[*soPhanTu]==-1 && n[*soPhanTu]==-1){
            check=true;
            break;
        }
        cout<<toHop(k[*soPhanTu],n[*soPhanTu])<<endl;
        if(kiemTra(k[*soPhanTu],n[*soPhanTu])==1) (*soPhanTu)++;
    }
}

int main()
{
    int k[1000];
    int n[1000];
    int sophantu;
    nhapKN(k,n,&sophantu);

}
