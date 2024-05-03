#include "Sound.h"

Sound::Sound()
{
    Intro=Mix_LoadMUS("Sound/.....");
    Fire =Mix_LoadWAV("Sound/...");
    T_dead=Mix_LoadWAV("Sound/...");
    Th_dead=Mix_LoadWAV("Sound/...");
    Outtro=Mix_LoadMUS("Sound/...");

    Mix_Volume(-1,10);
}

Sound::~Sound()
{
    Mix_FreeMusic(Intro);
    Mix_FreeChunk(Fire);
    Mix_FreeChunk(T_dead);
    Mix_FreeChunk(Th_dead);
    Mix_FreeMusic(Outtro);

    Intro=NULL;
    Fire=NULL;
    T_dead=NULL;
    Th_dead=NULL;
    Outtro=NULL;
}
