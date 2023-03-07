#ifndef ENITY_
#define ENITY_

#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
class Entity
{
public:
    Entity();
    const  float PLAYER_WIDTH  = 100 + 220 ;
    const  float PLAYER_HEIGHT = 100 + 200;
    float posX,posY,velX,velY;
    const float step=4;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    void handleEvent(SDL_Event& event);
    void move();
    void render(SDL_Texture* tex,SDL_Renderer* renderer);
    void setCurrentFrame(SDL_Rect src);
};
#endif // ENITY_
