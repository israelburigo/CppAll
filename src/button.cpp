#include "../headers/button.h"


void Button::update(float dt)
{
    BaseComponent::update(dt);

    color = {0xA0, 0xA0, 0xA0, 0xFF};
    if(BaseComponent::isHover)
        color = {0xC0, 0xC0, 0xC0, 0xFF};
}

void Button::draw(Graphics &g)
{
    BaseComponent::draw(g);
}