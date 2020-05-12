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

Local::Local(int id) : id(id) {}
