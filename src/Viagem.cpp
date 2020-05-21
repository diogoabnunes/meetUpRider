//
// Created by clara on 19/05/2020.
//

#include "Viagem.h"

const vector<Local> & Viagem::getPercurso() const{
return
percurso;
}

void Viagem::setPercurso(const vector<Local> & percurso) {
    Viagem::percurso = percurso;
}

const vector<Pessoa*> & Viagem::getPassageiros() const{
return
passageiros;
}

void Viagem::setPassageiros(const vector<Pessoa*> & passageiros) {
    Viagem::passageiros = passageiros;
}

Viagem::Viagem(const vector<Local> &percurso, const vector<Pessoa*> & passageiros) : percurso(percurso),
                                                                                   passageiros(passageiros) {}
