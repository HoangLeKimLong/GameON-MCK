
#include "TextObject.hpp"
#include <SDL_ttf.h>
#include "RenderWindow.hpp"
TextObject::TextObject()
{
    text_color_.r=255;
    text_color_.g=255;
    text_color_.b=255;
    tex=NULL;
}
TextObject::~TextObject()
{

}
bool TextObject::loadFromRenderText(TTF_Font* font)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font,str_val.c_str(),text_color_);
    if(text_surface)
    {
        tex =SDL_CreateTextureFromSurface(RenderWindow::renderer,text_surface);
        width=text_surface->w;
        height=text_surface->h;
        SDL_FreeSurface(text_surface);
    }
    return tex!= NULL;

}
