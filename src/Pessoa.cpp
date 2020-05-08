//
// Created by clara on 08/05/2020.
//

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

const Time &Pessoa::getHoraPartida() const {
    return horaPartida;
}

void Pessoa::setHoraPartida(const Time &horaPartida) {
    Pessoa::horaPartida = horaPartida;
}

const Time &Pessoa::getHoraChegada() const {
    return horaChegada;
}

void Pessoa::setHoraChegada(const Time &horaChegada) {
    Pessoa::horaChegada = horaChegada;
}

Pessoa::Pessoa(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada) : id(id),
                                                                                                    origem(origem),
                                                                                                    destino(destino),
                                                                                                    horaPartida(
                                                                                                            horaPartida),
                                                                                                    horaChegada(
                                                                                                            horaChegada) {}
