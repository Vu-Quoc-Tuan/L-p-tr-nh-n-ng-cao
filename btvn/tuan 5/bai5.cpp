#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int k=1;
    int dong=0;
    int cot=0;
    while(k<=n*m){
        for(int i=cot;i<m-cot;i++){
            arr[dong][i]=k;
            k++;
        }
        for(int i=dong+1;i<n-dong;i++){
            arr[i][m-cot-1]=k;
            k++;
        }
        for(int i=m-cot-2;i>=0;i--){
            if(k<=n*m){
                arr[n-dong-1][i]=k;
                k++;
            }
        }
        for(int i=n-cot-2;i>0;i--){
            if(k<=n*m){
                arr[i][cot]=k;
                k++;
            }
        }
        dong++;
        cot++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
