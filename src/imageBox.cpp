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

void ImageBox::changePixelMask(Uint32 mask)
{
    if(surface == nullptr)
        return;

    int w = surface->clip_rect.w;
    int h = surface->clip_rect.h;

    if(SDL_MUSTLOCK(surface))
        SDL_LockSurface(surface);

    // ARGB
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
        {
            auto pixels = (Uint32*)surface->pixels;
            auto px = get_pixel_at(pixels, x, y, w);
            set_pixel(x, y, px & mask);
        }
    if(SDL_MUSTLOCK(surface))
        SDL_UnlockSurface(surface);

    texture = SDL_CreateTextureFromSurface(app->graphics->renderer, surface);
}

Uint32 ImageBox::get_pixel_at(Uint32 * pixels, int x, int y, int w)
{
    return pixels[y * w + x];
}

void ImageBox::set_pixel(int x, int y, Uint32 pixel)
{
  Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);
  *target_pixel = pixel;
}