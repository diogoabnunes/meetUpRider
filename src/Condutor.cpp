#include "Condutor.h"

Condutor::Condutor(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada, int carro)
        : Pessoa(id, origem, destino, horaPartida, horaChegada), carro(carro) {}

int Condutor::getAutomovel() {
    return carro;
}

void Condutor::setAutomovel(int carro) {
    this->carro = carro;
}
