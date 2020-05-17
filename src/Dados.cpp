#include "Dados.h"

Dados::Dados() {
    Graph<Local> graph;
    initGraph(graph, "../mapas/GridGraphs/16x16/nodes.txt", "../mapas/GridGraphs/16x16/edges.txt", false);
    vector<Condutor*> r;
    vector<Pessoa*> v = readUsers("../resources/users.txt", r);
    vector<Automovel> c = readCarros("../resources/cars.txt");

    this->grafoInicial=graph;
    //processarGrafo();
    this->condutores=r;
    this->pessoas=v;
    this->carros = c;
    addPessoatoLocal();
}

vector<Condutor*> Dados::getCondutores() {
    return condutores;
}

vector<Pessoa *> Dados::getPessoas() {
    return pessoas;
}

vector<Automovel> Dados::getAutomoveis() {
    return carros;
}

void Dados::setCondutores(vector<Condutor*> condutores) {
    this->condutores=condutores;
}

void Dados::setPessoas(vector<Pessoa *> pessoas) {
    this->pessoas=pessoas;
}

void Dados::setAutomoveis(vector<Automovel> carros) {
    this->carros = carros;
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
    return Local(-1, -1, -1);
}

void Dados::addPessoatoLocal() {
    for(auto & l:grafoInicial.getVertexSet()){
        auto local=l->getInfo();
        vector<Pessoa>partida;
        vector<Pessoa>chegada;
        for(auto p : pessoas){
            if(p->getOrigem()==l->getInfo().getId())partida.push_back(*p);
            else if(p->getDestino()==l->getInfo().getId())chegada.push_back(*p);
        }
        local.setChegada(chegada);
        local.setPartida(partida);
        l->setInfo(local);
    }
}

int Dados::addPessoa() {
    int id, origem, destino;
    cout << "ID: "; cin >> id;
    if (searchPessoa(id) != NULL)
    {
        cout << "Já existe uma pessoa com esse ID\n";
        return 1;
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

    return 0;
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

    int minX = std::numeric_limits<int>::max();
    int minY = std::numeric_limits<int>::max();
    int maxX = std::numeric_limits<int>::min();
    int maxY = std::numeric_limits<int>::min();

    int idEdge = 0;
    for (auto v : g.getVertexSet())
    {
        if (real) {
            double yPercent = 1.0 - ((v->getInfo().getY() - minY)/(maxY - minY) * 0.9 + 0.05);
            double xPercent = (v->getInfo().getX() - minX)/(maxX - minX)*0.9 + 0.05;
            gv->setVertexSize(v->getInfo().getId(), 10);
            gv->addNode(v->getInfo().getId(), (int) (xPercent * width), (int) (yPercent * height));
        }
        else {
            gv->setVertexSize(v->getInfo().getId(), 10);
            gv->addNode(v->getInfo().getId(), v->getInfo().getX(), v->getInfo().getY());
        }
    }
    for (auto v : g.getVertexSet())
    {
        if (real) {
            for (auto e : v->getAdj()) {
                gv->addEdge(idEdge++, v->getInfo().getId(), e.getDest()->getInfo().getId(), 1);
            }
        }
        else {
            for (auto e : v->getAdj()) {
                gv->addEdge(idEdge++, v->getInfo().getId(), e.getDest()->getInfo().getId(), 0);
            }
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

int Dados::processarGrafo() {
    cout << "Dfs a partir do ponto de partida do condutor... " ;
    grafoInicial.dfs(condutores[0]->getOrigem());
    cout << "Concluido" << endl;
    auto destino =grafoInicial.findVertex(searchLocal(condutores[0]->getDestino()));
    if (!destino->isVisited()) {
        cout << "O destino do condutor nao e atingivel a partir da sua origem. " << endl;
        return 1;
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

    cout << "Grafo processado" << endl;
    return 0;
}

int Dados::runAlgorithm() {

    cout << "TODO, de forma a que seja possível visualizar grafos de cada iteracao?\n"; // TODO
    return 0;
}

void Dados::changeGraph(string nodes, string edges, bool real) {
    this->real = real;
    Graph<Local> grafo;
    initGraph(grafo, nodes, edges, real);
    this->grafoInicial = grafo;
    //processarGrafo();
}

bool Dados::isReal() const {
    return real;
}

void Dados::setReal(bool real) {
    Dados::real = real;
}
