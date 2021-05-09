#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_pixels.h>
#include <cmath>

#include "../headers/gui.h"
#include "../headers/application.h"
#include "../headers/button.h"
#include "../headers/utils.h"
#include "../headers/imageBox.h" 
#include "../headers/cimg.h"

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

    CImg<short> img1; 
    img1.
  
}

void botaoBlueClick(BaseComponent *sender)
{
    auto imgBox = (ImageBox*)sender->app->getByTag("main");
    auto img = (ImageBox*)sender->app->getByTag("blue");

    img->loadImg(imgBox->path);

    SDL_SetTextureColorMod(img->texture, 0, 0, 255);

}

void botaoGreenClick(BaseComponent *sender)
{
    auto imgBox = (ImageBox*)sender->app->getByTag("main");
    auto img = (ImageBox*)sender->app->getByTag("green");

    img->loadImg(imgBox->path);

    SDL_SetTextureColorMod(img->texture, 0, 255, 0);
}