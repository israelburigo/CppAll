#ifndef APPLICATION_H
#define APPLICATION_H

class Input;
class Graphics;
class BaseObject;

#include <list>

class Application{
    public:
        Application();
        ~Application();     
        void loop();
        void loopObjects(float dt, Graphics &g);
    protected:
        Input *_input;        
    private:        
        std::list<BaseObject*> _objects;
};

#endif