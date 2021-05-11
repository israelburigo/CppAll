#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <string>
using namespace std;

class Graphics;

/**
 * \brief Objeto abstrato que será herdado pelos componentes da aplicação
 */
class BaseObject{
    public:
        std::string tag;
        BaseObject(){}
        ~BaseObject(){}
        /**
         * \brief Método que é chamado dentro do loopObjects da aplicação para atualizar dados do componente
         * \param dt delta-time entre cada loop
         */
        virtual void update(float dt){}
        /**
         * \brief Método que é chamado dentro do loopObjects da aplicação para desenhar informações do componente
         * \param g grafico a qual os objetos serão desenhados
         */
        virtual void draw(Graphics &g){}
};

#endif 