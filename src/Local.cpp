//
// Created by clara on 12/05/2020.
//

#include "Local.h"

int Local::getId() const {
    return id;
}

void Local::setId(int id) {
    Local::id = id;
}

Local::Local(int id, int x, int y) : id(id), x(x), y(y) {}

Local::Local(int id) : id(id) {}

bool Local::operator==(const Local &rhs) const {
    return id == rhs.id;
}

bool Local::operator!=(const Local &rhs) const {
    return !(rhs == *this);
}

int Local::getX() const {
    return x;
}

void Local::setX(int x) {
    Local::x = x;
}

int Local::getY() const {
    return y;
}

void Local::setY(int y) {
    Local::y = y;
}

const vector<Pessoa*> & Local::getPartida() const{
return
partida;
}

void Local::setPartida(const vector<Pessoa*> & partida) {
    Local::partida = partida;
}

const vector<Pessoa*> & Local::getChegada() const{
return
chegada;
}

void Local::setChegada(const vector<Pessoa*> & chegada) {
    Local::chegada = chegada;
}

double Local::distance(Local dest) {

    double dist=sqrt(pow(getX()-dest.getX(),2)+pow(getY()-dest.getY(),2));
    //cout<<dist<<endl;
    return dist;

}
