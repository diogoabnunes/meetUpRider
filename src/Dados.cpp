#include "Dados.h"

Dados::Dados() {
    Graph<Local> graph;
    initGraph(graph);
    vector<Condutor*> r;
    vector<Pessoa*> v=readUsers("../resources/users.txt",r);
    vector<Automovel *> c=readCarros("../resources/cars.txt");

    this->grafoInicial=graph;
    this->condutores=r;
    this->pessoas=v;
    this->carros=c;
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


void Dados::setCondutores(vector<Condutor *> condutores) {
    this->condutores=condutores;
}

void Dados::setPessoas(vector<Pessoa *> pessoas) {
    this->pessoas=pessoas;
}

void Dados::setAutomoveis(vector<Automovel *> carros) {
    this->carros=carros;
}

const Graph<Local> &Dados::getGrafoInicial() const {
    return grafoInicial;
}

void Dados::setGrafoInicial(const Graph<Local> &grafoInicial) {
    Dados::grafoInicial = grafoInicial;
}

const Graph<Local> &Dados::getGrofoConexo() const {
    return grofoConexo;
}

void Dados::setGrofoConexo(const Graph<Local> &grofoConexo) {
    Dados::grofoConexo = grofoConexo;
}

const Graph<Local> &Dados::getGrafoProcessado() const {
    return grafoProcessado;
}

void Dados::setGrafoProcessado(const Graph<Local> &grafoProcessado) {
    Dados::grafoProcessado = grafoProcessado;
}
