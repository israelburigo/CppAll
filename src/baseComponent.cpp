#include"../headers/baseComponent.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_TTF.h>

#include <iostream>
using namespace std;

BaseComponent::BaseComponent(Application &app)
{
    this->_app = &app;
    _mouseDown = false;
    _isHover = false;
    this->_app->objects.push_back(this);
}

BaseComponent::~BaseComponent()
{


}

bool BaseComponent::contains(struct sMouse m)
{
    return m.x >= bounds.x && m.x <= (bounds.x + bounds.w) 
        && m.y >= bounds.y && m.y <= (bounds.y + bounds.h);
}

void BaseComponent::update(float dt)
{
    auto btnState = SDL_GetMouseState(&mouse.x, &mouse.y);

    _isHover = contains(mouse);

    auto mDown = this->_app->input->isMouseDown(btnState);

    if(_isHover && !mDown && _mouseDown)
    {
        _mouseDown = false;
        if(onClick != NULL)
            onClick(this);
    }

    if(_isHover && mDown)
        _mouseDown = true;
}

void BaseComponent::draw(Graphics &g){
    if(&bounds == NULL)
        return;   

    SDL_SetRenderDrawColor(g.renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(g.renderer, &bounds);

    TTF_Font* font = TTF_OpenFont("ARIAL.TTF", size);
    SDL_Color foregroundColor = { 0, 0, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Shaded(font, text, foregroundColor, NULL, color);
    SDL_BlitSurface(textSurface, NULL, , &bounds);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}
