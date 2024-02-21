#include "bulletObject.h"

bulletObject::bulletObject()
{
    x_value=0;
    y_value=0;
    is_move=false;

}
bulletObject::~bulletObject(){

}

void bulletObject::handmove(const int &x_border, const int &y_border)
{
    if(bulletcheck==bulletright){
        rect_.x+=x_value;
        if(rect_.x>x_border)
       {
          is_move=false;
       }
    }else if(bulletcheck==bulletleft){
        rect_.x-=x_value;
       if(rect_.x<0)
       {
          is_move=false;
       }
    }

}
