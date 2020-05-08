#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->setBackground("../earth.jpg");
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    gv->addNode(0, 200, 200);
    gv->addNode(1, 400, 400);
    gv->addEdge(0, 0, 1, 1);
    gv->rearrange();
    cout << "Testing\n";
    getchar();
    return 0;
}
