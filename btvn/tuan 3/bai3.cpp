#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
    point (int a, int b){
        x=a;
        y=b;
    }
};

point trungdiem (const point A, const point B)
{
    point kq(0,0);
    kq.x=(A.x+B.x)/2;
    kq.y=(A.y+B.y)/2;
    return kq;
}

int main(){
    point temp(3,5);
    point temp2(2,6);
    point reslut=trungdiem(temp,temp2);
    cout<<reslut.x;
}
