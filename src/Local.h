#ifndef MEETUPRIDER_LOCAL_H
#define MEETUPRIDER_LOCAL_H

#include "Pessoa.h"

class Local {
private:
    long int id;
    double x;
    double y;
    vector<Pessoa> partida;
    vector<Pessoa> chegada;
    
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
};

#endif //MEETUPRIDER_LOCAL_H
