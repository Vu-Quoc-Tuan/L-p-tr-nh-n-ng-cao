#include "game_map.h"

void GameMap::Loadmap(char *nam)
{
    FILE* fp=NULL;
    fopen_s(&fp,nam,"rb");
    if(fp==NULL)
    {
        return;
    }

    game_map_.max_x=0;
    game_map_.max_y=0;
    for(int i=0;i<max_map_y;i++){
        for(int j=0;j<max_map_x;j++){
            fscanf(fp,"%d",&game_map_.tile[i][j]);
            int val=game_map_.tile[i][j];
            if(val>0){
                if(j>game_map_.max_x){
                    game_map_.max_x=j;
                }
                if(i>game_map_.max_y){
                    game_map_.max_y=i;
                }
            }
        }
    }
    game_map_.max_x=(game_map_.max_x+1)*Title_size;
    game_map_.max_y=(game_map_.max_y+1)*Title_size;

    game_map_.start_x=0;
    game_map_.start_y=0;

    game_map_.file_name=nam;
    fclose(fp);
}

void GameMap::LoadTitle(SDL_Renderer* screen)
{
    char file_img[30];
    FILE* fp=NULL;

    for(int i=0;i<MAX_titles;i++){
        sprintf_s(file_img,"map/%d.png",i);

        fopen_s(&fp,file_img,"rb");
        if(fp==NULL){
            continue;
        }
        fclose(fp);

        title_mat[i].Loadimage(file_img,screen);
    }
}

void GameMap::drawmap(SDL_Renderer* screen){
    int x1=0;
    int x2=0;

    int y1=0;
    int y2=0;

    int map_x=0;
    int map_y=0;

    map_x=game_map_.start_x/Title_size;
    x1=(game_map_.start_x%Title_size)*-1;//in lùi lại 1 lượng
    x2=x1+SCREEN_WIDTH+(x1==0 ? 0:Title_size);//đến quá 1 lượng bằng lượng lùi

    map_y=game_map_.max_y/Title_size;
    y1=(game_map_.start_y%Title_size)*-1;//in lùi lại 1 lượng
    y2=y1+SCREEN_WIDTH+(y1==0 ? 0:Title_size);

    for(int i=y1;i<y2;i+=Title_size){
            map_x=game_map_.start_x/Title_size;
        for(int j=x1;j<x2;j+=Title_size){
            int val=game_map_.tile[map_y][map_x];
            if(val>0)
            {
                title_mat[val].SetRect(j,i);
                title_mat[val].Render(screen);
            }
            map_x++;
        }
        map_y++;
    }
}
