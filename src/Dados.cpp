#include "Dados.h"

Dados::Dados() {
    Graph<Local> graph;
    initGraph(graph, "../mapas/GridGraphs/16x16/nodes.txt", "../mapas/GridGraphs/16x16/edges.txt");
    vector<Condutor*> r;
    vector<Pessoa*> v=readUsers("../resources/users.txt",r);
    vector<Automovel *> c=readCarros("../resources/cars.txt");

    this->grafoInicial=graph;
    this->condutores=r;
    this->pessoas=v;
    this->carros=c;
    addPessoatoLocal();
    cout<<grafoInicial.getVertexSet()[2]->getInfo().getChegada().size();
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

const Graph<Local> &Dados::getGrafoConexo() const {
    return grafoConexo;
}

void Dados::setGrafoConexo(const Graph<Local> &grafoConexo) {
    Dados::grafoConexo = grafoConexo;
}

const Graph<Local> &Dados::getGrafoProcessado() const {
    return grafoProcessado;
}

void Dados::setGrafoProcessado(const Graph<Local> &grafoProcessado) {
    Dados::grafoProcessado = grafoProcessado;
}

Pessoa* Dados::searchPessoa(int id) {
    for (auto p : pessoas)
    {
        if (p->getId() == id)
        {
            return p;
        }
    }
    return NULL;
}

Local Dados::searchLocal(int id) {
    for(auto l :grafoInicial.getVertexSet()){
        if(l->getInfo().getId()==id){
            return l->getInfo();
        }
    }
}

void Dados::addPessoatoLocal() {
    for(auto & l:grafoInicial.getVertexSet()){
        auto local=l->getInfo();
        vector<Pessoa*>partida;
        vector<Pessoa*>chegada;
        for(auto & p:pessoas){
            if(p->getOrigem()==l->getInfo().getId())partida.push_back(p);
            else if(p->getDestino()==l->getInfo().getId())chegada.push_back(p);
        }
        local.setChegada(chegada);
        local.setPartida(partida);
        l->setInfo(local);
    }
}

void Dados::addPessoa() {
    int id, origem, destino;
    cout << "ID: "; cin >> id;
    if (searchPessoa(id) != NULL)
    {
        cout << "Já existe uma pessoa com esse ID\n";
        return;
    }
    cout << "Origem: "; cin >> origem;
    cout << "Destino: "; cin >> destino;
    int horas, minutos;
    do {
        cout << "Partida:\nHoras: "; cin >> horas;
    } while (horas >= 24);
    do {
        cout << "Minutos: "; cin >> minutos;
    } while (minutos >= 60);
    Time t1(horas, minutos);
    do {
        cout << "Partida:\nHoras: "; cin >> horas;
    } while (horas >= 24);
    do {
        cout << "Minutos: "; cin >> minutos;
    } while (minutos >= 60);
    Time t2(horas, minutos);

    Pessoa* p = new Pessoa(id, origem, destino, t1, t2);
    pessoas.push_back(p);
}

void Dados::graph_to_graphviewer(Graph<Local> &g)
{
    int width = 600;
    int height = 600;
    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->createWindow(width, height);
    gv->defineEdgeCurved(false);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    int idEdge = 0;
    for (auto v : g.getVertexSet())
    {
        gv->addNode(v->getInfo().getId(), v->getInfo().getX(), v->getInfo().getY());
        gv->setVertexLabel(v->getInfo().getId(), to_string(v->getInfo().getId()));
        for (auto a : v->getAdj())
        {
            gv->addEdge(idEdge++, v->getInfo().getId(), a.getDest()->getInfo().getId(), 0);
        }
    }
    gv->rearrange();
}

int Dados::visualizeGraph() {
    int see = -1;
    do {
        cout << "Visualizar grafo:\n";
        cout << "[1] Visualizar grafo inicial\n";
        cout << "[2] Visualizar grafo conexo\n";
        cout << "[3] Visualizar grafo processado\n";
        cout << "[0] Voltar\n";
        cin >> see;

        switch (see)
        {
            case 1:
                graph_to_graphviewer(grafoInicial);
                break;

            case 2:
                graph_to_graphviewer(grafoConexo);
                break;

            case 3:
                graph_to_graphviewer(grafoProcessado);
                break;

            case 0:
                break;

            default:
                break;
        }
    } while (see != 0);
    return 0;
}



void Dados::processarGrafo() {
    cout << "Dfs a partir do ponto de partida do condutor... " ;
    grafoInicial.dfs(condutores[0]->getOrigem());
    cout << "Concluido" << endl;
    auto destino =grafoInicial.findVertex(searchLocal(condutores[0]->getDestino()));
    if (!destino->isVisited()) {
        cout << "O destino do condutor nao e atingivel a partir da sua origem. " << endl;
        exit(0);
    }
    cout << "A obter o grafo conexo... ";
    grafoInicial.getGrafoConexo(grafoConexo);
    cout << "Concluido" << endl;
    cout << "A processar o grafo... " ;

    grafoConexo.floydWarshallShortestPath();
    int i=0;
    for (i = 0; i < grafoConexo.getVertexSet().size(); i++) {
        grafoConexo.getVertexSet()[i]->setQueueIndex(i);
        //caso o local seja partida ou chegada de algum cliente
        if (!grafoConexo.getVertexSet()[i]->getInfo().getPartida().empty() || !grafoConexo.getVertexSet()[i]->getInfo().getChegada().empty()) {
            grafoProcessado.addVertex(grafoConexo.getVertexSet()[i]->getInfo());
            grafoProcessado.findVertex(grafoConexo.getVertexSet()[i]->getInfo())->setQueueIndex(i);
        }
    }

    grafoProcessado.addVertex(grafoConexo.findVertex(searchLocal(condutores[0]->getDestino()))->getInfo());
    grafoProcessado.addVertex(grafoConexo.findVertex(searchLocal(condutores[0]->getOrigem()))->getInfo());
    grafoProcessado.setW(grafoConexo.getW());

    cout << "Concluido" << endl;

}






int Dados::runAlgorithm() {
    int option;

    do {
        cout << "\nIterações\n\n";
        cout << "[1] 1ª Iteração\n";
        cout << "[2] 2ª Iteração\n";
        cout << "[3] 3ª Iteração\n";
        cout << "[0] Back\n";
        cin >> option;

        switch(option){
            case 1:
                //Iteracao 1
                break;

            case 2:
                //Iteracao 2
                break;

            case 3:
                //Iteracao 3
                break;

            case 0:
                break;

            default:
                option = -1;
                cout << "Choose a valid number\n";
                break;
        }
    }while(option!=0);

    return 0;
}


void Dados::runIter1(int max) {



}


void Dados::changeGraph(string nodes, string edges) {
    Graph<Local> grafo;
    initGraph(grafo, nodes, edges);
    grafoInicial = grafo;
    // obter novos grafo simplificado e processado ou delete?

}