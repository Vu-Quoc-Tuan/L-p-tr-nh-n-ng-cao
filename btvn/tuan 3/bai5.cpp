#include<iostream>
using namespace std;

struct point
{
    int a,b;
};

struct Rect
{
    int x,y;
    int w,h;

    bool contains(point P)
    {
      if(P.a>x &&P.a<(x+w) && P.b>y && P.b<(y+h)){
        return true;
      }
      return false;
    }
};
