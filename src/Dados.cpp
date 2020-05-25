#include "Dados.h"
#include "Viagem.h"

Dados::Dados() {
    Graph<Local> *gc = new Graph<Local>();
    Graph<Local> *gf = new Graph<Local>();
    Graph<Local> *gi = new Graph<Local>();

    grafoInicial=*gi;
    grafoConexo=*gc;


    Graph<Local> graph;
    vector<Condutor*> r;

    vector<Pessoa*> v = readUsers("../resources/users.txt", r);
    vector<Automovel> c = readCarros("../resources/cars.txt");
    lastNodes="../mapas/GridGraphs/16x16/nodes.txt";
    lastEdges="../mapas/GridGraphs/16x16/edges.txt";


    this->condutores=r;
    this->minx = INT_MAX;
    this->miny = INT_MAX;
    this->maxx = INT_MIN;
    this->maxy = INT_MIN;
    this->viagem = Viagem();
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
    cout << "ID da pessoa a adicionar: "; cin >> id;
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

int Dados::elimPessoa()
{
    int id;
    cout << "ID da pessoa a eliminar: "; cin >> id;

    if (searchPessoa(id) != NULL) {
        for (auto it = pessoas.begin(); it != pessoas.end(); it++) {
            if ((*it)->getId() == id) {
                pessoas.erase(it);
                break;
            }
        }
        return 0;
    }
    else return 1;
}

int Dados::visualizeInfoPessoa()
{
    int pers; cout << "ID a visualizar: "; cin >> pers;
    Pessoa *p = searchPessoa(pers);
    if (p != NULL) { cout << *p; return 0; }
    else { cout << "O ID que escolheu nao pertence a nenhuma pessoa...\n"; return 1; }
}

int Dados::visualizeInfo() {
    int visi = -1;
    do {
        cout << "Visualizar informacao:\n";
        cout << "[1] De todas as pessoas\n";
        cout << "[2] De uma pessoa especifica\n";
        cout << "[0] Voltar";
        cin >> visi;

        switch (visi)
        {
            case 1:
                for (auto p : pessoas) cout << *p;
                break;

            case 2:
                visualizeInfoPessoa();
                break;

            case 0:
                break;

            default:
                cin.ignore(1000, '\n');
                cout << "Numero invalido\n";
                break;
        }
    } while (visi == -1);
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
            gv->setVertexSize(v->getInfo().getId(), 1);
            auxx = (v->getInfo().getX() - minx) / (maxx - minx);
            auxy = 1 - ((v->getInfo().getY() - miny) / (maxy - miny));
            gv->setVertexLabel(v->getInfo().getId(), to_string(v->getInfo().getId()));
            gv->addNode(v->getInfo().getId(), (int) (auxx * width), (int) (auxy * height));
        }
    }
    else {
        for (auto v : g.getVertexSet()) {
            gv->setVertexSize(v->getInfo().getId(), 10);
            gv->setVertexLabel(v->getInfo().getId(), to_string(v->getInfo().getId()));
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

void Dados::graph_to_coloured_graphviewer(Graph<Local> &g) {

    int width = 600;
    int height = 600;
    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->createWindow(width, height);
    gv->defineEdgeCurved(false);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    double auxx, auxy;
    if (real) {
        for (auto v : g.getVertexSet()) {
            if (v->getInfo().getX() > maxx) maxx = v->getInfo().getX();
            if (v->getInfo().getY() > maxy) maxy = v->getInfo().getY();
            if (v->getInfo().getX() < minx) minx = v->getInfo().getX();
            if (v->getInfo().getY() < miny) miny = v->getInfo().getY();
        }
        for (auto v : g.getVertexSet()) {
            gv->setVertexSize(v->getInfo().getId(), 1);
            auxx = (v->getInfo().getX() - minx) / (maxx - minx);
            auxy = 1 - ((v->getInfo().getY() - miny) / (maxy - miny));
            gv->setVertexLabel(v->getInfo().getId(), to_string(v->getInfo().getId()));
            gv->addNode(v->getInfo().getId(), (int) (auxx * width), (int) (auxy * height));
        }
    }
    else {
        for (auto v : g.getVertexSet()) {
            gv->setVertexSize(v->getInfo().getId(), 10);
            gv->setVertexLabel(v->getInfo().getId(), to_string(v->getInfo().getId()));
            gv->addNode(v->getInfo().getId(), (int) v->getInfo().getX(), (int) v->getInfo().getY());
        }
    }
    int idEdge = 0;
    for (auto v : g.getVertexSet())
    {
        for (auto e : v->getAdj()) {
            gv->addEdge(idEdge++, v->getInfo().getId(), e.getDest()->getInfo().getId(), 1);
        }
    }
    idEdge = 10000;
    Vertex<Local> inicio = viagem.getPercurso()[0];
    Vertex<Local> fim = viagem.getPercurso()[viagem.getPercurso().size() - 1];
    Vertex<Local> *here = nullptr;

    for (auto &v : viagem.getPercurso())
    {
        if (v.getId() != inicio.getInfo().getId() && v.getId() != fim.getInfo().getId()) {
            cout << "";
        }
        if (here == nullptr) here = grafoConexo.findVertex(v);
        else {

            gv->setEdgeColor(idEdge, "green");

            gv->addEdge(idEdge++, here->getInfo().getId(), v.getId(), 1);
            here = grafoConexo.findVertex(v);
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
                graph_to_coloured_graphviewer(grafoConexo);
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
        char option;
        cout << "O destino do condutor nao e atingivel a partir da sua origem. " << endl;
        cout <<"Gerar novas pessoas [Y/n]?";
        cin >> option;
        if(tolower(option)=='y') {
            cout<<"\nloading...";
            fflush(stdout);
            do {
                changeGraph2();
                grafoInicial.dfs(condutores[0]->getOrigem());
                destino = grafoInicial.findVertex(searchLocal(condutores[0]->getDestino()));
            } while (!destino->isVisited());
        } else exit(0);
    }
    cout << "\nA obter o grafo conexo... ";
    Graph<Local> gc;
    grafoInicial.getGrafoConexo(gc);
    cout << "Concluido" << endl;
    cout << "A processar o grafo..." ;
    fflush(stdout);
    grafoConexo=gc;

    /** seeing if map has saved matrix*/
   /* string path;
    ifstream file;
    auto v=split(lastNodes,"/");

    for(int i=0;i<v.size()-1;i++)
        path.append(v.at(i)+"/");

    path.append("floyd_W_P.txt");
    file.open(path);

    if(!file.is_open()) {
        grafoConexo.floydWarshallShortestPath();
        char option;
        cout<<"Save Floyd's matrix for future use? [Y/n]?";
        cin >> option;
        if(tolower(option)=='y') writePreprocessedMatrix(&grafoConexo,path);
    }
    else {
        file.close();
        readPreprocessedMatrix(&grafoConexo,path);
    }*/
    /***************************************/
    grafoConexo.floydWarshallShortestPath();
    cout << "Grafo processado" << endl;
    return 0;
}

int Dados::runAlgorithm() {
    int see = -1;
    do {
        cout<<endl;
        cout << "Iteracoes:\n";
        cout << "[1] 1a Iteracao\n";
        cout << "[2] 2a Iteracao \n";
        cout << "[3] 3a Iteracao\n";
        cout << "[0] Voltar\n";
        cin >> see;

        startTime();
        switch (see)
        {
            case 1:
                runIter1(1000);
                break;

            case 2:
                runIter2(1000);
                break;

            case 3:
                runIter3(1000);
                break;

            case 0:
                break;

            default:
                break;
        }
        double a = elapsedTime();
        cout << "Elapsed time: " << a << " ms" << endl;
        cout << "Elapsed time: " << a/1000.0 << " s" << endl;
    } while (see != 0);
    return 0;





    cout << "TODO, de forma a que seja possível visualizar grafos de cada iteracao?\n"; // TODO
    return 0;
}

//struct com informação a ser utilizada na função de prioridade
struct priorityData {
    Vertex<Local>*vatual; //ver
    Vertex <Local>*dest;
    double **W;
    Graph<Local> *g;
    Time currentTime;
};

struct priorityData info;

double priorityIter2(Vertex<Local>*v){
    double timeToV=info.g->getpathtime(info.vatual->getInfo(),v->getInfo());
    double timeToDestfromV=info.g->getpathtime(v->getInfo(),info.dest->getInfo());
    return timeToV*5+timeToDestfromV;//pontos mais proximos do vertice atual têm maior prioridade
}


double priorityiter1(Vertex<Local> *v) {
    double distTov=info.W[info.g->findVertexIdx(info.vatual->getInfo())][info.g->findVertexIdx(v->getInfo())];
    double vtoDestdist= info.W[info.g->findVertexIdx(v->getInfo())][info.g->findVertexIdx(info.dest->getInfo())];
    return distTov+vtoDestdist;
}

double priorityPassengers( Pessoa* p){
    double distToOrig=info.W[info.g->findVertexIdx(info.vatual->getInfo())][info.g->findLocalId(p->getOrigem())];
    double distToDest=info.W[info.g->findVertexIdx(info.vatual->getInfo())][info.g->findVertexIdx(p->getDestino())];
    return distToDest+distToOrig;
}

struct Choicefunc1
{
    bool operator()(Vertex<Local>* lhs, Vertex<Local>* rhs)
    {
        return priorityiter1(lhs) > priorityiter1(rhs);
    }
};



struct Choicefunc2
{
    bool operator()(Vertex<Local>* lhs, Vertex<Local>* rhs)
    {
        return priorityIter2(lhs) > priorityIter2(rhs);
    }
};




struct Choicefunc3
{
    bool operator()(Vertex<Local>* lhs, Vertex<Local>* rhs)
    {
        return info.g->getpathtime(info.vatual->getInfo(),lhs->getInfo()) > info.g->getpathtime(info.vatual->getInfo(),rhs->getInfo());
    }
};



struct ChoicefuncPassengers
{
    bool operator()(Pessoa* lhs, Pessoa* rhs)
    {
        return priorityPassengers(lhs) > priorityPassengers(lhs);
    }
};





Graph<Local> Dados::pdiIter1_2() {
    Graph<Local> pdi;
    for(auto v:grafoConexo.getVertexSet()) {
        if (!v->getInfo().getPartida().empty()) {
            pdi.addVertex(v->getInfo());
        }
    }
    return pdi;
}



void Dados::runIter1(int max) {
    vector<Pessoa*> passageiros;
    vector<Local>percurso;
    priority_queue<Vertex<Local>*,vector<Vertex<Local>*>,Choicefunc1>fila;
    condutores[0]->setPickup(condutores[0]->getHoraMinPartida());
    info.dest=grafoConexo.findVertex(searchLocal(condutores[0]->getDestino()));
    info.vatual=grafoConexo.findVertex(searchLocal(condutores[0]->getOrigem()));
    percurso.push_back(info.vatual->getInfo());
    info.W=grafoConexo.getW();
    info.g=&grafoConexo;

    auto pdi=pdiIter1_2();
    for(auto v: pdi.getVertexSet()){
        double d = info.vatual->getInfo().distance(v->getInfo());
        if(!v->getInfo().getPartida().empty() && d < max) fila.push(v);

    }

    Vertex<Local>* candidate;
    int pax=0;
    carros[0].setNSeats(10);
    while(pax<carros[0].getNSeats()&&!fila.empty()){
        while(!fila.empty())fila.pop();
        for(auto v: pdi.getVertexSet()){
            double d = info.vatual->getInfo().distance(v->getInfo());
            if(!v->getInfo().getPartida().empty() && d < max) fila.push(v);

        }

        if(fila.empty())break;
        candidate= fila.top();
        fila.pop();
        if (fillCarIter1(candidate, passageiros,  percurso,pdi,  pax))continue;
    }
    viagem.setPassageiros(passageiros);
    viagem.setPercurso(percurso);
    if (fila.empty()){
        cout << "Todos os passageiros que eram compativeis com a boleia foram transportados"<<endl;

        for(auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl;

    }
    else {
        cout << "Nem todos os passageiros compativeis foram tranportados pois a lotacao do carro foi atingida"<<endl;
        for (auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl;
    }

}


int Dados::fillCarIter1(Vertex<Local> *&candidate, vector<Pessoa *> &passageiros, vector<Local> &percurso,Graph<Local> &pdi, int & pax) {
    double distToCandidate=grafoConexo.getW()[grafoConexo.findVertexIdx(info.vatual->getInfo())][grafoConexo.findVertexIdx(candidate->getInfo())];
    if(distToCandidate==INF){
        pdi.removeVertex(candidate->getInfo());
        return 1;
    }

    double candidateToDest=grafoConexo.getW()[grafoConexo.findVertexIdx(candidate->getInfo())][grafoConexo.findVertexIdx(info.dest->getInfo())];

    if(candidateToDest==INF){
        pdi.removeVertex(candidate->getInfo());
        return 1;
    }
    auto p=candidate->getInfo().getPartida();
    //percorre todos os clientes à espera de boleia no local candidato
    for(auto it=p.begin();it<p.end();it++) {
        if (pax < carros[0].getNSeats()){
            passageiros.push_back(*it);
            pax++;
            p.erase(it);
            it--;

        }
        else break;
    }
    percurso.push_back(candidate->getInfo());
    info.vatual=candidate;
    pdi.removeVertex(candidate->getInfo());
    return 0;
}




void Dados::runIter2(int max) {
    vector<Pessoa*> passageiros;
    Graph<Local>percurso;
    priority_queue<Vertex<Local>*,vector<Vertex<Local>*>,Choicefunc2>fila;
    condutores[0]->setPickup(condutores[0]->getHoraMinPartida());
    info.dest=grafoConexo.findVertex(searchLocal(condutores[0]->getDestino()));
    info.vatual=grafoConexo.findVertex(searchLocal(condutores[0]->getOrigem()));
    info.currentTime=condutores[0]->getHoraMinPartida();
    percurso.addVertex(info.vatual->getInfo());
    info.W=grafoConexo.getW();
    info.g=&grafoConexo;

    auto pdi=pdiIter1_2();
    for(auto v: pdi.getVertexSet()){
        double d = info.vatual->getInfo().distance(v->getInfo());
        if(!v->getInfo().getPartida().empty() && d < max) fila.push(v);

    }

    Vertex<Local>* candidate;
    int pax=0;
    while(pax<carros[0].getNSeats()&&!fila.empty()){
        while(!fila.empty())fila.pop();
        for(auto v: pdi.getVertexSet()){
            double d = info.vatual->getInfo().distance(v->getInfo());
            if(!v->getInfo().getPartida().empty() && d < max) fila.push(v);

        }

        if(fila.empty())break;
        candidate= fila.top();
        fila.pop();
        if (fillCarIter2(candidate, passageiros,  percurso,pdi,  pax))continue;

    }
    info.dest->getInfo().setPassagem(Time(grafoConexo.getpathtime(info.vatual->getInfo(),info.dest->getInfo()))+info.currentTime);
    percurso.addVertex(info.dest->getInfo());

    viagem.setPassageiros(passageiros);
    vector<Local>locals;

    for(auto p:percurso.getVertexSet()){
        locals.push_back(p->getInfo());
    }
    viagem.setPercurso(locals);
    if (fila.empty()){
        cout << "Todos os passageiros que eram compativeis com a boleia foram transportados"<<endl<<endl;

        for(auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << "   Id do local:"<<p->getOrigem()<<endl<< "   Hora de pickUp: "<<p->getPickup()<<endl;
        
    }
    else {
        cout << "Nem todos os passageiros compativeis foram tranportados pois a lotacao do carro foi atingida"<<endl<<endl;
        for (auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl<< "Hora de pickUp: "<<p->getPickup()<<endl;


    }
}


int
Dados::fillCarIter2(Vertex<Local> *&candidate, vector<Pessoa *> &passageiros, Graph<Local>& percurso, Graph<Local> &pdi,int &pax) {
    bool transportou=false;
    double timeToCandidate=grafoConexo.getpathtime(info.vatual->getInfo(),candidate->getInfo());
    if(timeToCandidate==INF){
        auto a=candidate->getInfo();
        pdi.removeVertex(a);
        return 1;
    }

    double timecandidateToDest=grafoConexo. getpathtime(candidate->getInfo(),info.dest->getInfo());
    if(timecandidateToDest==INF){pdi.removeVertex(candidate->getInfo());return 1;}
    auto p=candidate->getInfo().getPartida();
    //percorre todos os clientes à espera de boleia no local candidato
    for(auto it=p.begin();it<p.end();it++) {
        if (pax < carros[0].getNSeats()){
            if((*it)->getHoraMinPartida()<=info.currentTime+Time(timeToCandidate) && condutores[0]->getHoraMaxChegada()>(info.currentTime+Time(timeToCandidate)+Time(timecandidateToDest)) && (*it)->getHoraMaxChegada()>(info.currentTime+Time(timeToCandidate)+Time(timecandidateToDest))){
                (*it)->setPickup(info.currentTime+Time(timeToCandidate));

                passageiros.push_back(*it);
                pax++;
                p.erase(it);
                it--;
                transportou=true;
            }
        }
        else break;
    }
    if(transportou) {
        candidate->getInfo().setPassagem(Time(grafoConexo.getpathtime(info.vatual->getInfo(),candidate->getInfo()))+info.currentTime);
        percurso.addVertex(candidate->getInfo());
        info.vatual = candidate;
        info.currentTime = info.currentTime + Time(timeToCandidate);
    }

    pdi.removeVertex(candidate->getInfo());
    return 0;
}




vector<Vertex<Local>*> Dados::getCandidateOrigs(Graph<Local> pdi) {
    vector<Vertex<Local>*> fila;
    for(auto l:pdi.getVertexSet()){
        if(!l->getInfo().getPartida().empty()){
            fila.push_back(l);
        }
    }
    sort(fila.begin(),fila.end(),Choicefunc3());
    return fila;
}



vector<Vertex<Local>*> Dados::getCandidateDest(Graph<Local> pdi) {
    vector<Vertex<Local>*> fila;
    for(auto l:pdi.getVertexSet()){
        if(!l->getInfo().getChegada().empty()){
            fila.push_back(l);
        }
    }
    sort(fila.begin(),fila.end(),Choicefunc3());
    return fila;
}




Graph<Local> Dados::pdiIter3(vector<Pessoa*> passengers) {
    Graph<Local> g;
    for(auto p:passengers){
        //adiciona as origens e destinos dos passageiros candidatos
        g.addVertex(grafoConexo.getVertexSet()[grafoConexo.findLocalId(p->getOrigem())]->getInfo());
        g.addVertex(grafoConexo.getVertexSet()[grafoConexo.findLocalId(p->getDestino())]->getInfo());
    }
    return g;
}



void Dados::runIter3(int max) {
    info.dest=grafoConexo.findVertex(searchLocal(condutores[0]->getDestino()));
    info.vatual=grafoConexo.findVertex(searchLocal(condutores[0]->getOrigem()));
    info.currentTime=condutores[0]->getHoraMinPartida();
    auto candidates= getCandidatePassengers();
    vector<Pessoa*> passageiros;
    Graph<Local>percurso;

    int pax=0;
    for(auto c:candidates){
        //o passageiro só é adicionado caso o vertice de chegada não tenha já sido percorrido
        // e se houver caminho desde o ultimo vertice percorrido até À origem do condutor e o tempo de percorrer esse caminho permita o passageiro chegar a horas
        if (pax==carros[0].getNSeats())break;
        if(percurso.findLocalId(c->getDestino())==-1 ) {
            Time passagem = grafoConexo.findLocal(c->getOrigem()).getPassagem();
            Time timetoFinalDest=Time(grafoConexo.getpathtime(grafoConexo.findVertex(searchLocal(c->getDestino()))->getInfo(),info.dest->getInfo()));
            Time tchegada= info.currentTime+Time(grafoConexo.getpathtime(info.vatual->getInfo(),grafoConexo.findVertex(searchLocal(c->getOrigem()))->getInfo()));
            //caso o vertice de partida pertença já ao percurso
            //e se a hora de passagem no vertice for superior ou igual à gora minima de partida do passageiro
            if (percurso.findLocalId(c->getOrigem()) != -1 && tchegada<c->getHoraMaxChegada() && passagem >= c->getHoraMinPartida() && tchegada+timetoFinalDest<condutores[0]->getHoraMaxChegada()) {

                //verificadas estas condiçoes o passageiro é transportado
                info.currentTime=tchegada;
                info.vatual=grafoConexo.findVertex(searchLocal(c->getOrigem()));
                c->setPickup(passagem);
                passageiros.push_back(c);
                auto local=grafoConexo.findLocal(c->getDestino());
                local.setPassagem(tchegada);
                percurso.addVertex(local);
                pax++;
            }
            else{
                Local origem = grafoConexo.findVertex(searchLocal(c->getOrigem()))->getInfo();
                Local destino=grafoConexo.findVertex(searchLocal(c->getDestino()))->getInfo();
                Time timetoPorig=Time(grafoConexo.getpathtime(info.vatual->getInfo(),origem));
                Time timeFromPorigToDest=Time(grafoConexo.getpathtime(origem,destino));
                Time timeFromPdestToFinalDest=Time(grafoConexo.getpathtime(origem,info.dest->getInfo()));
                if(info.currentTime+timeFromPorigToDest>c->getHoraMinPartida() && info.currentTime+timetoPorig+timeFromPorigToDest<c->getHoraMaxChegada()
                &&  info.currentTime+timetoPorig+timeFromPorigToDest+timeFromPdestToFinalDest<condutores[0]->getHoraMaxChegada())
                {
                    origem.setPassagem(info.currentTime+timetoPorig);
                    c->setPickup(info.currentTime+timetoPorig);
                    passageiros.push_back(c);
                    info.currentTime=info.currentTime+timetoPorig+timeFromPorigToDest;
                    destino.setPassagem(info.currentTime);
                    percurso.addVertex(origem);
                    percurso.addVertex(destino);
                    pax++;
                }
            }
        }
    }
    viagem.setPassageiros(passageiros);
    vector<Local>locals;
    for(auto p:percurso.getVertexSet()){
        locals.push_back(p->getInfo());
    }
    viagem.setPercurso(locals);

    if (pax!=carros[0].getNSeats()){
        cout << "Todos os passageiros que eram compativeis com a boleia foram transportados"<<endl<<endl;
        cout << "Passageiros:"<<endl;
        for(auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl<< "Hora de pickUp: "<<p->getPickup()<<endl;
        cout << "Percurso:"<<endl;
        for(auto p:locals)cout<<"Id do Local:" <<p.getId() << endl <<  "Hora de passagem: "<<p.getPassagem()<<endl;
    }
    else {
        cout << "Nem todos os passageiros compativeis foram tranportados pois a lotacao do carro foi atingida"<<endl<<endl;
        cout << "Todos os passageiros que eram compativeis com a boleia foram transportados"<<endl;
        cout << "Passageiros:"<<endl;
        for(auto p:passageiros)cout <<"Id do Passageiro:" <<p->getId() << endl << "Id do local:"<<p->getOrigem()<<endl<< "Hora de pickUp: "<<p->getPickup()<<endl;
        cout << "Percurso:"<<endl;
        for(auto p:locals)cout<<"Id do Local:" <<p.getId() << endl <<  "Hora de passagem: "<<p.getPassagem()<<endl;
    }
}






void Dados::changeGraph(string nodes, string edges, bool real) {
    lastNodes=nodes;
    lastEdges=edges;
    this->real = real;
    Graph<Local> grafo;
    initGraph(grafo, nodes, edges, real);
    this->grafoInicial = grafo;

    vector<Condutor*> r;
    pessoas = readUsers("../resources/random_users.txt", r);
    carros = readCarros("../resources/random_cars.txt");
    this->condutores=r;

    addPessoatoLocal();
    processarGrafo();
}

void Dados::changeGraph2() {
    generatePeople(&grafoInicial);
    vector<Condutor*> r;
    pessoas = readUsers("../resources/random_users.txt", r);
    carros = readCarros("../resources/random_cars.txt");
    this->condutores=r;

    addPessoatoLocal();
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

const vector<Automovel> &Dados::getCarros() const {
    return carros;
}

void Dados::setCarros(const vector<Automovel> &carros) {
    Dados::carros = carros;
}

const Viagem &Dados::getViagem() const {
    return viagem;
}

void Dados::setViagem(const Viagem &viagem) {
    Dados::viagem = viagem;
}


int Dados::analiseComplexity() {
    cout << "TODO\n";
    return 0;
}

vector<Pessoa *> Dados::getCandidatePassengers() {
    vector<Pessoa *> candidates;

    for(auto p:pessoas){
        auto o=grafoConexo.findLocalId(p->getOrigem());
        auto d=grafoConexo.findLocalId(p->getDestino());
        if(o!=-1&& d!=-1 &&grafoConexo.getW()[grafoConexo.findLocalId(condutores[0]->getOrigem())][grafoConexo.findLocalId(p->getOrigem())]!=INF
        && grafoConexo.getW()[grafoConexo.findLocalId(p->getOrigem())][grafoConexo.findLocalId(condutores[0]->getOrigem())]!=INF
        && grafoConexo.getW()[grafoConexo.findLocalId(p->getOrigem())][grafoConexo.findLocalId(p->getOrigem())]!=INF)
        candidates.push_back(p);
    }
    //sort(candidates.begin(),candidates.end(),ChoicefuncPassengers());
    return candidates;

}
