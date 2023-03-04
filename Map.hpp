#pragma once
#include "RenderWindow.hpp"
class Map
{
public:
    Map();
    ~Map();
    const int map_rows=20;
    const int map_cols=25;
    void loadMap(int arr[20][25]);
    void drawMap();
    void drawMapbyFile(const char* file_path);
private:
    SDL_Rect src,dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};
