//
// Created by clara on 12/05/2020.
//

#ifndef MEETUPRIDER_LOCAL_H
#define MEETUPRIDER_LOCAL_H


class Local {
public:
    Local(int id, int x, int y);

    Local(int id);

    int getId() const;

    void setId(int id);

private:
    int id;
    int x;
    int y;

};


#endif //MEETUPRIDER_LOCAL_H
