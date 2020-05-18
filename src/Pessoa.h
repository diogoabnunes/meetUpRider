#ifndef MEETUPRIDER_PESSOA_H
#define MEETUPRIDER_PESSOA_H

#include "Time.h"

class Pessoa {
protected:
    int id;
    int origem;
    int destino;
    Time horaPartida;
    Time horaChegada;
    Time pickup;

public:
    Pessoa(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada);

    int getId() const;
    void setId(int id);
    int getOrigem() const;
    void setOrigem(int origem);
    int getDestino() const;
    void setDestino(int destino);
    const Time &getHoraPartida() const;
    void setHoraPartida(const Time &horaPartida);
    const Time &getHoraChegada() const;
    void setHoraChegada(const Time &horaChegada);

    const Time &getPickup() const;

    void setPickup(const Time &pickup);
};

#endif //MEETUPRIDER_PESSOA_H
