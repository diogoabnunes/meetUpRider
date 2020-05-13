#ifndef MEETUPRIDER_DADOS_H
#define MEETUPRIDER_DADOS_H

#include "Condutor.h"
#include "Pessoa.h"
#include "Automovel.h"
#include "Graph.h"
#include "Local.h"
#include "ReadFiles.h"

#include <vector>

using namespace std;

class Dados {
    Graph<Local> grafo;
    vector<Condutor*> condutores;
    vector<Pessoa*> pessoas;
    vector<Automovel*> carros;

public:
    Dados(Graph<Local> grafo,vector<Condutor*> condutores ,vector<Pessoa*> pessoas, vector<Automovel *> carros);

    vector<Condutor*> getCondutores();
    vector<Pessoa*> getPessoas();
    Graph<Local> getGrafo();
    vector<Automovel *> getAutomoveis();

    void setCondutores(vector<Condutor *> condutores);
    void setPessoas(vector<Pessoa *> pessoas);
    void setGrafo(Graph<Local> grafo);
    void setAutomoveis(vector<Automovel *> carros);
};


#endif //MEETUPRIDER_DADOS_H
