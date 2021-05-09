#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>

#include "../headers/gui.h"
#include "../headers/application.h"
#include "../headers/button.h"
#include "../headers/utils.h"
#include "../headers/imageBox.h" 

using namespace std;

void createButton(Application &app, int x, int y, int w, int h, std::string s, void (*e)(BaseComponent*));
void createImageBox(Application &app, int x, int y, int w, int h, std::string tag);
void botaoTesteClick(BaseComponent *sender);
void botaoRedClick(BaseComponent *sender);
void botaoBlueClick(BaseComponent *sender);
void botaoGreenClick(BaseComponent *sender);

void createGui(Application &app)
{
    createButton(app, 10, 10, 100, 30, "Load Img" , botaoTesteClick);
    createButton(app, 10, 50, 100, 30, "Red", botaoRedClick);
    createButton(app, 10, 90, 100, 30, "Blue", botaoBlueClick);
    createButton(app, 10, 130, 100, 30, "Green" , botaoGreenClick);

    createImageBox(app, 10, 170, 300, 200, "main");
    createImageBox(app, 400, 10, 300, 200, "red");
    createImageBox(app, 400, 220, 300, 200, "blue");
    createImageBox(app, 400, 440, 300, 200, "green");
}

void createButton(Application &app, int x, int y, int w, int h, std::string s, void (*e)(BaseComponent*))
{
    auto btn = new Button(app);
    btn->bounds = {x, y, w, h};
    btn->text = s;
    btn->onClick = e;
}

void createImageBox(Application &app, int x, int y, int w, int h, std::string tag)
{
    auto img = new ImageBox(app);
    img->bounds = {x, y, w, h};
    img->tag = tag;
}

void botaoTesteClick(BaseComponent *sender)
{
    auto file = openfilename("BitMap Files (*.bmp)\0*.bmp\0");
    auto imgBox = (ImageBox*)sender->app->getByTag("main");

    if(imgBox == NULL)
        return;

    imgBox->loadImg(file.c_str());
}

void botaoRedClick(BaseComponent *sender)
{
    auto imgBox = (ImageBox*)sender->app->getByTag("main");
    auto img = (ImageBox*)sender->app->getByTag("red");

    img->loadImg(imgBox->path);

    int w = img->surface->clip_rect.w;
    int h = img->surface->clip_rect.h;

    if(SDL_MUSTLOCK(img->surface))
        SDL_LockSurface(img->surface);

    // ARGB
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
        {
            auto pixels = (Uint32*)img->surface->pixels;
            auto px = get_pixel_at(pixels, x, y, w);
            set_pixel(img->surface, x, y, px & 0xffff0000);
        }
    if(SDL_MUSTLOCK(img->surface))
        SDL_UnlockSurface(img->surface);

    img->texture = SDL_CreateTextureFromSurface(img->app->graphics->renderer, img->surface);
}

void botaoBlueClick(BaseComponent *sender)
{
    auto imgBox = (ImageBox*)sender->app->getByTag("main");
    auto img = (ImageBox*)sender->app->getByTag("blue");

    img->loadImg(imgBox->path);

    int w = img->surface->clip_rect.w;
    int h = img->surface->clip_rect.h;

    if(SDL_MUSTLOCK(img->surface))
        SDL_LockSurface(img->surface);

    // ARGB
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
        {
            auto pixels = (Uint32*)img->surface->pixels;
            auto px = get_pixel_at(pixels, x, y, w);
            set_pixel(img->surface, x, y, px & 0xff0000ff);
        }
    if(SDL_MUSTLOCK(img->surface))
        SDL_UnlockSurface(img->surface);

    img->texture = SDL_CreateTextureFromSurface(img->app->graphics->renderer, img->surface);
}

void botaoGreenClick(BaseComponent *sender)
{
    auto imgBox = (ImageBox*)sender->app->getByTag("main");
    auto img = (ImageBox*)sender->app->getByTag("green");

    img->loadImg(imgBox->path);

    int w = img->surface->clip_rect.w;
    int h = img->surface->clip_rect.h;

    if(SDL_MUSTLOCK(img->surface))
        SDL_LockSurface(img->surface);

    // ARGB
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
        {
            auto pixels = (Uint32*)img->surface->pixels;
            auto px = get_pixel_at(pixels, x, y, w);
            set_pixel(img->surface, x, y, px & 0xff00ff00);
        }
    if(SDL_MUSTLOCK(img->surface))
        SDL_UnlockSurface(img->surface);

    img->texture = SDL_CreateTextureFromSurface(img->app->graphics->renderer, img->surface);
}