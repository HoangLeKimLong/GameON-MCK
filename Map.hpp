#pragma once
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include <bits/stdc++.h>
const static int map_y=20;
const static int map_x=40;
#define BLANK_TILE -1
#define IMMORTAL_TILE 77
#define HARD_BREAKABLE 79
#define EASY_BREAKABLE_TILE 118
#define TILE_SIZE 32
class Map
{
public:


    void loadMap(const char* file_csv);
    void loadTileSet(const char* file_tileset);
    void drawMap();
    int  posTileSet[map_y][map_x];
    SDL_Texture* tilesetTexture;
private:
    std::vector<SDL_Rect> tileset;
    SDL_Rect tileRect;
    SDL_Rect destRect;

};
