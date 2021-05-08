#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../headers/gui.h"
#include "../headers/application.h"
#include "../headers/button.h"
#include "../headers/utils.h"
#include "../headers/imageBox.h" 

void botaoTesteClick(BaseComponent *sender)
{
    auto file = openfilename("BitMap Files (*.bmp)\0*.bmp\0");

    auto imgBox = (ImageBox*)sender->app->getByTag("main");

    if(imgBox == NULL)
        return;
    
    SDL_Surface *surface = IMG_Load(file.c_str());
    if (surface) 
    {
        imgBox->texture = SDL_CreateTextureFromSurface(imgBox->app->graphics->renderer, surface);
        SDL_FreeSurface(surface);
    }
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
    img->bounds = {x,y,w,h};
    img->tag = tag;
}

void createGui(Application &app)
{
    createButton(app, 10, 10, 100, 30, "Load Img" , botaoTesteClick);
    createButton(app, 10, 50, 100, 30, "Red", NULL);
    createButton(app, 10, 90, 100, 30, "Blue", NULL);
    createButton(app, 10, 130, 100, 30, "Green" , NULL);
    createImageBox(app, 10, 170, 200, 200, "main");
}

