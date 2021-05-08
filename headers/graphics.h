#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

class Graphics{
    public:
        Graphics(int w, int h);
        ~Graphics();
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
};

#endif