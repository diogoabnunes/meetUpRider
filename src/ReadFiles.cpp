//
// Created by clara on 08/05/2020.
//

#include "ReadFiles.h"

void initGraph(Graph<Local> &g) {
    parse_nodes(&g, "../mapas/GridGraphs/16x16/nodes.txt");
    parse_edges(&g, "../mapas/GridGraphs/16x16/edges.txt");
}

vector<Pessoa *> readUsers(string filename, vector<Condutor*>&cond) {
    vector<Pessoa *>pessoas;
    ifstream file;
    file.open(filename);
    if(!file.fail()){
        string line;
        while (!file.eof()){
            getline(file,line);
            auto l=split(line,";");
            Time partida(l[4]);
            Time chegada(l[5]);

            if(l[0]=="P"){
                auto* p=new Pessoa(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada);
                pessoas.push_back(p);
            }
            else{
                auto * c=new Condutor(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada,stoi(l[6]));
                cond.push_back(c);

            }
        }
    }
    file.close();
    return pessoas;
}

vector<Automovel *> readCarros(string filename){
    vector<Automovel*>carros;
    ifstream file;
    file.open(filename);
    if(!file.fail()){
        string line;
        while (!file.eof()){
            getline(file,line);
            auto l=split(line,";");
            Automovel *a = new Automovel(stoi(l[0]),stoi(l[1]));
            carros.push_back(a);
        }
    }
    file.close();
    return carros;

}

void parse_nodes(GraphViewer *gv, string file) {

    ifstream nos("../mapas/GridGraphs/16x16/nodes.txt");
    if (nos.is_open())
    {
        string line; char useless;
        int idNo, x, y;
        getline(nos, line); // number of nodes
        while (getline(nos, line))
        {
            stringstream ss(line);
            ss >> useless; // (
            ss >> idNo; // id
            ss >> useless; // ,
            ss >> x; // x
            ss >> useless; // ,
            ss >> y; // y
            gv->addNode(idNo, x, y);
            gv->setVertexSize(idNo, 10);
        }
        nos.close();
    }
    cout << "nos read\n";
}

void parse_nodes(Graph<Local> *g, string file) {

    ifstream nos("../mapas/GridGraphs/16x16/nodes.txt");
    if (nos.is_open())
    {
        string line;  char useless;
        int idNo, x, y;
        getline(nos, line); // number of nodes
        while (getline(nos, line))
        {
            stringstream ss(line);
            ss >> useless; // (
            ss >> idNo; // id
            ss >> useless; // ,
            ss >> x; // x
            ss >> useless; // ,
            ss >> y; // y
            g->addVertex(Local(idNo, x, y));
        }
        nos.close();
    }
    cout << "nos read\n";
}

void parse_edges(GraphViewer *gv, string file) {

    ifstream arestas("../mapas/GridGraphs/16x16/edges.txt");
    if (arestas.is_open())
    {
        int idAresta = 0;
        string line; char useless;
        int idNoOrigem, idNoDestino;
        getline(arestas, line); // number of edges
        while (getline(arestas, line))
        {
            stringstream ss(line);
            ss >> useless; // (
            ss >> idNoOrigem; // id
            ss >> useless; // ,
            ss >> idNoDestino; // id
            gv->addEdge(idAresta, idNoOrigem, idNoDestino, 0);
            idAresta++;
        }
        arestas.close();
    }
    cout << "arestas read\n";
}

void parse_edges(Graph<Local> *g, string file) {

    ifstream arestas("../mapas/GridGraphs/16x16/edges.txt");
    if (arestas.is_open())
    {
        int idAresta = 0;
        string line; char useless;
        int idNoOrigem, idNoDestino;
        getline(arestas, line); // number of edges
        while (getline(arestas, line))
        {
            stringstream ss(line);
            ss >> useless; // (
            ss >> idNoOrigem; // id
            ss >> useless; // ,
            ss >> idNoDestino; // id
            g->addEdge(Local(idNoOrigem), Local(idNoDestino), 1); // peso tem que ser alterado conforme o tipo de estrada
        }
        arestas.close();
    }
    cout << "arestas read\n";
}