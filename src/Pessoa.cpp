#include "Pessoa.h"

int Pessoa::getId() const {
    return id;
}

void Pessoa::setId(int id) {
    Pessoa::id = id;
}

int Pessoa::getOrigem() const {
    return origem;
}

void Pessoa::setOrigem(int origem) {
    Pessoa::origem = origem;
}

int Pessoa::getDestino() const {
    return destino;
}

void Pessoa::setDestino(int destino) {
    Pessoa::destino = destino;
}


Pessoa::Pessoa(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada) :
        id(id), origem(origem), destino(destino), horaMinPartida(horaPartida), horaMaxChegada(horaChegada) {}

const Time &Pessoa::getPickup() const {
    return pickup;
}

void Pessoa::setPickup(const Time &pickup) {
    Pessoa::pickup = pickup;
}

const Time &Pessoa::getHoraMinPartida() const {
    return horaMinPartida;
}

void Pessoa::setHoraMinPartida(const Time &horaMinPartida) {
    Pessoa::horaMinPartida = horaMinPartida;
}

const Time &Pessoa::getHoraMaxChegada() const {
    return horaMaxChegada;
}

void Pessoa::setHoraMaxChegada(const Time &horaMaxChegada) {
    Pessoa::horaMaxChegada = horaMaxChegada;
}

