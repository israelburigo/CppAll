#include <SDL2/SDL.h>
#include "../headers/imageBox.h"
#include <SDL2/SDL_image.h>

void ImageBox::update(float dt)
{
    BaseComponent::update(dt);
}

void ImageBox::draw(Graphics &g)
{
    //BaseComponent::draw(g);
    if(texture == NULL)
        return;
    SDL_RenderCopy(g.renderer, texture, NULL, &bounds);
}

void ImageBox::loadImg(string s)
{    
    surface = IMG_Load(s.c_str());
    if (surface) 
    {
        path = s;
        texture = SDL_CreateTextureFromSurface(app->graphics->renderer, surface);
    }
}