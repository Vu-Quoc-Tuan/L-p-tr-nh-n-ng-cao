#ifndef THREAT_H_INCLUDED
#define THREAT_H_INCLUDED

#include "Graphics.h"
#include "Settings.h"

class Threat_object : public Graphics
{
public:
    Threat_object();
    ~Threat_object(){;}

    bool Loadimage_monster(SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    void set_clip();

    void domonster (const int dest_x, const int dest_y);

    void set_destination (const int x, const int y) {x_pos_=x;
                                                     y_pos_=y;}



private:
    float x_pos_;
    float y_pos_;
    float x_value_;
    float y_value_;

    int height_frame;
    int weight_frame;
    int frame_;
    SDL_Rect frame_clip[9];
};

#endif // THREAT_H_INCLUDED
