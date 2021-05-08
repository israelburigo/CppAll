#include <SDL2/SDL.h>
#include "../headers/imageBox.h"

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