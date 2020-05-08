#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void parse_nodes(GraphViewer *gv, string file);
void parse_edges(GraphViewer *gv, string file);

int main() {
    int width = 600;
    int height = 600;

    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->setBackground("../earth.jpg");
    gv->createWindow(width, height);
    gv->defineEdgeCurved(false);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    parse_nodes(gv, "../mapas/GridGraphs/16x16/nodes.txt");
    parse_edges(gv, "../mapas/GridGraphs/16x16/edges.txt");

    gv->rearrange();

    getchar();
    gv->closeWindow();

    return 0;
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
    cout << "nos readed\n";
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
    cout << "arestas readed\n";
}