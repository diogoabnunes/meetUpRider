#include "Automovel.h"

Automovel::Automovel(unsigned int id ,unsigned int nSeats){
    this->id= id;
    this->nSeats=nSeats;
}

Automovel::Automovel(){
    this->id=-1;
    this->nSeats=-1;
}

unsigned int Automovel::getId(){
    return id;
}

unsigned int Automovel::getNSeats(){
    return nSeats;
}

void Automovel::setId(unsigned int id) {
    this->id=id;
}

void Automovel::setNSeats(unsigned int nSeats) {
    this->nSeats=nSeats;
}