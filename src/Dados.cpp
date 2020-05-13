#include "Dados.h"

Dados::Dados(Graph<Local> grafo, vector<Condutor *> condutores, vector<Pessoa *> pessoas, vector<Automovel *> carros) {
    this->grafo=grafo;
    this->condutores=condutores;
    this->pessoas=pessoas;
    this->carros=carros;
}

Graph<Local> Dados::getGrafo() {
    return grafo;
}

vector<Condutor *> Dados::getCondutores() {
    return condutores;
}

vector<Pessoa *> Dados::getPessoas() {
    return pessoas;
}

vector<Automovel *> Dados::getAutomoveis() {
    return carros;
}

void Dados::setGrafo(Graph<Local> grafo) {
    this->grafo = grafo;
}

void Dados::setCondutores(vector<Condutor *> condutores) {
    this->condutores=condutores;
}

void Dados::setPessoas(vector<Pessoa *> pessoas) {
    this->pessoas=pessoas;
}

void Dados::setAutomoveis(vector<Automovel *> carros) {
    this->carros=carros;
}