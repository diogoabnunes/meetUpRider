//
// Created by clara on 08/05/2020.
//
#pragma once
#ifndef MEETUPRIDER_READFILES_H
#define MEETUPRIDER_READFILES_H

#define numPeople 200

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Pessoa.h"
#include "utils.h"
#include "Condutor.h"
#include "graphviewer.h"
#include "Graph.h"
#include "Local.h"
#include "Dados.h"
#include <time.h>
using namespace std;


void initGraph(Graph<Local> &g, string nodesfile, string edgesfile, bool real);

vector <Pessoa*> readUsers(string filename, vector<Condutor*> &cond);
vector <Automovel> readCarros(string filename);

void parse_nodes(Graph<Local> *g, string file, bool real);
void parse_edges(Graph<Local> *g, string file);

void generatePeople(Graph<Local> *graph);


#endif //MEETUPRIDER_READFILES_H
