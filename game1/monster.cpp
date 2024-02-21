#include "monster.h"

monsterObject::monsterObject()
{
    x_pos=0;
    y_pos=0;
    x_value=0;
    y_value=0;
    frame=0;
    heigh_frame=0;
    weight_frame=0;
}

monsterObject::~monsterObject()
{

}

bool monsterObject::loadimg(std::string path, SDL_Renderer * screen)
{
    bool result = BaseOject::Loadimage(path,screen);
    if(result){
        heigh_frame=rect_.h;
        weight_frame=rect_.w/8;
    }
    return result;
}

void monsterObject::set_clips()
{
    if(heigh_frame>0 && weight_frame>0)
    {
      for(int i=0;i<8;i++){
        frame_clip[i].x=i*weight_frame;
        frame_clip[i].y=0;
        frame_clip[i].w=weight_frame;
        frame_clip[i].h=heigh_frame;
      }

    }
}

void monsterObject::show(SDL_Renderer *screen)
{
    rect_.x=x_pos;
    rect_.y=y_pos;
    frame++;

    if(frame>=8)
    {
        frame=0;
    }
    SDL_Rect * currenclip=& frame_clip[frame];
    SDL_Rect renaqua={rect_.x,rect_.y,heigh_frame,weight_frame};
    SDL_RenderCopy(screen,p_object,currenclip,&renaqua);
}


