#include "../headers/graphics.h"
#include <SDL2/SDL.h>

Graphics::Graphics(int w, int h)
{
    SDL_CreateWindowAndRenderer(w, h, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, "Teste");
}

Graphics::~Graphics()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
