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
    Graph<Local> grafoConexo;
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
    void setAutomoveis(vector<Automovel *> carros);

    const Graph<Local> &getGrafoInicial() const;
    void setGrafoInicial(const Graph<Local> &grafoInicial);
    const Graph<Local> &getGrafoConexo() const;
    void setGrafoConexo(const Graph<Local> &grafoConexo);
    const Graph<Local> &getGrafoProcessado() const;
    void setGrafoProcessado(const Graph<Local> &grafoProcessado);

    Pessoa* searchPessoa(int id);
    void addPessoa();

    void graph_to_graphviewer(Graph<Local> &g);
    int visualizeGraph();

    void addPessoatoLocal();

    void processarGrafo();
};


#endif //MEETUPRIDER_DADOS_H
