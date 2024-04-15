#include <bits/stdc++.h>
using namespace std;

int count_even(int* arr, int n)
{
    int dem=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) dem++;
    }
    return dem;
}

int main()
{
    int * arr= new int[10];
    srand(time(NULL));
    for(int i=0;i<10;i++){
        arr[i]=rand();
    }
    cout<<count_even(arr,10);
}
