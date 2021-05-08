#include "../headers/graphics.h"
#include <SDL2/SDL.h>

Graphics::Graphics(int w, int h)
{
    SDL_CreateWindowAndRenderer(w, h, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Teste");
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
}
