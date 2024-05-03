#include "Kit.h"

item::item()
{
    type=1;
}
bool item::load_image_item(SDL_Renderer* screen)
{
    bool temp;
    if(type==laser)
    {
        temp=Graphics::Loadimage_base("box load laser",screen);
    }else if(type==rocket){
        temp=Graphics::Loadimage_base("box load roket", screen);
    }else {
        temp=Graphics::Loadimage_base("box load armor", screen);
    }
    return temp;
}

void item::set_type()
{
    srand(time(NULL));
    type=rand()%3;
}

void item::set_distination(const Map& map_data)
{
    bool check=false;
    while(!check)
    {
        srand(time(NULL));
        int tempx=rand()%SCREEN_WIDTH;
        int tempy=rand()%SCREEN_HEIGHT;
        if(map_data.tile[tempy][tempx]==0){
            rect_.x=tempx;
            rect_.y=tempy;
            break;
        }
    }
}

void item::show_item(SDL_Renderer* screen)
{
    SDL_RenderCopy(screen,texture,NULL,&rect_);
}
