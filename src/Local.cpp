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