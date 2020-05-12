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
#include "graphviewer.h"
#include "Graph.h"
using namespace std;

void initGraph();

vector<Pessoa*>readUsers(string filename);

vector<Automovel> readCarros(string filename);

void parse_nodes(GraphViewer *gv, string file);
void parse_nodes(Graph<Local> *gv, string file);

void parse_edges(GraphViewer *gv, string file);
void parse_edges(Graph<Local> *gv, string file);

#endif //MEETUPRIDER_READFILES_H
