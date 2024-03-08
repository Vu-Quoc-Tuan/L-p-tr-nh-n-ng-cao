#include<iostream>
using namespace std;

int arr1[10];
int ar1[5]={1,2,3,4};
//int ar11[3]={1,2,3,4};
int a[ ] = {1, 2, 3, 4};
int main()
{int ab[ ] = {1, 2, 3, 4};
    int arr2[10];
//    int ar11[3]={1,2,3,4};
    for(int i=0;i<10;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<5;i++){
        cout<<ar1[i]<<" ";
    }
    cout<<endl;

//    for(int i=0;i<3;i++){
//        cout<<ar11[i]<<" ";
//    }
//    cout<<endl;

//    for(int i=0;i<3;i++){
//        cout<<ar11[i]<<" ";
//    }
//    cout<<endl;

    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<4;i++){
        cout<<ab[i]<<" ";
    }
    cout<<endl;
}
