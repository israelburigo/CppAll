#include"../headers/baseComponent.h"
#include <SDL2/SDL.h>

BaseComponent::BaseComponent(Application &app)
{
//    this->_app = &app;
}

BaseComponent::~BaseComponent()
{

}

void BaseComponent::update(float dt)
{

}

void BaseComponent::draw(Graphics &g){
    // if(&bounds == NULL)
    //     return;

    // SDL_SetRenderDrawColor(g.renderer, color.r, color.g, color.b, color.a);
    // SDL_RenderFillRect(g.renderer, &bounds);
}
