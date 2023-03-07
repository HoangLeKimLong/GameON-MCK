
#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include  "Common_Func.hpp"
#include "RenderWindow.hpp"
using namespace std;
class TextObject
{
public:
    TextObject();
    ~TextObject();

    enum TextColor
    {
        RedText=0,
        WhiteText=1,
        BlackText=2,
    };
    bool loadFromFile(string path);
    bool loadFromRenderText(TTF_Font* font);
    void free();

    void setColor(Uint8 red,Uint8 green,Uint8 blue);
    void selectColor(int type);

    void RenderText(int xp,int yp,
                    SDL_Rect* clip = NULL,
                    double angle =0.0,
                    SDL_Point* center=NULL,
                    SDL_RendererFlip flip =SDL_FLIP_NONE );
    int getWidth() {return width;}
    int getHeight() {return height;}
    void setText( const string& text){str_val = text;}
    string getText() const {return str_val;}


private:
    string str_val; // ndung cua text
    SDL_Color text_color_;
    SDL_Texture* tex;
    int width;
    int height;

};
#endif // TEXT_OBJECT_H
