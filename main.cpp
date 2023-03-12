
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
    Entity player;
    player.tex=image;

    player.posX=0;
    player.posY=0;

    Map gamemap;
    gamemap.loadMap("newmaplv1data.csv");
    gamemap.loadTileSet("Level1.png");
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

					//Handle input for player
                    player.handleEvent(event);
        }
       // player.checkCollision(gamemap);
        gamemap.drawMap();
        player.move(gamemap);



        player.render(player.tex,window.renderer);

        frameTime =SDL_GetTicks() - frameStart;


        if(frameDelay  > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        SDL_SetRenderDrawColor(RenderWindow::renderer, 0, 0, 128, 255);
        window.display();
        window.clear();

    }


    window.cleanUp();
    return 0;
}
