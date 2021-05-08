#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class Graphics;

class BaseObject
{
    public:
        virtual void update(float dt){}
        virtual void draw(Graphics &g){}
};

#endif 