//
// Created by clara on 08/05/2020.
//

#include "Condutor.h"

Condutor::Condutor(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada, int idCarro)
        : Pessoa(id, origem, destino, horaPartida, horaChegada), idCarro(idCarro) {}
