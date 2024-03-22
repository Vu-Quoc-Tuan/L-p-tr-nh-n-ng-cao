#include<iostream>
#include<math.h>
//#include<cstdlib>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%50;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int m=0;m<n;m++){
                if(arr[i]!=arr[j] && arr[i]!=arr[m]){
                    if(arr[i]+arr[j]+arr[m]==25){
                        cout<<arr[i]<<" "<<arr[j]<<" "<<arr[m]<<endl;
                }
            }
        }
    }
}
}
