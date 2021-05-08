#include "../headers/input.h"

Input::Input(){

}

Input::~Input(){

}

void Input::startLoop(){
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

void Input::keyUpEvent(const SDL_Event& e){
    this->_releasedKeys[e.key.keysym.scancode] = true;
    this->_heldKeys[e.key.keysym.scancode] = false;
}

void Input::keyDownEvent(const SDL_Event& e){
    this->_pressedKeys[e.key.keysym.scancode] = true;
    this->_heldKeys[e.key.keysym.scancode] = true;
}

bool Input::wasKeyPressed(SDL_Scancode key){
    return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key){
    return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key){
    return this->_heldKeys[key];
}

void Input::mouseUpEvent(const SDL_MouseButtonEvent& e){
    this->_mouseDown[e.button] = false;
}
void Input::mouseDownEvent(const  SDL_MouseButtonEvent& e){
    this->_mouseDown[e.button] = true;
}

bool Input::isMouseDown(Uint8 m){
    return this->_mouseDown[m];
}