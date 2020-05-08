//
// Created by clara on 08/05/2020.
//
#pragma once
#ifndef MEETUPRIDER_READFILES_H
#define MEETUPRIDER_READFILES_H



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Pessoa.h"
#include "utils.h"
#include "Condutor.h"
using namespace std;


vector<Pessoa*>readUsers(string filename);


#endif //MEETUPRIDER_READFILES_H
