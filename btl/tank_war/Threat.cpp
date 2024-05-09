#include "Threat.h"

Threat_object::Threat_object()
{
    x_value_=0;
    y_value_=0;
    x_pos_=0;
    y_pos_=0;
    frame_=0;
    height_frame=0;
    weight_frame=0;
}
bool Threat_object::Loadimage_monster(SDL_Renderer* screen)
{
    bool temp=Loadimage_base("Image/threat/quai2.png",screen);

    height_frame=rect_.h;
    weight_frame=rect_.w/8;

    return temp;
}

void Threat_object::set_clip()
{
    if(height_frame>0 && weight_frame>0){
        for(int i=0;i<8;i++)
        {
            frame_clip[i].x=weight_frame*i;
            frame_clip[i].y=0;
            frame_clip[i].w=weight_frame;
            frame_clip[i].h=height_frame;
        }
    }
}

void Threat_object::domonster(const int dest_x, const int dest_y)
{
    if(dest_x-x_pos_>0){
        if(dest_x-x_pos_<=THREAT_SPEED_x) x_pos_+=(dest_x-x_pos_);
        else x_pos_+=THREAT_SPEED_x;
    }else {
        if(x_pos_-dest_x<=THREAT_SPEED_x) x_pos_+=(dest_x-x_pos_);
        else x_pos_-=THREAT_SPEED_x;
    }

    if(dest_y-y_pos_>0){
        if(dest_y-y_pos_<=THREAT_SPEED_y) y_pos_+=(dest_y-y_pos_);
        else y_pos_+=THREAT_SPEED_y;
    }else {
        if(y_pos_-dest_y<=THREAT_SPEED_y) y_pos_+=(dest_y-y_pos_);
        else y_pos_-=THREAT_SPEED_y;
    }
}

void Threat_object::Show(SDL_Renderer* screen)
{
    frame_++;
    frame_=frame_%8;
    rect_.x=x_pos_;rect_.y=y_pos_;
    SDL_Rect renderquad={x_pos_,y_pos_,weight_frame,height_frame};
    SDL_Rect* currentclip= &frame_clip[frame_];
    SDL_RenderCopy(screen,texture,currentclip,&renderquad);
}


