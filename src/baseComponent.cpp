#include"../headers/baseComponent.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
using namespace std;

BaseComponent::BaseComponent(Application &app)
{
    this->app = &app;
    mouseDown = false;
    isHover = false;
    this->app->objects.push_back(this);
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

    isHover = contains(mouse);

    auto mDown = this->app->input->isMouseDown(btnState);

    if(isHover && !mDown && mouseDown)
    {
        mouseDown = false;
        if(onClick != NULL)
            onClick(this);
    }

    if(isHover && mDown)
        mouseDown = true;
}

void BaseComponent::draw(Graphics &g){
    if(&bounds == NULL)
        return;   

    SDL_SetRenderDrawColor(g.renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(g.renderer, &bounds);

    auto font = TTF_OpenFont("C:/Windows/fonts/arial.ttf", 12); 
    auto a = TTF_GetError();

    SDL_Color fore = {0, 0, 0, 0xff}; 
    auto surfaceMessage = TTF_RenderUTF8_Blended(font, text.c_str(), fore);
    auto message = SDL_CreateTextureFromSurface(g.renderer, surfaceMessage);  

    SDL_Rect dest = {
        bounds.x + bounds.w/2 - surfaceMessage->clip_rect.w/2, 
        bounds.y + bounds.h/2 - surfaceMessage->clip_rect.h/2,
        surfaceMessage->clip_rect.w,
        surfaceMessage->clip_rect.h
    };

    SDL_RenderCopy(g.renderer, message, NULL, &dest);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
    TTF_CloseFont(font);
}
