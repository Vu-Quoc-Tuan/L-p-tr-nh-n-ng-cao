#include "Game.h"

Game::Game()//tất cả các ảnh và vị trí thì chưa được chỉnh sửa, chx them nhacj,mau
{

}

Game::~Game()
{
    g_sound.~Sound();
}

void Game::set_render(SDL_Renderer* screen)
{
    renderer=screen;

    g_player.set_player2(true);
    g_player.Loadimage_main(renderer);


    //menu
    g_text[0].set_color(253,226,202);//236	135	14

    g_text[1].set_color(253,226,202);//236	135	14

    g_text[2].set_color(253,226,202);//236	135	14

    g_text[3].set_color(253,226,202);//236	135	14

    //end game
    g_text[4].set_color(253,226,202);//236	135	14

    g_text[5].set_color(253,226,202);//236	135	14

    g_text[6].set_color(253,226,202);//236	135	14

    //score
    g_text[7].set_color(0,0,0);

}

OPTION Game::Show_menu()
{
    Graphics bgr;
    bgr.Loadimage_base("Image/tamthoi/start_menu.png",renderer);
    bgr.setforbackground();
    int status=4;

    int mouse_X,mouse_Y;

    OPTION res=OPTION::NO;
    while(res==NO)
    {
        SDL_RenderClear(renderer);

        bgr.render(renderer);
        g_text[0].Loadtext("SINGLEPLAYER",renderer,1);
        g_text[1].Loadtext("MULTIPLAYER",renderer,1);
        g_text[2].Loadtext("HELP",renderer,1);
        g_text[3].Loadtext("EXIT",renderer,1);

        g_text[0].render_text(375,300,renderer);
        g_text[1].render_text(375,330,renderer);
        g_text[2].render_text(375,360,renderer);
        g_text[3].render_text(375,390,renderer);

        //thêm 1 nút cài đặt ở góc dưới bên phải

        while(SDL_PollEvent(&events)!=0)
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION:
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    for(int i=0;i<status;i++)
                    {
                        SDL_Rect temp=g_text[i].get_rect();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_text[i].set_color(236,135,14);
                        }else{
                            g_text[i].set_color(253,226,202);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    for(int i=0;i<status;i++)
                    {
                        SDL_Rect temp=g_text[i].get_rect();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            if(i==0) return SINGLEPLAYER;
                            else if(i==1) return MULTIPLAYER;
                            else if(i==2) return HELP;
                            else return EXIT_GAME;
                        }
                    }
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    return EXIT_GAME;
}

OPTION Game::Show_help() {
    Graphics i_help;
    i_help.Loadimage_base("Image/tamthoi/game_over.png", renderer);
    i_help.setforbackground();
    while (true) {
        SDL_Event events;
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_KEYDOWN) {
                // Phím được nhấn, thoát vòng lặp
                return OPTION::HOME;
            }
        }
        SDL_RenderClear(renderer);
        i_help.render(renderer);
        SDL_RenderPresent(renderer);
    }
    return OPTION::HOME;
}

