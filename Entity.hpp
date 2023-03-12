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
    int posX,posY,velX,velY;
    int lastPosX,lastPosY;
    const int step=4;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    void handleEvent(SDL_Event& event);
    void move(Map& gamemap);
    void render(SDL_Texture* tex,SDL_Renderer* renderer);
    bool checkCollision(Map& gamemap);
};
#endif // ENITY_
