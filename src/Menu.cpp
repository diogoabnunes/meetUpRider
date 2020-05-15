#include "Menu.h"
#include "ReadFiles.h"

#include <iostream>

using namespace std;


Menu::Menu(const Dados &dados) : dados(dados) {}

const Dados &Menu::getDados() const {
    return dados;
}

void Menu::setDados(const Dados &dados) {
    Menu::dados = dados;
}


void Menu::showMenu(Dados &dados) {
    int option = -1;
    do {
        cout << "\nMeetUpRider\n\n";
        cout << "[1] Visualizar grafo\n";
        cout << "[2] Visualizar informação de uma pessoa específica\n";
        cout << "[3] Adicionar pessoa\n";
        cout << "[4] Remover pessoa\n";
        cout << "[0] Terminar programa\n";
        cin >> option;

        switch (option)
        {
            case 1:
                if (this->visualizeGraph(dados) != 0) {
                    cout << "Error visualizing graph\n";
                    exit(1);
                }
                break;

            case 2:
                //visualizeInfo();
                break;

            case 3:
                //addPessoa();
                break;

            case 4:
                //delPessoa();
                break;

            case 0:
                break;

            default:
                option = -1;
                cout << "Choose a valid number\n";
                break;
        }
    } while (option != 0);
}

void graph_to_graphviewer(const Graph<Local> &g)
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

int Menu::visualizeGraph(Dados &dados) {
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
                graph_to_graphviewer(dados.getGrafoInicial());
                break;

            case 2:
                graph_to_graphviewer(dados.getGrafoConexo());
                break;

            case 3:
                graph_to_graphviewer(dados.getGrafoProcessado());
                break;

            case 0:
                break;

            default:
                break;
        }
    } while (see != 0);
    return 0;
}
