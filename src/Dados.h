#ifndef MEETUPRIDER_DADOS_H
#define MEETUPRIDER_DADOS_H

#include "Condutor.h"
#include "Pessoa.h"
#include "Automovel.h"
#include "Graph.h"
#include "Local.h"
#include "ReadFiles.h"
#include "limits.h"

#include <vector>

using namespace std;

class Dados {
    Graph<Local> grafoInicial;
    Graph<Local> grafoConexo;
    Graph<Local> grafoProcessado;
    vector<Condutor*> condutores;
    vector<Pessoa*> pessoas;
    vector<Automovel> carros;
    vector<Vertex<Local>*> pdi;
    bool real;
    int maxx, minx, maxy, miny;
public:
    int getMaxx() const;

    void setMaxx(int maxx);

    int getMinx() const;

    void setMinx(int minx);

    int getMaxy() const;

    void setMaxy(int maxy);

    int getMiny() const;

    void setMiny(int miny);

public:
    bool isReal() const;
    void setReal(bool real);

public:
    Dados();

    vector<Condutor*> getCondutores();
    vector<Pessoa*> getPessoas();
    vector<Automovel> getAutomoveis();

    void setCondutores(vector<Condutor*> condutores);
    void setPessoas(vector<Pessoa*> pessoas);
    void setAutomoveis(vector<Automovel> carros);

    const Graph<Local> &getGrafoInicial() const;
    void setGrafoInicial(const Graph<Local> &grafoInicial);
    const Graph<Local> &getGrafoConexo() const;
    void setGrafoConexo(const Graph<Local> &grafoConexo);
    const Graph<Local> &getGrafoProcessado() const;
    void setGrafoProcessado(const Graph<Local> &grafoProcessado);

    Pessoa* searchPessoa(int id);
    Local searchLocal(int id);
    int addPessoa();

    void graph_to_graphviewer(Graph<Local> &g);
    int visualizeGraph();

    void addPessoatoLocal();

    int processarGrafo();
    void runIter1(int max);
    int runAlgorithm();

    void changeGraph(string nodes,string edges,bool real);

    const vector<Vertex<Local>*> & getPdi() const;

    void setPdi(const vector<Vertex<Local>*> & pdi);
};


#endif //MEETUPRIDER_DADOS_H
