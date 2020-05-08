#ifndef MEETUPRIDER_AUTOMOVEL_H
#define MEETUPRIDER_AUTOMOVEL_H

#include <stdlib.h>

class Automovel {
    unsigned int id;
    unsigned int nSeats;

public:
    Automovel();
    Automovel(unsigned int id,unsigned int nSeats);
    unsigned int getId();
    void setId(unsigned int id);
    unsigned int getNSeats();
    void setNSeats(unsigned int nSeats);
};


#endif //MEETUPRIDER_AUTOMOVEL_H
