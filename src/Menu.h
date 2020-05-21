#ifndef MEETUPRIDER_MENU_H
#define MEETUPRIDER_MENU_H

#include "../lib/graphviewer.h"
#include "Dados.h"

class Menu {
public:
    Menu();
    void showMenu(Dados &dados);
    int chooseMap(Dados &dados);
};


#endif //MEETUPRIDER_MENU_H
