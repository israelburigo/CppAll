#ifndef APPLICATION_H
#define APPLICATION_H

#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/baseObject.h"
#include <list>
#include <string>

typedef struct{
    Graphics g;
} sEventArgs;

class Application{
    public:
        std::list<BaseObject*> objects;
        Input *input = NULL;   
        Graphics *graphics;
        Application();
        ~Application();     
        void loop();
        void loopObjects(float dt,  Graphics &g);        
        BaseObject* getByTag(std::string tag);
    private:        
        
};

#endif