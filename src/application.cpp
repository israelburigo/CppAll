#include <SDL2/SDL.h>
#include "../headers/application.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

namespace{
     const int FPS = 60;
     const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Application::Application()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->loop();
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
                        input->keyDownEvent(event);
                case SDL_KEYUP : 
                    if(event.key.repeat == 0)
                        input->keyUpEvent(event);
                default:break;
            }
        }

        const int currentTime = SDL_GetTicks();
        int elapsedTime = currentTime - lastUpdateTime;
        this->update(std::min<int>(elapsedTime, MAX_FRAME_TIME));
        lastUpdateTime = currentTime;
    }
}

void Application::update(float dt)
{

}

void Application::draw(Graphics &graphics)
{
    
}


