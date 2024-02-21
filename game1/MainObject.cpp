#include "MainObject.h"

MainObject::MainObject()
{
    frame_=0;
    x_pos_=0;
    y_pos_=0;
    x_value_=0;
    y_value_=0;
    width_frame_=0;
    height_frame_=0;
    status_=-1;
    intput_type.left_=0;
    intput_type.right_=0;
    intput_type.down_=0;
    intput_type.jump_=0;
    intput_type.up_=0;
}

MainObject::~MainObject()
{

}

bool MainObject::Loadimage(std::string path, SDL_Renderer* screen)
{
    bool ret= BaseOject::Loadimage(path,screen);
    if(ret==true){
       width_frame_=rect_.w/5;
       height_frame_=rect_.h/2;
    }
    return ret;
}

void MainObject::set_clips()
{
    if(width_frame_>0 && height_frame_>0)
    {
        frame_clip[0].x=0;
        frame_clip[0].y=0;
        frame_clip[0].w=width_frame_;
        frame_clip[0].h=height_frame_;

        frame_clip[1].x=width_frame_;
        frame_clip[1].y=0;
        frame_clip[1].w=width_frame_;
        frame_clip[1].h=height_frame_;

        frame_clip[2].x=2*width_frame_;
        frame_clip[2].y=0;
        frame_clip[2].w=width_frame_;
        frame_clip[2].h=height_frame_;

        frame_clip[3].x=3*width_frame_;
        frame_clip[3].y=0;
        frame_clip[3].w=width_frame_;
        frame_clip[3].h=height_frame_;

        frame_clip[4].x=4*width_frame_;
        frame_clip[4].y=0;
        frame_clip[4].w=width_frame_;
        frame_clip[4].h=height_frame_;

        frame_clip[5].x=0;
        frame_clip[5].y=height_frame_;
        frame_clip[5].w=width_frame_;
        frame_clip[5].h=height_frame_;

        frame_clip[6].x=width_frame_;
        frame_clip[6].y=height_frame_;
        frame_clip[6].w=width_frame_;
        frame_clip[6].h=height_frame_;

        frame_clip[7].x=2*width_frame_;
        frame_clip[7].y=height_frame_;
        frame_clip[7].w=width_frame_;
        frame_clip[7].h=height_frame_;

        frame_clip[8].x=3*width_frame_;
        frame_clip[8].y=height_frame_;
        frame_clip[8].w=width_frame_;
        frame_clip[8].h=height_frame_;

        frame_clip[9].x=4*width_frame_;
        frame_clip[9].y=height_frame_;
        frame_clip[9].w=width_frame_;
        frame_clip[9].h=height_frame_;

    }
}

void MainObject::Show(SDL_Renderer* des)
{
    if(status_==WALK_RIGHT){
        Loadimage("images/test.png",des);
    }
    if (intput_type.right_ == 1) {
        frame_++;
    } else {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip[frame_];

    SDL_Rect rendererquad = { rect_.x, rect_.y, width_frame_, height_frame_ };
    SDL_RenderCopy(des, p_object, current_clip, &rendererquad);
}
void MainObject::Handinputaction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
            case SDLK_RIGHT:
                status_ = WALK_RIGHT;
                intput_type.right_ = 1;
                intput_type.left_ = 0;
                break;

            case SDLK_LEFT:
                status_ = WALK_LEFT;
                intput_type.left_ = 1;
                intput_type.right_ = 0;
                break;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
            case SDLK_RIGHT:
                intput_type.right_ = 0;
                break;

            case SDLK_LEFT:
                intput_type.left_ = 0;
                break;
        }
    }
    else if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_RIGHT)
        {
            // Xử lý khi người dùng nhấn nút chuột phải
            bulletObject* p_bullet = new bulletObject;
            p_bullet->Loadimage("images/bullet.png", screen);

            if (status_ == WALK_RIGHT) {
                p_bullet->set_bulletcheck(bulletObject::bulletright);
                p_bullet->SetRect(this->rect_.x + width_frame_- 20, rect_.y + height_frame_ * 0.3);
            } else if (status_ == WALK_LEFT) {
                p_bullet->set_bulletcheck(bulletObject::bulletleft);
                p_bullet->SetRect(this->rect_.x  - 20, rect_.y + height_frame_ * 0.3);
            }

            p_bullet->set_x_value(30);
            p_bullet->set_is_move(true);

            p_bulleobject_list.push_back(p_bullet);
        }
    }
}



void MainObject::doplayer()
{
    x_value_ = 0;
    y_value_ += 0.8;

    y_pos_+=y_value_;
    if(y_pos_>=25){
        y_pos_=25;
    }

    if (intput_type.left_ == 1) {
        x_value_ -= 8;
    }
    else if (intput_type.right_ == 1) {
        x_value_ += 8;
    }
    x_pos_ += x_value_;
}

void MainObject::handbullet(SDL_Renderer* screen)
{
    for(int i = 0; i < p_bulleobject_list.size(); i++)
    {
        bulletObject* bullet = p_bulleobject_list[i];
        if(bullet != NULL)
        {
            if (bullet->get_is_move())
            {
                bullet->handmove(SCREEN_WIDTH, SCREEN_HEIGHT);
                bullet->Render(screen);
            }
            else
            {
                p_bulleobject_list.erase(p_bulleobject_list.begin() + i);
            }
        }
    }
}
