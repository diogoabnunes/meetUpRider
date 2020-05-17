#include <vector>
#include "src/Dados.h"
#include "src/Menu.h"
using namespace std;

int main() {
    Dados *dados = new Dados();
    Menu menu;
    menu.showMenu(*dados);
    // atualizar ficheiros se necessário
    return 0;
}