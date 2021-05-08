#ifndef BUTTON_H
#define BUTTON_H

#include "application.h"
#include "baseComponent.h"
#include "graphics.h"

class Button : public BaseComponent{
    public:
        Button(Application &app):BaseComponent(app){
            color = {0xA0, 0xA0, 0xA0, 0xFF};
        }
        ~Button() {

        }
        
        void update(float dt) override;
        void draw(Graphics &g) override;
    private:
};

#endif