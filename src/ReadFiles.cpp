#include "ReadFiles.h"

void initGraph(Graph<Local> &g, string nodesfile, string edgesfile, bool real) {
    parse_nodes(&g, nodesfile, real);
    parse_edges(&g, edgesfile);
    generatePeople(&g);
}

vector<Pessoa*> readUsers(string filename, vector<Condutor*> &cond) {
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
                auto* p=new Pessoa(stol(l[1]),stol(l[2]),stol(l[3]),partida,chegada);
                pessoas.push_back(p);
            }
            else {
                auto *c = new Condutor(stol(l[1]),stol(l[2]),stol(l[3]),partida,chegada,stol(l[6]));
                cond.push_back(c);
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
            Automovel *a = new Automovel(stol(l[0]),stol(l[1]));
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
    cout << file << " lido!\n";
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
            g->addEdge(Local(idNoOrigem), Local(idNoDestino), g->calcEdgeWeight(Local(idNoOrigem), Local(idNoDestino)));
            idEdge++;
        }
        arestas.close();
    }
    cout << file << " lido!\n";
}

void generatePeople(Graph<Local> *graph){

    int start,end,n1,n2;
    int nVertex=graph->getNumVertex();
    Time ti,tf;

    srand(time(NULL));

    n1=rand()%nVertex;
    n2=rand()%nVertex;
    start=graph->getVertexSet().at(0)->getInfo().getId(); // change 0 to n1
    end=graph->getVertexSet().at(n2)->getInfo().getId();

    ti.setHour(rand()%20);
    ti.setMinutes(rand()%60);
    do{
        tf.setHour(rand()%24);
        tf.setMinutes(rand()%60);
    } while(tf<ti);

    ofstream file("../resources/random_cars.txt");
    file<<"0;"<<2+rand()%9;
    file.close();

    file.open("../resources/random_users.txt");
    file<<"C;0;"<<start<<";"<<end<<";"<<ti.getHour()<<"h"<<ti.getMinutes()<<";"<<tf.getHour()<<"h"<<tf.getMinutes()<<";"<<0<<endl;

    for(int i=1; i < numPeople ; i++ ){

        n1=rand()%nVertex;
        n2=rand()%nVertex;
        start=graph->getVertexSet().at(n1)->getInfo().getId();
        end=graph->getVertexSet().at(n2)->getInfo().getId();

        ti.setHour(rand()%20);
        ti.setMinutes(rand()%60);
        do{
            tf.setHour(rand()%24);
            tf.setMinutes(rand()%60);
        } while(tf<ti);

        file<<"P;"<<i<<";"<<start<<";"<<end<<";"<<ti.getHour()<<"h"<<ti.getMinutes()<<";"<<tf.getHour()<<"h"<<tf.getMinutes();

        if(i+1!=numPeople)
            file<<endl;
    }

    file.close();
}