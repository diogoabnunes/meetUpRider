#ifndef MEETUPRIDER_LOCAL_H
#define MEETUPRIDER_LOCAL_H

#include "Pessoa.h"

class Local {
private:
    long int id;
    double x;
    double y;
    vector<Pessoa*> partida;
    vector<Pessoa*> chegada;
    
public:
    Local(int id, int x, int y);
    Local(int id);

    int getId() const;
    void setId(int id);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
  
    double distance(Local dest);



    bool operator==(const Local &rhs) const ;

    bool operator!=(const Local &rhs)const ;

    void setId1(long id);

    const vector<Pessoa*> & getPartida() const;

    void setPartida(const vector<Pessoa *>& partida);

    const vector<Pessoa*> & getChegada() const;

    void setChegada(const vector<Pessoa*> & chegada);
};

#endif //MEETUPRIDER_LOCAL_H
