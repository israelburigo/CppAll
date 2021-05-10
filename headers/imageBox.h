#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include "application.h"
#include "baseComponent.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <string>

typedef struct{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
} sBGRA;

typedef union {
    Uint32 value;
    sBGRA argb;   
} uColor;

class ImageBox : public BaseComponent{
    public:
        ImageBox(Application &app):BaseComponent(app){}
        ~ImageBox() {
            SDL_FreeSurface(surface);    
            SDL_DestroyTexture(texture);
        }        
        void update(float dt) override;
        void draw(Graphics &g) override;
        void loadImg(string s);
        void loopPixels(void (*f)(int, int, uColor*));
        string path;
        SDL_Surface *surface = NULL;
        SDL_Texture *texture = NULL;
    private:
};

#endif
