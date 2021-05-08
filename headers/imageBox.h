#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include "application.h"
#include "baseComponent.h"
#include "graphics.h"
#include <SDL2/SDL.h>

class ImageBox : public BaseComponent{
    public:
        ImageBox(Application &app):BaseComponent(app){}
        ~ImageBox() {}        
        void update(float dt) override;
        void draw(Graphics &g) override;
        SDL_Texture *texture = NULL;
    private:
};

#endif
