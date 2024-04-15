#include<iostream>
using namespace std;

int lengof(int* arr) {
    int i = 0;
    while (*(arr + i) != '\0') {
        i++;
    }
    return i;
}


int main()
{
    int* arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=i;
    }
    cout<<lengof(arr);
}
