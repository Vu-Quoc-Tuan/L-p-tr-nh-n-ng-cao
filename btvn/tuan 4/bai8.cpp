#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int list_patien [N];
    for(int i=0;i<N;i++)
    {
        cin>>list_patien[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(list_patien[i]>list_patien[j]){
                int temp=list_patien[j];
                list_patien[j]=list_patien[i];
                list_patien[i]=temp;
            }
        }
    }
    int kq;
    for(int i=0;i<N;i++){
        kq+=list_patien[i]*N-1-i;
    }
    cout<<kq;
}
