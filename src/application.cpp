#include <SDL2/SDL.h>
#include "../headers/application.h"
#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/baseObject.h"

#include <list>

namespace{
     const int FPS = 60;
     const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Application::Application()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->loop();
    this->_objects = std::list<BaseObject*>();
}

Application::~Application()
{
    SDL_Quit();
}

void Application::loop()
{    
    SDL_Event event;
    this->_input = new Input();

    auto g = new Graphics(600, 600);

    auto lastUpdateTime = SDL_GetTicks();

    while(true)
    {
        this->_input->startLoop();

        if(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT : return;            
                case SDL_KEYDOWN : 
                    if(event.key.repeat == 0)
                        this->_input->keyDownEvent(event);
                case SDL_KEYUP : 
                    if(event.key.repeat == 0)
                        this->_input->keyUpEvent(event);
                default:break;
            }
        }

        const int currentTime = SDL_GetTicks();
        int elapsedTime = currentTime - lastUpdateTime;
        this->loopObjects(std::min<int>(elapsedTime, MAX_FRAME_TIME), *g);
        lastUpdateTime = currentTime;
        
    }
}

void Application::loopObjects(float dt, Graphics &g)
{
    for(auto const& i : this->_objects)    
    {
        i->update(dt);
        SDL_RenderClear(g.renderer);
        i->draw(g);
        SDL_RenderPresent(g.renderer);
    }
}



