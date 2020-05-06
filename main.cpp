#include <iostream>
#include "graphviewer.h"

using namespace std;

int main() {

    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->addNode(0, 200, 200);
    gv->addNode(1, 400, 400);
    gv->addEdge(0, 0, 1, 1);
    cout << "Testing\n";

    return 0;
}
