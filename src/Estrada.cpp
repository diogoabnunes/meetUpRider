//
// Created by clara on 16/05/2020.
//

#include "Estrada.h"

Estrada::Estrada(int distancia, const Time &tempo) : distancia(distancia), tempo(tempo) {}

int Estrada::getDistancia() const {
    return distancia;
}

void Estrada::setDistancia(int distancia) {
    Estrada::distancia = distancia;
}

const Time &Estrada::getTempo() const {
    return tempo;
}

void Estrada::setTempo(const Time &tempo) {
    Estrada::tempo = tempo;
}
