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

void doiso(point& P){
    P.x=25;
}

void doiso(int x){
    x=25;
}

int main(){
    point temp(3,5);
    doiso(temp.x);
    cout<<temp.x<<endl;
    doiso(temp);
    cout<<temp.x;
}
