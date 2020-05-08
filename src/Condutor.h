//
// Created by clara on 08/05/2020.
//

#ifndef MEETUPRIDER_CONDUTOR_H
#define MEETUPRIDER_CONDUTOR_H


#include "Pessoa.h"
#include "Automovel.h"

class Condutor:public  Pessoa {
public:
    Condutor(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada, Automovel carro);

    Automovel getAutomovel();

    void setAutomovel(Automovel carro);

private:
    Automovel carro;
};


#endif //MEETUPRIDER_CONDUTOR_H
