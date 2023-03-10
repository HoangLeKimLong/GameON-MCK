#include "Common_Func.hpp"
#include "RenderWindow.hpp"

SDL_Texture* Common_Func::loadTexture(const char* file_path)
{
    SDL_Surface* tmpSurface =IMG_Load(file_path);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(RenderWindow::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}
void Common_Func::draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest)
{

    SDL_RenderCopy(RenderWindow::renderer,tex,&src,&dest);
}
