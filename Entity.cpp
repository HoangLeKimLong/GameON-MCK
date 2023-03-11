
#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "Common_Func.hpp"

Entity::Entity()
{
    posX=0;
    posY=0;

    velX=0;
    velY=0;
}
void Entity::handleEvent(SDL_Event& event)
{
    //ìf a key was pressed
    if(event.type == SDL_KEYDOWN&& event.key.repeat == 0)
    {
        //Adjust the velocity
        switch(event.key.keysym.sym)
        {
        case SDLK_w: velY-=step;
                    tex=Common_Func::loadTexture("res/tankifW-nobk.png");
                    break;
        case SDLK_s: velY+=step;
                    tex=Common_Func::loadTexture("res/tankifS-nobk .png");
                    break;
        case SDLK_a: velX-=step;
                    tex=Common_Func::loadTexture("res/tankifA-nobk.png");
                    break;
        case SDLK_d: velX+=step;
                    tex=Common_Func::loadTexture("res/tankifD-nobk.png");
                    break;
        }

    }
    if( event.type == SDL_KEYUP&& event.key.repeat == 0 )
    {
        //Adjust the velocity
        switch(event.key.keysym.sym)
        {
        case SDLK_w: velY+=step; break;
        case SDLK_s: velY-=step; break;
        case SDLK_a: velX+=step; break;
        case SDLK_d: velX-=step; break;
        }
    }
    //

}
void Entity::move()
{
    //move left or right
    posX+=velX;
    //If the dot went too far to the right or left
    if( ( posX  < 0 - 30 ) || ( posX + PLAYER_WIDTH  + 30  > RenderWindow::SCREEN_WIDTH  ) )
    {
        //Move back
        posX -= velX;
    }
    //move up or down
    posY+=velY;
    //If the dot went too far to the up or down
    if( ( posY < 0 - 30 )  || (posY + PLAYER_HEIGHT  + 15 > RenderWindow::SCREEN_HEIGHT ) )
    {
        //Move back
        posY -= velY;
    }


}
void Entity::render(SDL_Texture* tex,SDL_Renderer* renderer)
{
    SDL_Rect rect;
    SDL_QueryTexture(tex,NULL,NULL,&rect.w,&rect.h);
    rect.x=posX;
    rect.y=posY;
    rect.w=PLAYER_WIDTH*2;

    rect.h=PLAYER_HEIGHT*2;

    SDL_RenderCopy(renderer,tex,NULL,&rect);
}
void Entity::change(Map& gamemap,SDL_Event& event)
{
    if( 1+2 >= 3)
    cout<<gamemap.posTileSet[0][0];
}
