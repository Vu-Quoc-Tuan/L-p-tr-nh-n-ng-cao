#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int arr[30];
    srand(time(NULL));
    for(int i=0;i<30;i++){
        arr[i]=rand();
    }
    for(int i:arr){
        cout<<i<<" ";
    }

    for(int i=0;i<30;i++){
        for(int j=i;j<30;j++){
            if(arr[i]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout<<endl;
    for(int i:arr){
        cout<<i<<" ";
    }
}
