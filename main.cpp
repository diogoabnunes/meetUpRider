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

    Dados *dados= new Dados();
    Menu menu;
    menu.showMenu(*dados);

    return 0;
}