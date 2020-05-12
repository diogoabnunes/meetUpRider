#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "src/ReadFiles.h"
#include "src/Pessoa.h"

using namespace std;

int visualizeGraph();

int main() {
    initGraph();
    vector<Condutor*>r;
    vector<Pessoa*> v=readUsers("../resources/users.txt",r);
    auto c=readCarros("../resources/cars.txt");

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
                if (visualizeGraph() != 0) {
                    cout << "Error visualizing graph\n";
                    return 1;
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

    return 0;
}

int visualizeGraph() {
    int width = 600;
    int height = 600;

    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->createWindow(width, height);
    gv->defineEdgeCurved(false);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    parse_nodes(gv, "../mapas/GridGraphs/16x16/nodes.txt");
    parse_edges(gv, "../mapas/GridGraphs/16x16/edges.txt");

    gv->rearrange();

    return 0;
}