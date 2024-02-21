#ifndef GAME_MAP_H_INCLUDED
#define GAME_MAP_H_INCLUDED

#include "common_Function.h"
#include "BaseObject.h"

#define MAX_titles 20

class TitleMat : public BaseOject
{
public:
    TitleMat(){;}
    ~TitleMat(){;}
};

class GameMap
{
public:
    GameMap(){;}
    ~GameMap(){;}

    void Loadmap(char* nam);
    void LoadTitle(SDL_Renderer* screen);
    void drawmap(SDL_Renderer* screen);
private:
    Map game_map_;
    TitleMat title_mat[MAX_titles];
};

#endif // GAME_MAP_H_INCLUDED
