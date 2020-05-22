//
// Created by clara on 19/05/2020.
//

#ifndef MEETUPRIDER_VIAGEM_H
#define MEETUPRIDER_VIAGEM_H


#include "Local.h"

class Viagem {
public:
    Viagem(const vector<Local> &percurso, const vector<Pessoa*> & passageiros);
    Viagem();

    const vector<Local> & getPercurso() const;

    void setPercurso(const vector<Local> & percurso);

    const vector<Pessoa*> & getPassageiros() const;

    void setPassageiros(const vector<Pessoa*> & passageiros);

private:
    vector<Local> percurso;
    vector<Pessoa*>passageiros;

};


#endif //MEETUPRIDER_VIAGEM_H
