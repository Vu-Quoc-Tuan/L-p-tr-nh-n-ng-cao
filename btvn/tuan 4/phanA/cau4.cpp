#include <iostream>
using namespace std;

int main() {
//    char arr[4] = {'A', 'B', 'C', 'D'};
//arr[-1]='e';
//
//
//   cout<<arr[4]<<endl;
//   cout<<arr[-1]<<endl;
//   cout<<arr[5]<<endl;

    char arr[3][4];
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j];
        }
    }

    return 0;
}
