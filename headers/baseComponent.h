#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <SDL2/SDL.h>
#include "baseObject.h"
#include "graphics.h"
#include "application.h"


struct sColour{
    unsigned char r, g, b, a;
};

struct sMouse{
    int x, y;
};

class BaseComponent : BaseObject
{
    public:
        BaseComponent(Application &app);
        ~BaseComponent();
        void update(float dt) override;
        void draw(Graphics &g) override;
        SDL_Rect bounds;
        struct sColour color;
        struct sMouse mouse;
    private:
        Application *_app;
};

#endif