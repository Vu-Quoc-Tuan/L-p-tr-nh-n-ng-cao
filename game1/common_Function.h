#ifndef COMMON_FUNCTION_H_INCLUDED
#define COMMON_FUNCTION_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include<string>
#include<windows.h>

//screen
const int SCREEN_HEIGHT = 680;
const int SCREEN_WIDTH = 1280;
const int SCREEN_BPP=32;


const int color_r=116;
const int color_g=116;
const int color_b=116;

static SDL_Window* window=NULL;
static SDL_Renderer* renderer=NULL;
static SDL_Event event;

#define Title_size 64
#define max_map_x 400
#define max_map_y 10

typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};

typedef struct Map
{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    int tile[max_map_x][max_map_y];
    char* file_name;
};

#endif // COMMON_FUNCTION_H_INCLUDED
