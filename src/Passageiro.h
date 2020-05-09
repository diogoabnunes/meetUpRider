//
// Created by clara on 09/05/2020.
//

#ifndef MEETUPRIDER_PASSAGEIRO_H
#define MEETUPRIDER_PASSAGEIRO_H


#include "Pessoa.h"

class Passageiro : public Pessoa{
public:
    Passageiro(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada);

};


#endif //MEETUPRIDER_PASSAGEIRO_H
