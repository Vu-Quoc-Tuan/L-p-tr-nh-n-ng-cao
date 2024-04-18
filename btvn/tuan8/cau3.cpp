#include<bits/stdc++.h>
using namespace std;

struct point
{
    int value=0;
};
    struct thu
    {
        int arr[5]={1,2,3,4,5};
        point temp;
    };

int main()
{
    thu temp;
    cout<<temp.arr<<endl;
    cout<<&temp.temp<<endl;
    thu check=temp;
    cout<<check.arr<<endl;
    cout<<&check.temp;

}
