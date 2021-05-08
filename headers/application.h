#ifndef APPLICATION_H
#define APPLICATION_H

#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/baseObject.h"
#include <list>

class Application{
    public:
        Application();
        ~Application();     
        void loop();
        void loopObjects(float dt, Graphics &g);
        std::list<BaseObject*> objects;
        Input *input;    
    private:        
        
};

#endif