OPTION Game::End_game()
{
    Graphics image_end;
    image_end.Loadimage_base("Image/tamthoi/game_over.png",renderer);
    image_end.setforbackground();
    int status_begin=5;
    int status_end=6;

    int mouse_X, mouse_Y;
    while(true)
    {
        SDL_RenderClear(renderer);

        image_end.render(renderer);

        g_text[4].Loadtext("Score:"+std::to_string (g_score),renderer,Font4);
        g_text[5].Loadtext("HOME",renderer,Font4);
        g_text[6].Loadtext("EXIT",renderer,Font4);

        g_text[4].render_text(375,300,renderer);
        g_text[5].render_text(375,350,renderer);
        g_text[6].render_text(375,400,renderer);

        while(SDL_PollEvent(&events)!=0)
        {
            switch(events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION :
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_text[i].get_rect();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_text[i].set_color(236,135,14);
                        }else{
                            g_text[i].set_color(253,226,202);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_text[i].get_rect();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            if(i==5) return OPTION::HOME;
                            else return EXIT_GAME;
                        }
                    }
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    return EXIT_GAME;
}

OPTION Game::Pause_game()
{
    Graphics temp;
    temp.Loadimage_base("anhpause",renderer);
    temp.set_rect(300,400);
    int mouse_X, mouse_Y;

    while(true)
    {
        temp.render(renderer);

        while(SDL_PollEvent(&events)!=0)
        {
            if(events.type==SDL_MOUSEBUTTONDOWN)
            {
                mouse_X=events.motion.x;
                mouse_Y=events.motion.y;

                SDL_Rect n_restart={1,2,3,4};
                SDL_Rect n_resume ={1,2,3,4};
                SDL_Rect n_home   ={1,2,3,4};

                if(Extension::pointed_to(mouse_X,mouse_Y,n_restart))     return OPTION::REPLAY;
                else if(Extension::pointed_to(mouse_X,mouse_Y,n_home))   return OPTION::HOME;
                else if(Extension::pointed_to(mouse_X,mouse_Y,n_resume)) return OPTION::NO;
            }
        }
        SDL_RenderPresent(renderer);
    }
    return OPTION::NO;
}

OPTION Game::Play_single()
{
    Reset_game();
    g_player.set_player2(false);

    game_map.load_map(1);
    game_map.load_title(renderer);
    Map map_data= game_map.get_datamap();

    int spawnTime=0;
//    int itemspawn=0;

//    g_time.Start();

    bool quit=false;

    while(!quit)
    {
        int staticks=SDL_GetTicks64();

        while(SDL_PollEvent(&events)!=0)
        {
            if (events.type == SDL_QUIT) {
                quit = true;
                break;
            }
            if (events.type==SDL_KEYDOWN && events.key.keysym.sym==SDLK_p){
                OPTION current = Pause_game();
                if(current==REPLAY)     return Play_single();
                else if(current==HOME)  return Show_menu();
            }

            g_player.fire_action(renderer);
        }

        spawnTime++;
        if(spawnTime>60 && list_threat.size()<=7)
        {
            list_threat.push_back(spawnMonster());
            spawnTime=0;
        }

//        itemspawn++;
//        if(itemspawn>100 && list_item.size()<=8)
//        {
//            list_item.push_back(spawn_item());
//            itemspawn=0;
//        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        game_map.drawmap(renderer);

        g_text[7].Loadtext("SCORE:"+std::to_string(g_score),renderer,Font3);
        g_text[7].render_text(0,0,renderer);

        load_threat();
//        load_item  ();

        g_player.draw_bullet(renderer,map_data);
        g_player.Show(renderer);

        SDL_RenderPresent(renderer);

        int frame_tick=SDL_GetTicks64()-staticks;
        if(frame_tick<1000/FPS){
          SDL_Delay(1000/FPS-frame_tick);
        }

        g_player.Update_action(renderer,map_data);

    }
}

OPTION Game::Play_mutile()
{
    Reset_game();
    g_player.set_player2(true);

    game_map.load_map(1);
    game_map.load_title(renderer);
    Map map_data= game_map.get_datamap();

//    int itemspawn=0;

    bool quit=false;

    while(!quit)
    {
        int staticks=SDL_GetTicks64();

        while(SDL_PollEvent(&events)!=0)
        {
            if (events.type == SDL_QUIT) {
                quit = true;
                break;
            }
            if (events.type==SDL_KEYDOWN && events.key.keysym.sym==SDLK_p){
                OPTION current = Pause_game();
                if(current==REPLAY)     return Play_mutile();
                else if(current==HOME)  return Show_menu();
            }

            g_player.fire_action(renderer);
        }

//        itemspawn++;
//        if(itemspawn>100 && list_item.size()<=7)
//        {
//            list_item.push_back(spawn_item());
//            itemspawn=0;
//        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        game_map.drawmap(renderer);

//        load_item();

        g_player.draw_bullet(renderer,map_data);
        g_player.Show(renderer);

        SDL_RenderPresent(renderer);

        int frame_tick=SDL_GetTicks64()-staticks;
        if(frame_tick<1000/FPS){
          SDL_Delay(1000/FPS-frame_tick);
        }

        g_player.Update_action(renderer,map_data);

    }
}






void Game::Reset_game()/////
{
    g_score=0;
    g_player.set_type_bullet1(rocket);
    g_player.set_type_bullet2(normal);
    list_item.clear();
    list_threat.clear();
}

void Game::show_score()
{
    g_text[7].Loadtext("Score:"+std::to_string (g_score),renderer,Font3);
    g_text[7].render_text(0,0,renderer);
}




void Game::Start()
{
    OPTION current_option=Show_menu();
    do
    {
        switch (current_option)//add setting if it is posible and high score
        {
            case OPTION::EXIT_GAME :
                return;
            case OPTION::HELP :
                current_option=Show_help();
                break;
            case OPTION::HOME :
                //reset lại
                current_option=Show_menu();
                break;
            case OPTION::SINGLEPLAYER :
                Reset_game();
                current_option=Play_single();
                break;
            case OPTION::MULTIPLAYER :
                Reset_game();
                current_option=Play_mutile();


            default:
                current_option=OPTION::EXIT_GAME;
                break;
        }

    }while(true);
}




void Game::load_item()
{
    for(item &temp: list_item)
    {
        temp.load_image_item(renderer);
        temp.set_type();
        temp.show_item(renderer);
    }
}

item Game::spawn_item()
{
    item temp;
    temp.set_distination(game_map.get_datamap());
    return temp;
}

void Game::load_threat()
{
    for(Threat_object &threat: list_threat){
        threat.Loadimage_monster(renderer);
        threat.set_clip();
        threat.domonster(g_player.get_rect_player1().x,g_player.get_rect_player1().y);
        threat.Show(renderer);
    }
}

Threat_object Game::spawnMonster()
{
    Threat_object monster;
    int x = rand() % SCREEN_WIDTH;
    int y = rand() % SCREEN_HEIGHT;
    monster.set_destination(x,y);
    return monster;
}
