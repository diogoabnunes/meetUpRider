#ifndef MEETUPRIDER_CONDUTOR_H
#define MEETUPRIDER_CONDUTOR_H

#include "Pessoa.h"
#include "Automovel.h"

class Condutor: public Pessoa {
private:
    int carro;
    
public:
    Condutor(int id, int origem, int destino, const Time &horaPartida, const Time &horaChegada, int carro);

    int getAutomovel();
    void setAutomovel(int carro);
};


#endif //MEETUPRIDER_CONDUTOR_H
