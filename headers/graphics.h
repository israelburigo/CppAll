#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

class Graphics{
    public:
        Graphics(int w, int h);
        ~Graphics();
        SDL_Window *window;
        SDL_Renderer *renderer;
    private:        
};

#endif