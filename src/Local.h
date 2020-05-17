//
// Created by clara on 12/05/2020.
//
#pragma once
#ifndef MEETUPRIDER_LOCAL_H
#define MEETUPRIDER_LOCAL_H


#include "Pessoa.h"

class Local {
public:
    Local(int id, int x, int y);

    Local(int id);

    int getId() const;

    void setId(int id);

    bool operator==(const Local &rhs) const;

    bool operator!=(const Local &rhs) const;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    const vector<Pessoa*> & getPartida() const;

    void setPartida(const vector<Pessoa*> & partida);

    const vector<Pessoa*> & getChegada() const;

    void setChegada(const vector<Pessoa*> & chegada);

    double distance( Local dest) ;

private:
    int id;
    int x;
    int y;
    vector<Pessoa*>partida;
    vector<Pessoa*>chegada;
};


#endif //MEETUPRIDER_LOCAL_H
