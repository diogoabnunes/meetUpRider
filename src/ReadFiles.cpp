#include "ReadFiles.h"

void initGraph(Graph<Local> &g, string nodesfile, string edgesfile, bool real) {
    parse_nodes(&g, nodesfile, real);
    parse_edges(&g, edgesfile);
}

vector<Pessoa*> readUsers(string filename, vector<Condutor> &cond) {
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

            if (l[0]=="P") {
                auto* p=new Pessoa(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada);
                pessoas.push_back(p);
            }
            else {
                auto *c = new Condutor(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada,stoi(l[6]));
                cond.push_back(*c);
            }
        }
    }
    file.close();
    return pessoas;
}

vector<Automovel> readCarros(string filename){
    vector<Automovel>carros;
    ifstream file;
    file.open(filename);
    if(!file.fail()){
        string line;
        while (!file.eof()){
            getline(file,line);
            auto l=split(line,";");
            Automovel *a = new Automovel(stoi(l[0]),stoi(l[1]));
            carros.push_back(*a);
        }
    }
    file.close();
    return carros;
}

void parse_nodes(Graph<Local> *g, string file, bool real) {
    ifstream nos(file);
    if (nos.is_open())
    {
        string line;  char useless;
        long int idNo;
        long double x, y;
        double maxx = -1, maxy = -1;
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
            /*if (real) {
                if (x > maxx) maxx = x;
                if (y > maxy) maxy = y;
            }*/
            g->addVertex(Local(idNo, x, y));
        }
        nos.close();
        /*
        if (real) {
            double toScaleX = maxx / 600;
            double toScaleY = maxy / 600;
            double auxx, auxy;
            for (auto v : g->getVertexSet()) {
                auxx = v->getInfo().getX() / toScaleX;
                auxy = v->getInfo().getY() / toScaleY;
                v->getInfo().setX(auxx);
                v->getInfo().setY(auxy);
            }
        }*/
    }
    cout << "Ficheiro de nos lido!\n";
}

void parse_edges(Graph<Local> *g, string file) {
    int idEdge = 0;
    ifstream arestas(file);
    if (arestas.is_open())
    {
        string line; char useless;
        long int idNoOrigem, idNoDestino;
        getline(arestas, line); // number of edges
        while (getline(arestas, line))
        {
            stringstream ss(line);
            ss >> useless; // (
            ss >> idNoOrigem; // id
            ss >> useless; // ,
            ss >> idNoDestino; // id
            g->addEdge(Local(idNoOrigem), Local(idNoDestino), 1); // peso tem que ser alterado conforme o tipo de estrada
            idEdge++;
        }
        arestas.close();
    }
    cout << "Ficheiro de arestas lido!\n";
}