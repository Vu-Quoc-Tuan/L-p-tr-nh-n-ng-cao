#include<iostream>
#include<string>
using namespace std;

struct Rect
{
    int x,y;
    int w,h;
    Rect(){};
};

struct Ship
{
    Rect sizeship;
    string id;

    int dx;
    int dy;

    Ship(){};

    void move(){
        sizeship.x+=dx;
        sizeship.y+=dy;
    }
};

void display(const Ship& ship)
{
    cout<<ship.sizeship.x<<" "<<ship.sizeship.y<<endl;
    cout<<ship.id<<endl;
}

int main()
{
    Ship temp1;
    Ship temp2;
int loop=2;
    while(loop--){
        temp1.move();
        temp2.move();
        display(temp1);
        display(temp2);
    }
    return 0;
}
