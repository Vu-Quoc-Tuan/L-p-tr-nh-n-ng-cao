#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        arr[i][0]=1;
    }
    for(int i=1;i<n;i++){
        arr[i][i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0) cout<<setw(3)<<right;
            else cout<<setw(3)<<right<<arr[i][j];
        }
        cout<<endl;
    }
}
