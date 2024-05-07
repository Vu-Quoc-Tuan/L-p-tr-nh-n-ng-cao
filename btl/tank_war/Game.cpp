#include "Game.h"

Game::Game()//tất cả các ảnh và vị trí thì chưa được chỉnh sửa, chx them nhacj,mau
{
//phần button:
    //menu
    g_button[0].set_rect(318,228);//button single
    g_button[1].set_rect(314,328);//button multiple
    g_button[2].set_rect(335,436);//button help
    g_button[3].set_rect(330,562);//button exit
    g_button[4].set_rect(837,660);//button rank    chux suawr

    //help
    g_button[5].set_rect(0,620);//button return

    //pause
    g_button[6].set_rect(334,297);//button restart
    g_button[7].set_rect(372,366);//button continue
    g_button[8].set_rect(411,296);//button home
    g_button[9].set_rect(493,296);//button music

    //end game
    g_button[10].set_rect(363,283);//button restart
    g_button[11].set_rect(389,377);//button home
    g_button[12].set_rect(394,454);//button exit

    //in match
    g_button[13].set_rect(0,0);//button pause


//phần Text:
    //score in single
    g_text[0].set_color(0,0,0);

    //score in multiple
    g_text[1].set_color(0,0,0);
    g_text[2].set_color(0,0,0);

    //score in end
    g_text[3].set_color(0,0,0); //single
    g_text[4].set_color(0,0,0); //multiple

    //high score
    g_text[5].set_color(0,0,0);
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
}


OPTION Game::Show_menu()
{
    g_sound.Playintro();
    Graphics bgr;
    bgr.Loadimage_base("Image/background/start.png",renderer);
    bgr.setforbackground();

    int status=5;
    int dem=1;
    int mouse_X,mouse_Y;

    OPTION res=OPTION::NO;
    while(res==NO)
    {
        SDL_RenderClear(renderer);

        g_button[0].Loadimage_base("Image/background/button/menu11.png",renderer);
        g_button[1].Loadimage_base("Image/background/button/menu21.png",renderer);
        g_button[2].Loadimage_base("Image/background/button/menu31.png",renderer);
        g_button[3].Loadimage_base("Image/background/button/menu41.png",renderer);
        g_button[4].Loadimage_base("Image/background/button/menu51.png",renderer);

        while(SDL_PollEvent(&events)!=0)
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION:
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    dem=1;
                    for(int i=0;i<status;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_button[i].Loadimage_base(("Image/background/button/menu"+std::to_string(dem)+"2.png").c_str(),renderer);
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/menu"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    dem=1;
                    for(int i=0;i<status;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_sound.PlayClick();
                            if(i==0){
                                res= OPTION::SINGLEPLAYER;
                                g_button[0].Loadimage_base("Image/background/button/menu13.png",renderer);
                            }
                            else if(i==1){
                                res= OPTION::MULTIPLAYER;
                                g_button[1].Loadimage_base("Image/background/button/menu23.png",renderer);
                            }
                            else if(i==2){
                                res= OPTION::HELP;
                                g_button[2].Loadimage_base("Image/background/button/menu33.png",renderer);
                            }
                            else if(i==4){
                                res= OPTION::RANK;
                                g_button[4].Loadimage_base("Image/background/button/menu53.png",renderer);
                            }
                            else if(i==3){
                                res= OPTION::EXIT_GAME;
                                g_button[3].Loadimage_base("Image/background/button/menu43.png",renderer);
                            }
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/menu"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;
            }
        }
        bgr.render(renderer);
        for(int i=0;i<status;i++) g_button[i].render(renderer);

        SDL_RenderPresent(renderer);
    }
    g_sound.Haltmusic();
    return res;
}

