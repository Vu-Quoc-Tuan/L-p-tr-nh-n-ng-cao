#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "common_Function.h"
#include "BaseObject.h"
#include "MainObject.h"

class monsterObject : public BaseOject
{
public:
    monsterObject();
    ~monsterObject();

    void set_x_pos (const float &xpos) {x_pos=xpos;}
    void set_y_pos (const float &ypos) {y_pos=ypos;}
    float get_x_pos ()const {return x_pos;}
    float get_y_pos () const {return y_pos;}

    void set_x_value(const float & xvalue) {x_value=xvalue;}
    void set_y_value (const float & yvalue){y_value=yvalue;}

    void set_clips();

    bool loadimg(std::string path,SDL_Renderer * screen);
    void show(SDL_Renderer * screen);
    void domonster();

 //void get_monsterspeed()


private:
    int map_x;
    int map_y;


    float x_value;
    float y_value;
    float x_pos;
    float y_pos;
    int heigh_frame;
    int weight_frame;
    int frame;
    SDL_Rect frame_clip[8];

 //   int monsterspeed;
};


#endif // MONSTER_H_INCLUDED
