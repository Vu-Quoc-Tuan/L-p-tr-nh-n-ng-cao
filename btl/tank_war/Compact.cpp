#include "Compact.h"

//phần Win
void SDLWin::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "%s: %s", msg, error);
    SDL_Quit();
}
SDL_Window* SDLWin::initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
    if (window == nullptr)
            logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());
    if(TTF_Init()==-1)
            logErrorAndExit( "SDL_Font error:", TTF_GetError());
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
            logErrorAndExit( "SDL_Video error:", SDL_GetError());
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            logErrorAndExit( "SDL_Mix error:", Mix_GetError());

    return window;
}
SDL_Renderer* SDLWin::createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //renderer =
             SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr)
             logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetRenderDrawColor(renderer,255,255,255,255);//có thể sửa

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}
void SDLWin::quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


//EXTENSION

//bool Extension::WasShot()
//{
//
//}

//void Extension::upgrade_bullet(item & box, Player & ngchoi)
//{
//    SDL_Rect hop=box.get_rect_();
//    SDL_Rect nguoi1=ngchoi.get_rect_player1();
//    SDL_Rect nguoi2=ngchoi.get_rect_player2();
//
//    if(detail::check_collision(hop,nguoi1))
//    {
//        ngchoi.set_type_bullet1(box.get_type());
//        //xoas hoopj
//    }
//    if(detail::check_collision(hop,nguoi2))
//    {
//        ngchoi.set_type_bullet2(box.get_type());
//        //xoa hoop
//    }
//}


bool Extension::pointed_to(int x_pos, int y_pos, SDL_Rect rect)
{
    return rect.x <= x_pos && x_pos <= rect.x + rect.w
        && rect.y <= y_pos && y_pos <= rect.y + rect.h;
}