OPTION Game::Show_help() {
    Graphics i_help;
    i_help.Loadimage_base("Image/background/help.png", renderer);
    i_help.setforbackground();

    int mouse_X,mouse_Y;
    OPTION res=OPTION::NO;

    while (res==NO) {
        SDL_RenderClear(renderer);

        g_button[5].Loadimage_base("Image/background/button/help1.png",renderer);

        while (SDL_PollEvent(&events)!=0) {
            switch (events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION:{
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    SDL_Rect temp=g_button[5].get_rect_();

                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_button[5].Loadimage_base("Image/background/button/help2.png",renderer);
                    }else{
                        g_button[5].Loadimage_base("Image/background/button/help1.png",renderer);
                    }
                    break;}

                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.button.x;
                    mouse_Y=events.button.y;
                    SDL_Rect temp=g_button[5].get_rect_();

                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_sound.PlayClick();
                        res=OPTION::HOME;
                        g_button[5].Loadimage_base("Image/background/button/help3.png",renderer);
                    }else{
                        g_button[5].Loadimage_base("Image/background/button/help1.png",renderer);
                    }
                    break;
            }
        }
        i_help.render(renderer);
        g_button[5].render(renderer);
        SDL_RenderPresent(renderer);
    }
    return res;
}

OPTION Game::End_game()
{
    g_sound.PlayOuttro();
    if(g_score!=0){
        g_text[3].Loadtext("YOU LOSE",renderer,Font4);
    }else{
        g_text[4].Loadtext("End Game",renderer,Font4);
    }

    int status_begin=10;
    int status_end=12;

    int mouse_X, mouse_Y;
    OPTION res=OPTION::NO;

    while(res==NO)
    {

        g_button[10].Loadimage_base("Image/background/button/end11.png",renderer);
        g_button[11].Loadimage_base("Image/background/button/end21.png",renderer);
        g_button[12].Loadimage_base("Image/background/button/end31.png",renderer);


        while(SDL_PollEvent(&events)!=0)
        {
            switch(events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION :{
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    int dem=1;

                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_button[i].Loadimage_base(("Image/background/button/end"+std::to_string(dem)+"2.png").c_str(),renderer);
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/end"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;}

                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.button.x;
                    mouse_Y=events.button.y;
                    int dem=1;

                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))/////
                        {
                            g_sound.PlayClick();
                            if(i==10)      res=OPTION::SINGLEPLAYER;
                            else if(i==11) res=OPTION::HOME;
                            else if(i==12) res=OPTION::EXIT_GAME;
                            g_button[i].Loadimage_base(("Image/background/button/end"+std::to_string(dem)+"3.png").c_str(),renderer);
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/end"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;
            }
        }
        if(g_score!=0){
            g_text[3].render_text(323,223,renderer);
        }else{
            g_text[4].render_text(323,223,renderer);
        }
        for(int i=status_begin;i<=status_end;i++) g_button[i].render(renderer);

        SDL_RenderPresent(renderer);
    }
    g_sound.Haltmusic();
    return res;
}

