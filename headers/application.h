#ifndef APPLICATION_H
#define APPLICATION_H

#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/baseObject.h"
#include <list>
#include <string>

/**
 * \brief Classe principal de aplicação
 */
class Application{
    public:
        std::list<BaseObject*> objects;
        Input *input = NULL;   
        Graphics *graphics;
        Application();
        ~Application();  
        /**
         * \brief Método que é sempre executado enquanto a aplicação estiver rodando
         */   
        void loop();
        /**
         * \brief Método que percorre os componentes d aplicação e chama Update e Draw de cada um deles
         * \param dt delta-time entre cada loop
         * \param g grafico a qual os objetos serão desenhados
         */ 
        void loopObjects(float dt,  Graphics &g); 
        /**
         * \brief Método que busca um componete da aplicação pela tag
         * \param tag tag
         * \return Componente encontrado pela tag, retorna NULL se não encontrar nenhum
         */        
        BaseObject* getByTag(std::string tag);
    private:        
        
};

#endif