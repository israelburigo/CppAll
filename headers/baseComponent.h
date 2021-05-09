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

class BaseComponent : public BaseObject{
    public:
        BaseComponent(Application &app);
        ~BaseComponent();
        virtual void update(float dt);
        virtual void draw(Graphics &g);
        SDL_Rect bounds;
        std::string text;                 
        SDL_Color color;
        struct sMouse mouse;
        void (*onClick)(BaseComponent*) = NULL;
        Application *app;
    private:       
        bool contains(struct sMouse m);
    protected:        
        bool mouseDown;
        bool isHover;
};

#endif