OPTION Game::Pause_game()
{
    Graphics temp;
    temp.Loadimage_base("Image/background/button/pause.png",renderer);
    temp.set_rect(358,214);

    int status_begin=6;
    int status_end=9;
    int mouse_X, mouse_Y;
    int dem=1;

    OPTION res=OPTION::NO;
    while(res==NO)
    {
        dem=1;
        for(int i=status_begin;i<=status_end;i++){
            g_button[i].Loadimage_base(("Image/background/button/pause"+std::to_string(dem)+"1.png").c_str(),renderer);
            dem++;
        }

        while(SDL_PollEvent(&events)!=0)
        {
            switch(events.type)
            {
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
                case SDL_MOUSEMOTION :{
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;
                    dem=1;

                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                        {
                            g_button[i].Loadimage_base(("Image/background/button/pause"+std::to_string(dem)+"2.png").c_str(),renderer);
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/pause"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;}

                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.button.x;
                    mouse_Y=events.button.y;
                    dem=1;

                    for(int i=status_begin;i<=status_end;i++)
                    {
                        SDL_Rect temp=g_button[i].get_rect_();
                        if(Extension::pointed_to(mouse_X,mouse_Y,temp))/////
                        {
                            g_sound.PlayClick();
                            if(i==6)      res=OPTION::REPLAY;
                            else if(i==7) res=OPTION::CONTINUE;
                            else if(i==8) res=OPTION::HOME;
                            else if(i==9) //TAWTR NHAC
                            g_button[i].Loadimage_base(("Image/background/button/pause"+std::to_string(dem)+"3.png").c_str(),renderer);
                        }else{
                            g_button[i].Loadimage_base(("Image/background/button/pause"+std::to_string(dem)+"1.png").c_str(),renderer);
                        }
                        dem++;
                    }
                    break;
            }
        }

        temp.render(renderer);
        for(int i=status_begin;i<=status_end;i++)
            g_button[i].render(renderer);

        SDL_RenderPresent(renderer);
    }
    return res;
}

OPTION Game::Play_single()//sẽ đổi map
{
    Reset_game();

    Graphics back_ground;
    back_ground.Loadimage_base("Image/background/multiple.png",renderer);
    back_ground.setforbackground();

    g_player.set_player2(false);

    game_map.load_map(1);
    game_map.load_title(renderer);
    Map map_data= game_map.get_datamap();

    int mouse_X, mouse_Y;

    int spawnTime=0;
    int itemspawn=0;

//    g_time.Start();

    OPTION res= OPTION::NO;

    while(res==NO)
    {
        int staticks=SDL_GetTicks64();
        g_text[0].Loadtext("SCORE:"+std::to_string(g_score),renderer,Font3);
        g_button[13].Loadimage_base("Image/background/button/ingame1.png",renderer);


        while(SDL_PollEvent(&events)!=0)
        {
            switch (events.type){
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;
//                case SDL_KEYDOWN:
//                    if (events.key.keysym.sym == SDLK_p){
//                        OPTION current = Pause_game();
//                        if(current==REPLAY)     res= OPTION::SINGLEPLAYER;
//                        else if(current==HOME)  res=OPTION::HOME;
//                    }
//                    break;

                case SDL_MOUSEMOTION:{
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;

                    SDL_Rect temp=g_button[13].get_rect_();

                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_button[13].Loadimage_base("Image/background/button/ingame2.png",renderer);
                    }else{
                        g_button[13].Loadimage_base("Image/background/button/ingame1.png",renderer);
                    }
                    break;}

                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.button.x;
                    mouse_Y=events.button.y;

                    SDL_Rect temp=g_button[13].get_rect_();
                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_sound.PlayClick();
                        OPTION current = Pause_game();
                        if(current==REPLAY)     res= OPTION::SINGLEPLAYER;
                        else if(current==HOME)  res=OPTION::HOME;
                    }

                    break;

            }
            g_player.fire_action(renderer);
        }

        spawnTime++;
        if(spawnTime>60 && list_threat.size()<=7)
        {
            list_threat.push_back(spawnMonster());
            spawnTime=0;
        }
        down_hp();
        delete_threat();
        itemspawn++;
        if(itemspawn>500 && list_item.size()<=5)
        {
            list_item.push_back(spawn_item());
            itemspawn=0;
        }

        if(hp<=0) res=End_game();

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        back_ground.render(renderer);
        game_map.drawmap(renderer);


        g_text[0].render_text(750,5,renderer);

        load_threat();
        load_item  (map_data);
        upgrade();

        g_player.draw_bullet(renderer,map_data);
        g_player.Show(renderer);
        g_button[13].render(renderer);

        SDL_RenderPresent(renderer);

        int frame_tick=SDL_GetTicks64()-staticks;
        if(frame_tick<1000/FPS){
          SDL_Delay(1000/FPS-frame_tick);
        }

        g_player.Update_action(renderer,map_data);

    }
    return res;
}

