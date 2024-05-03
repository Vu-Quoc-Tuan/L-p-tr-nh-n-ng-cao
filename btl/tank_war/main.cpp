//#include "Compact.h"
#include "Game.h"


int main(int argc, char *argv[])
{
    SDL_Window* window=SDLWin::initSDL();
    SDL_Renderer* renderer=SDLWin::createRenderer(window);

//    MapObject game_map;
//    game_map.load_map(2);
//    game_map.load_title(renderer);
//    Map map_data=game_map.get_datamap();
//
//    Player player1;
//    player1.set_player2(true);// điểu chỉnh trạng thái
//    player1.Loadimage_main(renderer);
//
//    std::vector<Threat_object> list_threat;
//    int spawnTime =0;

Game Mgame;
Mgame.set_render(renderer);
Mgame.Start();

Uint64 last_time = SDL_GetTicks64();
    bool quit = false;
//    SDL_Event event;
    while (!quit) {

        while (SDL_PollEvent(&events) != 0) {
            if (events.type == SDL_QUIT) {
                quit = true;
            }
 //           player1.fire_action(renderer);
        }

//        spawnTime++;
//        if(spawnTime>60 && list_threat.size()<=7){
//            list_threat.push_back(Extension::spawnMonster());
//            spawnTime=0;
//        }

//        SDL_RenderClear(renderer);
//        SDL_SetRenderDrawColor(renderer,255,255,255,255);

 //       game_map.drawmap(renderer);

//        for(Threat_object &threat: list_threat){
//                threat.Loadimage_monster(renderer);
//                threat.set_clip();
//                threat.domonster(player1.get_x_pos(),player1.get_y_pos());
//                threat.Show(renderer);
//        }

//        player1.draw_bullet(renderer,map_data);
//        player1.Show(renderer);

//        SDL_RenderPresent(renderer);

       // Tính toán delta time
//      Uint64 current_time = SDL_GetTicks64();
//      float delta_time = (current_time - last_time) / 1000.0f;
//      last_time = current_time;

      // Giới hạn FPS
//      while (SDL_GetTicks64() - current_time < (1000/FPS));

      // Sử dụng delta_time trong logic game
//      player1.Update_action(renderer,map_data,delta_time);
    }

    SDLWin::quitSDL(window,renderer);
    return 0;
}
