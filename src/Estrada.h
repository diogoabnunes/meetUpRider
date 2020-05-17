//
// Created by clara on 16/05/2020.
//

#ifndef MEETUPRIDER_ESTRADA_H
#define MEETUPRIDER_ESTRADA_H


#include "Time.h"

class Estrada {
public:
    Estrada(int distancia, const Time &tempo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Time &getTempo() const;

    void setTempo(const Time &tempo);

private:
    int distancia;
    Time tempo;

};


#endif //MEETUPRIDER_ESTRADA_H
