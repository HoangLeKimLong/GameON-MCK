
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Map.hpp"

using namespace std;

const  int SCREEN_WIDTH=800;
const int SCREEN_HEIGHT=600;

const int FPS = 60;
const int frameDelay= 1000/ FPS;

Uint32 frameStart;
int frameTime;
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        cout<< "Hey...SDL_INIT has failed!: "<<SDL_GetError() <<endl;
    }
    if( !IMG_Init(IMG_INIT_PNG) )
    {
        cout<< "Hey...IMG_INIT has failed!" << SDL_GetError() <<endl;
    }

    SDL_Event event;


    RenderWindow window("game v1.0",RenderWindow::SCREEN_WIDTH,RenderWindow::SCREEN_HEIGHT);

    SDL_Texture* background = window.loadTexture("resources/bkground.png");
    SDL_Texture* image =window.loadTexture("resources/plane80-PhotoRoom.png");
    Entity plane;
    plane.tex=image;

    plane.posX=100;
    plane.posY=400;

    Map* map;
    map=new Map();
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
        map->drawMap();
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
