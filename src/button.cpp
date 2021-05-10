#include "../headers/button.h"


void Button::update(float dt)
{
    color = {0xA0, 0xA0, 0xA0, 0xFF};
    if(BaseComponent::isHover)
        color = {0xC0, 0xC0, 0xC0, 0xFF};

    BaseComponent::update(dt);
}

void Button::draw(Graphics &g)
{
    BaseComponent::draw(g);
}