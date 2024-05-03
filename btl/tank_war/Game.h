#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Compact.h"

class Game
{
public:
    Game();
    ~Game();

    void Start();
    void set_render(SDL_Renderer* screen);

private:
    //global
    SDL_Renderer* renderer;

    //load
    MapObject game_map;
    Player g_player;

    //threat
    std::vector<Threat_object> list_threat;
    Threat_object spawnMonster();
    void load_threat();

    //item
    std::vector<item> list_item;
    item spawn_item();
    void load_item();

    //time
    Timer g_time;

    //score
    int g_score;
    void show_score();

    //sound
    Sound g_sound;

    //text
    LText g_text[20];

    //method
    OPTION Play_single();
    OPTION Play_mutile();
    OPTION End_game ();
    OPTION Show_menu();
    OPTION Show_help();
    OPTION Pause_game();

    void Reset_game ();

};

#endif // GAME_H_INCLUDED
