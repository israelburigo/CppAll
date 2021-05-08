#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <string>
using namespace std;

class Graphics;

class BaseObject{
    public:
        std::string tag;
        BaseObject(){}
        ~BaseObject(){}
        virtual void update(float dt){}
        virtual void draw(Graphics &g){}
};

#endif 