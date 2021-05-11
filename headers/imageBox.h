#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include "application.h"
#include "baseComponent.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <string>

typedef struct{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
} sBGRA;

typedef union {
    Uint32 value;
    sBGRA argb;   
} uColor;

class ImageBox : public BaseComponent{
    public:
        ImageBox(Application &app):BaseComponent(app){}
        ~ImageBox() {
            SDL_FreeSurface(surface);    
            SDL_DestroyTexture(texture);
        }        
        void update(float dt) override;
        void draw(Graphics &g) override;
        /**
         * \brief Método para carregar uma imagem do disco na textura desse componente
         * \param s caminho da imagem no disco
         */
        void loadImg(string s);
        /**
         * \brief Método que percorre cada pixel da imagem carregada no componente
         * \param f função callback iterada de cada pixel
         */
        void loopPixels(void (*f)(int, int, uColor*));
        string path;
        SDL_Surface *surface = NULL;
        SDL_Texture *texture = NULL;
    private:
};

#endif
