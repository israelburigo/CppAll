#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <SDL2/SDL.h>
#include "baseObject.h"
#include "graphics.h"
#include "application.h"
#include <string>

struct sMouse{
    int x, y;
};

class BaseComponent : BaseObject
{
    public:
        BaseComponent(Application &app);
        ~BaseComponent();
        virtual void update(float dt);
        virtual void draw(Graphics &g);
        SDL_Rect bounds;
        std::string text;        
        SDL_Color color;
        struct sMouse mouse;
        void (*onClick)(BaseComponent*);
    private:
        Application *_app;
        bool contains(struct sMouse m);
        bool _mouseDown;
        bool _isHover;
};

#endif