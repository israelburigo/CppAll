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

void ImageBox::loopPixels(void (*f)(int, int, uColor*))
{
    if(surface == nullptr)
        return;

    auto w = surface->clip_rect.w;
    auto h = surface->clip_rect.h;

    if(SDL_MUSTLOCK(surface))
        SDL_LockSurface(surface);

    // ARGB
    uColor color;
    for (auto xy = 0; xy < w * h; xy++)
    {
        auto x = (int)(xy % w);
        auto y = (int)(xy / w);

        auto pixels = (Uint32*)surface->pixels;
        color.value = pixels[y * w + x];
        if(f != nullptr)
            f(x, y, &color);
        pixels[y * w + x] = color.value;
    }

    if(SDL_MUSTLOCK(surface))
        SDL_UnlockSurface(surface);

    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(app->graphics->renderer, surface);
}