OPTION Game::Play_mutile()
{
    Reset_game();

    Graphics back_ground;
    back_ground.Loadimage_base("Image/background/multiple.png",renderer);
    back_ground.setforbackground();

    g_player.set_player2(true);

    game_map.load_map(1);
    game_map.load_title(renderer);
    Map map_data= game_map.get_datamap();

    int itemspawn=0;
    int mouse_X, mouse_Y;

    OPTION res= OPTION::NO;

    while(res==NO)
    {
        int staticks=SDL_GetTicks64();

        if(score_value1!=0) {
            score_1+=score_value1%2;
            score_value1=0;
        }
        if(score_value2!=0)
        {
            score_2+=score_value2%2;
            score_value2=0;
        }
        g_text[1].Loadtext(std::to_string(score_1),renderer,Font3);
        g_text[2].Loadtext(std::to_string(score_2),renderer,Font3);
        g_button[13].Loadimage_base("Image/background/button/ingame1.png",renderer);

        while(SDL_PollEvent(&events)!=0)
        {
            switch (events.type){
                case SDL_QUIT:
                    return OPTION::EXIT_GAME;

                case SDL_MOUSEMOTION:{
                    mouse_X=events.motion.x;
                    mouse_Y=events.motion.y;

                    SDL_Rect temp=g_button[13].get_rect_();

                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_button[13].Loadimage_base("Image/background/button/ingame2.png",renderer);
                    }else{
                        g_button[13].Loadimage_base("Image/background/button/ingame1.png",renderer);
                    }
                    break;}

                case SDL_MOUSEBUTTONDOWN:
                    mouse_X=events.button.x;
                    mouse_Y=events.button.y;

                    SDL_Rect temp=g_button[13].get_rect_();
                    if(Extension::pointed_to(mouse_X,mouse_Y,temp))
                    {
                        g_sound.PlayClick();
                        OPTION current = Pause_game();
                        if(current==REPLAY)     res= OPTION::MULTIPLAYER;
                        else if(current==HOME)  res=OPTION::HOME;
                    }

                    break;

            }
            g_player.fire_action(renderer);
        }

        itemspawn++;
        if(itemspawn>100 && list_item.size()<=3)
        {
            list_item.push_back(spawn_item());
            itemspawn=0;
        }


        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        back_ground.render(renderer);
        game_map.drawmap(renderer);

        load_item(map_data);
        upgrade();

        g_player.draw_bullet(renderer,map_data);
        g_player.Show(renderer);

        g_text[1].render_text(80,647,renderer);
        g_text[2].render_text(782,647,renderer);
        g_button[13].render(renderer);

        SDL_RenderPresent(renderer);

        int frame_tick=SDL_GetTicks64()-staticks;
        if(frame_tick<1000/FPS){
          SDL_Delay(1000/FPS-frame_tick);
        }

        g_player.Update_action(renderer,map_data);
        get_point_multiple();
    }
    return res;
}



void Game::Reset_game()//chỉnh lại type_bullet,xoas ddan
{
    g_score=0;
    score_1=0;
    score_2=0;
    score_value1=0;
    score_value2=0;
    hp= 20;
    g_player.set_type_bullet1(normal);
    g_player.set_type_bullet2(normal);
    list_item.clear();
    list_threat.clear();
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
                break;

            default:
                current_option=OPTION::EXIT_GAME;
                break;
        }

    }while(true);
}




void Game::load_item(const Map& map_data)
{
    int i=0;
    for(item &temp: list_item)
    {
        temp.load_image_item(renderer);
//        if(
//            (map_data.tile[temp.get_rect_().x/TILE_SIZE][temp.get_rect_().y/TILE_SIZE]==1 ||
//            map_data.tile[(temp.get_rect_().x+temp.get_rect_().w)/TILE_SIZE][temp.get_rect_().y/TILE_SIZE]==1 ||
//            map_data.tile[temp.get_rect_().x/TILE_SIZE][(temp.get_rect_().y+temp.get_rect_().h)/TILE_SIZE]==1 ||
//            map_data.tile[(temp.get_rect_().x+temp.get_rect_().w)/TILE_SIZE][(temp.get_rect_().y+temp.get_rect_().h)/TILE_SIZE]==1)
//)
//              list_item.erase(list_item.begin()+i);
        temp.show_item(renderer);
        i++;
    }
}

