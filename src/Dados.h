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
    Graph<Local> grafoInicial;
    Graph<Local> grofoConexo;
    Graph<Local> grafoProcessado;
    vector<Condutor*> condutores;
    vector<Pessoa*> pessoas;
    vector<Automovel*> carros;

public:
    Dados();

    vector<Condutor*> getCondutores();
    vector<Pessoa*> getPessoas();
    vector<Automovel *> getAutomoveis();

    void setCondutores(vector<Condutor *> condutores);
    void setPessoas(vector<Pessoa *> pessoas);
    void setGrafo(Graph<Local> grafo);
    void setAutomoveis(vector<Automovel *> carros);

    const Graph<Local> &getGrafoInicial() const;

    void setGrafoInicial(const Graph<Local> &grafoInicial);

    const Graph<Local> &getGrofoConexo() const;

    void setGrofoConexo(const Graph<Local> &grofoConexo);

    const Graph<Local> &getGrafoProcessado() const;

    void setGrafoProcessado(const Graph<Local> &grafoProcessado);
};


#endif //MEETUPRIDER_DADOS_H
