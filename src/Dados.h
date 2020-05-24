#ifndef MEETUPRIDER_DADOS_H
#define MEETUPRIDER_DADOS_H

#include "Condutor.h"
#include "Pessoa.h"
#include "Automovel.h"
#include "Graph.h"
#include "Local.h"
#include "ReadFiles.h"
#include "limits.h"
#include "Viagem.h"

#include <vector>

using namespace std;

class Dados {
private:
    Graph<Local> grafoInicial;
    Graph<Local> grafoConexo;
    Graph<Local> grafoProcessado;
    vector<Condutor*> condutores;
    vector<Pessoa*> pessoas;
    vector<Automovel> carros;
    Viagem viagem;

public:
    const vector<Automovel> &getCarros() const;

    void setCarros(const vector<Automovel> &carros);

    const Viagem &getViagem() const;

    void setViagem(const Viagem &viagem);

private:
    bool real;
    int maxx, minx, maxy, miny;
    string lastNodes,lastEdges;

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

    bool isReal() const;
    void setReal(bool real);

    int getMaxx() const;
    void setMaxx(int maxx);
    int getMinx() const;
    void setMinx(int minx);
    int getMaxy() const;
    void setMaxy(int maxy);
    int getMiny() const;
    void setMiny(int miny);

    Pessoa* searchPessoa(int id);
    Local searchLocal(int id);
    int addPessoa();
    int elimPessoa();
    int visualizeInfoPessoa();
    int visualizeInfo();

    void graph_to_coloured_graphviewer(Graph<Local> &g);
    void graph_to_graphviewer(Graph<Local> &g);
    int visualizeGraph();

    void addPessoatoLocal();

    int processarGrafo();

    //iteraçoes

    Graph<Local> pdiIter1_2();//seleciona os pontos de interesse das iterações 1 e 2
    Graph<Local> pdiIter3(vector<Pessoa*> passengers);
    void runIter1(int max);
    void runIter2(int max);


    vector<Vertex<Local>*> getCandidateOrigs(Graph<Local> pdi);

    vector<Vertex<Local>*> getCandidateDest(Graph<Local> pdi);



    int fillCarIter1( Vertex<Local>* & candidate, vector<Pessoa*>& passageiros,vector<Local>&percurso , Graph<Local>& pdi  ,int & pax );
    int fillCarIter2( Vertex<Local>* & candidate, vector<Pessoa*>& passageiros,Graph<Local> &percurso , Graph<Local>& pdi  ,int & pax );

    vector<Pessoa*>getCandidatePassengers();

    void runIter3(int max);

    int runAlgorithm();

    void changeGraph(string nodes,string edges,bool real);
    void changeGraph2();

    void refreshUsers(string users);

    int analiseComplexity();
};


#endif //MEETUPRIDER_DADOS_H
