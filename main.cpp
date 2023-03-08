
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Map.hpp"

using namespace std;



const int FPS = 60;
const int frameDelay= 1000/ FPS;

Uint32 frameStart;
int frameTime;
int main(int argc,char* argv[])
{

    SDL_Event event;


    RenderWindow window("game v1.0",RenderWindow::SCREEN_WIDTH,RenderWindow::SCREEN_HEIGHT);

    SDL_Texture* background = window.loadTexture("resources/tank.jpg");
    SDL_Texture* image =window.loadTexture("res/tankifD-nobk.png");
    Entity plane;
    plane.tex=image;

    plane.posX=0;
    plane.posY=0;

    Map gamemap;
    gamemap.loadMap("data.csv");
    gamemap.loadTileSet("tileset.png");
    bool gameRunning=true;
    while(gameRunning)
    {

        frameStart=SDL_GetTicks();

        SDL_RenderClear(window.renderer);

        while( SDL_PollEvent( &event ) != 0 )
        {

        //User requests quit
					if( event.type == SDL_QUIT )
					{
						gameRunning=false;
					}

					//Handle input for the dot
					plane.handleEvent(event);
        }

        gamemap.drawMap();
        plane.move();



        plane.render(plane.tex,window.renderer);

        frameTime =SDL_GetTicks() - frameStart;


        if(frameDelay  > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        window.display();
        window.clear();

    }


    window.cleanUp();
    return 0;
}
