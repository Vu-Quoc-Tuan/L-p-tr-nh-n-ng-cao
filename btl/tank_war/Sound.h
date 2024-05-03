#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include"Settings.h"

class Sound
{
public:
    Sound();
    ~Sound();

    void Playintro()  {Mix_PlayMusic(Intro,-1);}
    void PlayFire()   {Mix_PlayChannel(0,Fire,0);}
    void PlayT_dead() {Mix_PlayChannel(1,T_dead,0);}
    void PlayTh_dead(){Mix_PlayChannel(2,Th_dead,0);}
    void PlayOuttro() {Mix_PlayMusic(Outtro,-1);}

private:
    Mix_Music* Intro;
    Mix_Chunk* Fire;
    Mix_Chunk* T_dead;
    Mix_Chunk* Th_dead;
    Mix_Music* Outtro;
};


#endif // SOUND_H_INCLUDED
