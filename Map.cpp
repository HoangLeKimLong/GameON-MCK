#include "Map.hpp"
#include "Common_Func.hpp"
#include "RenderWindow.hpp"
#include <bits/stdc++.h>
using namespace std;
void Map::loadMap(const char* file_csv)
{
    std::ifstream file(file_csv);
	for (int i = 0; i < 20; i++) {
		std::string s;
		file >> s;
		std::stringstream ss(s);
		std::string c;
		int j = 0;
		while (getline(ss, c, ',')) {
			int x = stoi(c);
			posTileSet[i][j] = x;
			j++;
		}
	}


}
void Map::loadTileSet(const char* file_tileset)
{
    SDL_Surface* tilesetSurface = IMG_Load(file_tileset);
    tilesetTexture = SDL_CreateTextureFromSurface(RenderWindow::renderer, tilesetSurface);


    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            tileRect = { j * 32, i * 32, 32, 32 };
            tileset.push_back(tileRect);
        }
    }
}
void Map::drawMap()
{
    destRect.x=0;
    destRect.y=0;
    destRect.w=32;
    destRect.h=32;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            tileRect = tileset[posTileSet[i][j]];
            SDL_RenderCopy(RenderWindow::renderer, tilesetTexture, &tileRect, &destRect);
            destRect.x += 32;
        }
    destRect.y += 32;
    destRect.x = 0;
    }
}
