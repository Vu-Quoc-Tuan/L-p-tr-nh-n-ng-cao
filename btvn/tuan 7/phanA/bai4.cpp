#include <bits/stdc++.h>
using namespace std;

bool binary_searcht(int left,int right,int *arr, int value)
{

    int mid=(right-left)/2+left;
    if(arr[mid]==value) return true;
        if(left>=right) return false;
    else if(arr[mid]<value){
        return binary_searcht(mid+1,right,arr,value);
    }else{
        return binary_searcht(left,mid-1,arr,value);
    }
}

int main()
{
    int *arr=new int[10];
    srand(time(NULL));
    for(int i=0;i<10;i++){
        arr[i]=rand();
    }
    sort(arr,arr+10);
    cout<<binary_searcht(0,9,arr,5);
}
