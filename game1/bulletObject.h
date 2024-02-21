#ifndef BULLETOBJECT_H_INCLUDED
#define BULLETOBJECT_H_INCLUDED

#include "common_Function.h"
#include "BaseObject.h"


class bulletObject : public BaseOject
{
public:
    bulletObject();
    ~bulletObject();

    enum bulletcheck
    {
        bulletright=20,
        bulletleft=21
    };

    void set_x_value(const int &xvl) { x_value = xvl; }
    void set_y_value(const int &yvl) { y_value = yvl; }
    int get_x_value() { return x_value; }
    int get_y_value() { return y_value; }
    void set_is_move(const bool &movevl) { is_move = movevl; }
    bool get_is_move() { return is_move; }

    void set_bulletcheck(const int &checkvar){ bulletcheck=checkvar;}
    int get_bulletcheck() {return bulletcheck;}

    void handmove(const int &x_border, const int &y_border);

private:
    int x_value;
    int y_value;
    bool is_move;
    unsigned int bulletcheck;
};

#endif // BULLETOBJECT_H_INCLUDED
