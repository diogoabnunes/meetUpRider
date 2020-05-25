#include <vector>
#include "src/Dados.h"
#include "src/Menu.h"
using namespace std;

int main() {
    Menu menu;
    Dados *dados = new Dados();

    int ret;
    do ret = menu.chooseMap(*dados);
    while(ret==-1);

    menu.showMenu(*dados);
    return 0;
}