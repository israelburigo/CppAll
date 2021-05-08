#ifndef APPLICATION_H
#define APPLICATION_H

class Input;

class Graphics;

class Application{
    public:
        Application();
        ~Application();     
        void loop();
        void draw(Graphics &graphics);
        void update(float dt);
    private:
        Input _input;

};

#endif