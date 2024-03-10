#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='*') continue;
            char temp='0';
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(arr[a+i][b+j]=='*' && a+i<n && b+j<m)
                    {
                        temp++;
                    }
                    arr[i][j]=temp;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
