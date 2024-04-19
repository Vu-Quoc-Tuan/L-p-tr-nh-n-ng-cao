#include<bits/stdc++.h>
using namespace std;

int main()
{
     int* p = new int;
     int* p2 = p;
     *p = 10;
     delete p;// lỗi do địa chỉ mà p trỏ vào được giải phòng và đó cũng là địa chỉ p2 trỏ vào
    *p2 = 100;
     cout << *p2;
     delete p2;
}
