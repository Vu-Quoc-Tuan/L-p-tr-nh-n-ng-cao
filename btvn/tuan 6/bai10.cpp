#include<iostream>
#include<vector>
#include<math.h>

#include <algorithm>

using namespace std;

void insn(vector<int> temp)
{
    int kq;
    for(int i=0;i<(int)temp.size();i++){
        kq+=pow(2,i)*temp[i];
    }
    cout<< kq;
}

void innp(int n)
{
    vector<int> result;
    while(n)
    {
        int a=n%2;
        result.push_back(a);
        n/=2;
    }
     std::reverse(result.begin(), result.end());;
    for(int i=0;i<(int)result.size();i++){
        cout<<result[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int temp=n;
    vector<int> kq;
    bool flag=false;
    while(n)
    {
        int a=n%10;
        n/=10;
        kq.push_back(a);
        if(a>=2) flag=true;
    }
    if(flag) innp(temp);
    else insn(kq);

}
