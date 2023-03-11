#ifndef ENITY_
#define ENITY_

#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Map.hpp"
using namespace std;


class Map;

class Entity
{
public:
    Entity();
    const  float PLAYER_WIDTH  = 64 ;
    const  float PLAYER_HEIGHT = 64;
    float posX,posY,velX,velY;
    const float step=4;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    void handleEvent(SDL_Event& event);
    void move();
    void render(SDL_Texture* tex,SDL_Renderer* renderer);
    void change(Map& gamemap,SDL_Event& event);
};
#endif // ENITY_
