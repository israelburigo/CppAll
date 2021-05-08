#include "../headers/gui.h"
#include "../headers/application.h"
#include <string>
#include "../headers/button.h"

void botaoTesteClick(BaseComponent *sender)
{

}

 void createButton(Application &app, int x, int y, int w, int h, std::string s, void (*e)(BaseComponent*))
{
    auto btn = new Button(app);
    btn->bounds = {x, y, w, h};
    btn->text = s;
    btn->onClick = e;
}

void createGui(Application &app)
{
    createButton(app, 10, 10, 100, 30, "Load Img" , botaoTesteClick);
}

