#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED

#include "common_Function.h"
#include "BaseObject.h"
#include "bulletObject.h"
#include <vector>




class MainObject : public BaseOject
{
public:
    MainObject();
    ~MainObject();

    enum Walktype
    {
        WALK_RIGHT=0,
        WALK_LEFT=1
    };

    bool Loadimage(std::string path,SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void Handinputaction(SDL_Event events,SDL_Renderer* screen);
    void set_clips();
    void doplayer();

    void set_bulletlist(std::vector<bulletObject*> bulletlist){
    p_bulleobject_list = bulletlist;
    }

    std::vector<bulletObject*> get_bullet_list() const {return p_bulleobject_list;}

    void handbullet(SDL_Renderer* screen);
private:

    std::vector <bulletObject*>p_bulleobject_list;

    float x_value_;
    float y_value_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip[10];
    Input intput_type;
    int frame_;
    int status_;
};

#endif // MAINOBJECT_H_INCLUDED
