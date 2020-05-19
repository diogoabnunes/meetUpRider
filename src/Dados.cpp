#include "Dados.h"
#include "Viagem.h"

Dados::Dados() {
    Graph<Local> graph;
    vector<Condutor*> r;
    vector<Pessoa*> v = readUsers("../resources/users.txt", r);
    vector<Automovel> c = readCarros("../resources/cars.txt");

    initGraph(grafoInicial, "../mapas/GridGraphs/16x16/nodes.txt", "../mapas/GridGraphs/16x16/edges.txt", false);

    this->condutores=r;
    this->pessoas=v;
    this->carros = c;
    addPessoatoLocal();
    processarGrafo();
    this->minx = INT_MAX;
    this->miny = INT_MAX;
    this->maxx = INT_MIN;
    this->maxy = INT_MIN;
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
        vector<Pessoa*>partida;
        vector<Pessoa*>chegada;
        for(auto p : pessoas){
            if(p->getOrigem()==l->getInfo().getId())partida.push_back(p);
            else if(p->getDestino()==l->getInfo().getId())chegada.push_back(p);
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

    int idEdge = 0;

    double auxx, auxy;
    if (real) {
        for (auto v : g.getVertexSet()) {
            if (v->getInfo().getX() > maxx) maxx = v->getInfo().getX();
            if (v->getInfo().getY() > maxy) maxy = v->getInfo().getY();
            if (v->getInfo().getX() < minx) minx = v->getInfo().getX();
            if (v->getInfo().getY() < miny) miny = v->getInfo().getY();
        }
        for (auto v : g.getVertexSet()) {
            gv->setVertexSize(v->getInfo().getId(), 10);
            auxx = (v->getInfo().getX() - minx) / (maxx - minx);
            auxy = 1 - ((v->getInfo().getY() - miny) / (maxy - miny));
            gv->addNode(v->getInfo().getId(), (int) (auxx * width), (int) (auxy * height));
        }
    }
    else {
        for (auto v : g.getVertexSet()) {
            gv->setVertexSize(v->getInfo().getId(), 10);
            gv->addNode(v->getInfo().getId(), (int) v->getInfo().getX(), (int) v->getInfo().getY());
        }
    }
    for (auto v : g.getVertexSet())
    {
        for (auto e : v->getAdj()) {
            gv->addEdge(idEdge++, v->getInfo().getId(), e.getDest()->getInfo().getId(), 1);
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
        exit(1) ;
    }
    cout << "A obter o grafo conexo... ";
    grafoInicial.getGrafoConexo(grafoConexo);
    cout << "Concluido" << endl;
    cout << "A processar o grafo... " ;

    grafoConexo.floydWarshallShortestPath();

    cout << "Grafo processado" << endl;
    return 0;
}

int Dados::runAlgorithm() {
    runIter1(10000);
    cout << "TODO, de forma a que seja possível visualizar grafos de cada iteracao?\n"; // TODO
    return 0;
}

//struct com informação a ser utilizada na função de prioridade
struct priorityData {
    Vertex<Local>*vatual; //ver
    Vertex <Local>*dest;
    double **W;
    Graph<Local> *g;
};

struct priorityData info;


double priorityiter1(Vertex<Local> *v) {
    double distTov=info.W[info.g->findVertexIdx(info.vatual->getInfo())][info.g->findVertexIdx(v->getInfo())];
    double vtoDestdist= info.W[info.g->findVertexIdx(v->getInfo())][info.g->findVertexIdx(info.dest->getInfo())];
    return distTov+vtoDestdist;
}

struct Choicefunc1
{
    bool operator()(Vertex<Local>* lhs, Vertex<Local>* rhs)
    {
        return priorityiter1(lhs) > priorityiter1(rhs);
    }
};


vector<Vertex<Local> *> Dados::pdiIter1() {
    vector<Vertex<Local> *> pdi;
    for(auto v:grafoConexo.getVertexSet()) {
        if (!v->getInfo().getPartida().empty()) {
            pdi.push_back(v);
        }
    }
    return pdi;
}

void Dados::runIter1(int max) {
    vector<Pessoa*> passageiros;
    vector<Local>percurso;

    priority_queue<Vertex<Local>*,vector<Vertex<Local>*>,Choicefunc1>fila;

    condutores[0]->setPickup(condutores[0]->getHoraPartida());
    //passageiros.push_back(condutores[0]);
    info.dest=grafoConexo.findVertex(searchLocal(condutores[0]->getDestino()));
    info.vatual=grafoConexo.findVertex(searchLocal(condutores[0]->getOrigem()));
    percurso.push_back(info.vatual->getInfo());
    info.W=grafoConexo.getW();
    info.g=&grafoConexo;

    auto pdi=pdiIter1();

    for(auto v: pdi){
        double d = info.vatual->getInfo().distance(v->getInfo());
        if(!v->getInfo().getPartida().empty() && d < max) fila.push(v);

    }
    Vertex<Local>* candidate;
    int pax=0;
    while(pax<carros[0].getNSeats()&&!fila.empty()){

        candidate= fila.top();
        fila.pop();

        double distToCandidate=info.W[info.g->findVertexIdx(info.vatual->getInfo())][info.g->findVertexIdx(candidate->getInfo())];
        if(distToCandidate==INF)continue;
        double candidateToDest=info.W[info.g->findVertexIdx(candidate->getInfo())][info.g->findVertexIdx(info.dest->getInfo())];
        if(candidateToDest==INF)continue;
        auto p=candidate->getInfo().getPartida();
        //percorre todos os clientes à espera de boleia no local candidato
        for(auto it=p.begin();it<p.end();it++) {
            if (pax < carros[0].getNSeats()){
                passageiros.push_back(*it);
                pax++;
                p.erase(it);

            }
            else break;
        }
        percurso.push_back(candidate->getInfo());

        }
    Viagem viagem(percurso,passageiros);
    if (fila.empty()){
        cout << "Todos os passageiros que eram compativeis com a boleia foram transportados"<<endl;

        for(auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl;

    }
    else {
        cout << "Nem todos os passageiros compativeis foram tranportados pois a lotacao do carro foi atingida"<<endl;
        for (auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl;
    }
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

int Dados::getMaxx() const {
    return maxx;
}

void Dados::setMaxx(int maxx) {
    Dados::maxx = maxx;
}

int Dados::getMinx() const {
    return minx;
}

void Dados::setMinx(int minx) {
    Dados::minx = minx;
}

int Dados::getMaxy() const {
    return maxy;
}

void Dados::setMaxy(int maxy) {
    Dados::maxy = maxy;
}

int Dados::getMiny() const {
    return miny;
}

void Dados::setMiny(int miny) {
    Dados::miny = miny;
}

