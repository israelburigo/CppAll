#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <SDL2/SDL.h>
#include "baseObject.h"
#include "graphics.h"
#include "application.h"
#include <string>

/**
 * \brief estrutura contento coordenadas x e y
 */
struct sMouse{
    int x, y;
};

/**
 * \brief Classe de componentes da aplicação
 */
class BaseComponent : public BaseObject{
    public:
        BaseComponent(Application &app);
        ~BaseComponent();
        virtual void update(float dt);
        virtual void draw(Graphics &g);
        SDL_Rect bounds;
        std::string text;                 
        SDL_Color color;
        struct sMouse mouse;
        /**
         * \brief Evento onClick do componente
         * \param sender componente que chamou o evento
         */
        void (*onClick)(BaseComponent*) = NULL;
        Application *app;
    private:  
        /**
         * \brief método que verifica se uma coordenada x,y está inserida dentro dos limites do componente
         * \param m coordenadas x,y
         * \return retorna True se estiver dentro e False se não
         */    
        bool contains(struct sMouse m);
    protected:        
        bool mouseDown;
        bool isHover;
};

#endif