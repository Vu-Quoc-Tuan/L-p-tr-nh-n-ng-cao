#include "BaseObject.h"

BaseOject::BaseOject()
{
    p_object=NULL;
    rect_.x=0;
    rect_.y=0;
    rect_.w=0;
    rect_.h=0;
}

BaseOject::~BaseOject()
{
    Free();
}

bool BaseOject::Loadimage(std::string path, SDL_Renderer* screen) {
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  if (!loadedSurface) {
    std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, color_r, color_g, color_b));

  SDL_Texture* optimizedTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);


  if (!optimizedTexture) {
    std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }
  rect_.h=loadedSurface->h;
  rect_.w=loadedSurface->w;

  SDL_FreeSurface(loadedSurface);
  p_object=optimizedTexture;
  return p_object!=NULL;
}

void BaseOject::Render(SDL_Renderer*des,const SDL_Rect* clip)
{
    SDL_Rect renderquad={rect_.x,rect_.y,rect_.w,rect_.h};
    SDL_RenderCopy(des,p_object,clip,&renderquad);
}

void BaseOject::Free()
{
    if(p_object!=NULL)
    {
        SDL_DestroyTexture(p_object);
        p_object=NULL;
        rect_.w=0;
        rect_.h=0;
    }
}


