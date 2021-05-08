#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../headers/application.h"
#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/baseObject.h"
#include "../headers/button.h"
#include "../headers/gui.h"

#include <list>

namespace{
     const int FPS = 60;
     const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Application::Application()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    this->objects = std::list<BaseObject*>();
    this->loop();    
}

Application::~Application()
{
    for(auto const& i : this->objects) 
        delete i;
    SDL_Quit();
}

void Application::loop()
{    
    SDL_Event event;
    this->input = new Input();

    this->graphics = new Graphics(600, 600);

    auto lastUpdateTime = SDL_GetTicks();

    createGui(*this);

    while(true)
    {
        this->input->startLoop();

        if(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT : return;            
                case SDL_KEYDOWN : 
                    if(event.key.repeat == 0)
                        this->input->keyDownEvent(event); 
                break;
                case SDL_KEYUP : 
                    if(event.key.repeat == 0)
                        this->input->keyUpEvent(event); 
                break;                
                case SDL_MOUSEBUTTONDOWN:
                    this->input->mouseDownEvent(event.button); 
                break;
                case SDL_MOUSEBUTTONUP:
                    this->input->mouseUpEvent(event.button); 
                break;
                default:break;
            }
        }

        const int currentTime = SDL_GetTicks();
        int elapsedTime = currentTime - lastUpdateTime;
        this->loopObjects(std::min<int>(elapsedTime, MAX_FRAME_TIME), *this->graphics);
        lastUpdateTime = currentTime;
        
    }
}

void Application::loopObjects(float dt, Graphics &g)
{
    SDL_SetRenderDrawColor(g.renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(g.renderer);
    for(auto const& i : this->objects)    
    {
        i->update(dt);
        i->draw(g);
    }
    SDL_RenderPresent(g.renderer);
}

BaseObject* Application::getByTag(std::string tag)
{
    for(auto const& i : this->objects)
        if(i->tag == tag)
            return i;
    return NULL;
}




