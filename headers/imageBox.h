#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include "application.h"
#include "baseComponent.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <string>

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
        void changePixelMask(Uint32 mask);
        string path;
        SDL_Surface *surface = NULL;
        SDL_Texture *texture = NULL;
    private:
        void set_pixel(int x, int y, Uint32 pixel);
        Uint32 get_pixel_at(Uint32 * pixels, int x, int y, int w);
};

#endif