item Game::spawn_item()
{
    g_sound.PlaySpawn();
    item temp;
    temp.set_distination(game_map.get_datamap());
    temp.set_type();
    return temp;
}
void Game::upgrade()
{
    if (!list_item.empty()) {
        for (auto it = list_item.begin(); it!= list_item.end();) {
            if (detail::check_collision(it->get_rect_(), g_player.get_rect_player1())) {
                g_sound.PlayCollect();
                g_player.set_type_bullet1(it->get_type());
                it = list_item.erase(it);
            } else if (detail::check_collision(it->get_rect_(), g_player.get_rect_player2())) {
                g_player.set_type_bullet2(it->get_type());
                it = list_item.erase(it);
            } else {
                ++it;
            }
        }
    }
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

void Game::delete_threat() {
    std::vector<BulletObject*> list1 = g_player.get_list1_();

    for (size_t i = 0; i < list_threat.size(); ) {
        Threat_object& temp1 = list_threat.at(i);

        for (size_t j = 0; j < list1.size(); ) {
            BulletObject* temp2 = list1.at(j);

            if (detail::check_collision(temp1.get_rect_(), temp2->get_rect_())) {
                g_score++;
                temp2->set_move(false);
                list1.erase(list1.begin() + j);
                list_threat.erase(list_threat.begin() + i);
            } else {
                ++j;
            }
        }

        if (i < list_threat.size()) {
            ++i;
        }
    }
}

void Game::down_hp()
{
    for(int i=0;i<list_threat.size();i++)
    {
        Threat_object temp= list_threat.at(i);
        if(detail::check_insize(temp.get_rect_(),g_player.get_rect_player1()))
        {
            hp-=2;
            list_threat.erase(list_threat.begin()+i);
            //delete temp;
            //temp=NULL;
        }
    }
}

void Game::get_point_multiple()
{
    std::vector<BulletObject*> list1 = g_player.get_list1_();
    std::vector<BulletObject*> list2 = g_player.get_list2_();

    for (size_t j = 0; j < list1.size(); ) {
        BulletObject* temp1 = list1.at(j);

        if (detail::check_collision(temp1->get_rect_(), g_player.get_rect_player1())
            && temp1->getDistanceFromSpawnPoint()>MIN_DISTANCE_FROM_SPAWN_POINT) {
            g_sound.PlayT_dead();
            score_value2++;
            temp1->set_move(false);
            list1.erase(list1.begin() + j);
        } else if (detail::check_collision(temp1->get_rect_(), g_player.get_rect_player2())
                   && temp1->getDistanceFromSpawnPoint()>MIN_DISTANCE_FROM_SPAWN_POINT) {
            g_sound.PlayT_dead();
            score_value1++;
            temp1->set_move(false);
            list1.erase(list1.begin() + j);
        }else j++;
    }
    for (size_t i = 0; i < list2.size(); ) {
        BulletObject* temp2 = list2.at(i);

        if (detail::check_collision(temp2->get_rect_(), g_player.get_rect_player1())
            && temp2->getDistanceFromSpawnPoint()>MIN_DISTANCE_FROM_SPAWN_POINT) {
            g_sound.PlayT_dead();
            score_value2++;
            temp2->set_move(false);
            list2.erase(list2.begin() + i);
        } else if (detail::check_collision(temp2->get_rect_(), g_player.get_rect_player2())
                   && temp2->getDistanceFromSpawnPoint()>MIN_DISTANCE_FROM_SPAWN_POINT) {
            g_sound.PlayT_dead();
            score_value1++;
            temp2->set_move(false);
            list2.erase(list2.begin() + i);
        }else i++;
    }
}
