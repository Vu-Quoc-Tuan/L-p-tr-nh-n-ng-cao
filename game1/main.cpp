#include <iostream>
#include "common_Function.h"
#include "BaseObject.h"
#include "game_map.h"
#include "MainObject.h"
#include "bulletObject.h"
#include "monster.h"

BaseOject g_background;

bool initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
    return false;
  }else{
      SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
      window=SDL_CreateWindow("by vqt",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
      if (!window) {
           std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
           exit(EXIT_FAILURE);
           return false;
      }else{
          renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

          if (!renderer) {
          std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
          exit(EXIT_FAILURE);
          return false;
          }else{
              SDL_SetRenderDrawColor(renderer,255,255,255,255);
              int imgFlags=IMG_INIT_PNG;
              if(!(IMG_Init(imgFlags)&&imgFlags)) return false;
         }
       }
  }
  return true;

}

bool loadBackground()
{
    bool ret=g_background.Loadimage("map/0.png",renderer);
    if(ret==false){
        return false;
    }else return true;

}

void quitSDL() {
  g_background.Free();
  SDL_DestroyRenderer(renderer);
  renderer=NULL;
  SDL_DestroyWindow(window);
  window=NULL;
  IMG_Quit();
  SDL_Quit();
}

    std::vector<monsterObject*> makemonsterlist()
    {
        std::vector<monsterObject*>monsterlist;
        monsterObject* listmon=new monsterObject[2];
        for(int i=1;i<=2;i++)
        {
            monsterObject * threat=(listmon+i);
            threat->loadimg("images/player_right.png",renderer);
            threat->set_clips();
            threat->set_x_pos(i*100);
            threat->set_y_pos(25);
            monsterlist.push_back(threat);

        }
    return monsterlist;
    }

int main(int argc, char* argv[])
{
    if(initSDL()==false){
        return -1;
    }
    if(loadBackground()==false){
        return -1;
    }

    GameMap game_map;
    game_map.Loadmap("map/map01.dat");
    game_map.LoadTitle(renderer);


    MainObject player;
    player.Loadimage("images/test.png",renderer);
    player.set_clips();

std::vector<monsterObject*>monsterlist=makemonsterlist();

    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            player.Handinputaction(event,renderer);
        }
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
        g_background.Render(renderer,NULL);
        game_map.drawmap(renderer);

        player.handbullet(renderer);
        player.doplayer();
        player.Show(renderer);

for(int i=1;i<=monsterlist.size();i++){
    monsterObject * trunggian=monsterlist.at(i);
    if(trunggian!=NULL){
        trunggian->domonster();
        trunggian->show(renderer);
    }
}

        SDL_RenderPresent(renderer);
    }

    quitSDL();

    return 0;
}
