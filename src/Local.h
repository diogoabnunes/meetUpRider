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

    bool operator==(const Local &rhs) const;

    bool operator!=(const Local &rhs) const;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

private:
    int id;
    int x;
    int y;

};


#endif //MEETUPRIDER_LOCAL_H
