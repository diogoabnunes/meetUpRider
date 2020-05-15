#ifndef MEETUPRIDER_MENU_H
#define MEETUPRIDER_MENU_H

#include "../lib/graphviewer.h"
#include "Dados.h"


class Menu {
private:
    Dados dados;
public:
    const Dados &getDados() const;

    void setDados(const Dados &dados);

public:
    Menu(const Dados &dados);

    void showMenu(Dados &dados);
    int visualizeGraph(Dados &dados);
};


#endif //MEETUPRIDER_MENU_H
