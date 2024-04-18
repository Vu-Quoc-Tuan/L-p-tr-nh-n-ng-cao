#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

void in1(Point temp){
    cout<<&temp.x<<endl;
}

void in2(Point& temp){
    cout<<&temp.x<<endl;
}

int main()
{
    Point temp;
    cout<<"địa chỉ gốc:"<<&temp.x<<endl;

    in1(temp);
    in2(temp);
}
