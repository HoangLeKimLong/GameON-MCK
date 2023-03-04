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
    const  float PLANE_WIDTH  = 110 ;
    const float PLANE_HEIGHT = 60 ;
    float posX,posY,velX,velY;
    const float step=5;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    void handleEvent(SDL_Event& event);
    void move();
    void render(SDL_Texture* tex,SDL_Renderer* renderer);
};
#endif // ENITY_
