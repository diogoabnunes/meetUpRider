#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "src/ReadFiles.h"



#include "src/Pessoa.h"
#include "src/Dados.h"
#include "src/Menu.h"

using namespace std;

int main() {
    Graph<Local> graph;
    initGraph(graph);
    vector<Condutor*> r;
    vector<Pessoa*> v=readUsers("../resources/users.txt",r);
    vector<Automovel *> c=readCarros("../resources/cars.txt");

    Dados *dados= new Dados(graph,r,v,c);

    Menu menu;
    menu.showMenu();

    return 0;
}