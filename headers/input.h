#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL2/SDL.h>

struct Mouse{
    int x;
    int y;
};

class Input
{
    public:
        Input();
        ~Input();
        void startLoop();
        void keyUpEvent(const SDL_Event& e);
        void keyDownEvent(const SDL_Event& e);
        void mouseUpEvent(const SDL_MouseButtonEvent& e);
        void mouseDownEvent(const  SDL_MouseButtonEvent& e);

        bool wasKeyPressed(SDL_Scancode key);
        bool wasKeyReleased(SDL_Scancode key);
        bool isKeyHeld(SDL_Scancode key);
        bool isMouseDown(Uint8 b);
    private:
        std::map<SDL_Scancode, bool> _heldKeys;
        std::map<SDL_Scancode, bool> _pressedKeys;
        std::map<SDL_Scancode, bool> _releasedKeys;
        std::map<Uint8, bool> _mouseDown;
};

#endif