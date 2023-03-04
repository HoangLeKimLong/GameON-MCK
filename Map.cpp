#include "Map.hpp"
#include "Common_Func.hpp"
#include "RenderWindow.hpp"
using namespace std;
int level1[20][25]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}
};

Map::Map()
{

    dirt= Common_Func::loadTexture("resources/mapTexture/dirt.png");
    grass = Common_Func::loadTexture("resources/mapTexture/grass.png");
    water = Common_Func::loadTexture("resources/mapTexture/water.png");
    loadMap(level1);
    src.x = src.y=0;
    src.w= dest.w=32;
    src.h=dest.h=32;

    dest.x=dest.y=0;

}
void Map::loadMap(int arr[20][25])
{

    for(int  row =0;row <20;row++)
    {
        for( int col=0; col <25;col++)
        {
            map[row][col]= arr[row][col];
        }
    }
}
void Map::drawMap()
{
    int type=0;
    for(int  row =0;row <20;row++)
    {
        for( int col=0; col <25;col++)
        {
            type = map[row][col];
            dest.x = col * 32;
            dest.y = row * 32;
            switch(type)
            {
            case 0:
                Common_Func::draw(water,src,dest);
                break;
            case 1:
                Common_Func::draw(grass,src,dest);
                break;
            case 2:
                Common_Func::draw(dirt,src,dest);
                break;
            default:
                break;
            }
        }
    }
}
