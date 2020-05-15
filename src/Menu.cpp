#include "Menu.h"
#include "ReadFiles.h"

#include <iostream>

using namespace std;


Menu::Menu() {}

void Menu::showMenu(Dados &dados) {
    int option = -1;
    do {
        cout << "\nMeetUpRider\n\n";
        cout << "[1] Visualizar grafo\n";
        cout << "[2] Visualizar informação de uma pessoa específica\n";
        cout << "[3] Adicionar pessoa\n";
        cout << "[4] Remover pessoa\n";
        cout << "[5] Correr algoritmo\n";
        cout << "[6] Analisar complexidade\n";
        cout << "[0] Terminar programa\n";
        cin >> option;

        switch (option)
        {
            case 1:
                if (dados.visualizeGraph() != 0) {
                    cout << "Error visualizing graph\n";
                    exit(1);
                }
                break;

            case 2:
                //visualizeInfo();
                break;

            case 3:
                dados.addPessoa();
                break;

            case 4:
                //delPessoa();
                break;

            case 5:
                if (dados.runAlgorithm() != 0) {
                    cout << "Error running algorithm\n";
                    exit(1);
                }
                break;

            case 6:
                //analiseComplexity();
                break;

            case 0:
                break;

            default:
                option = -1;
                cout << "Choose a valid number\n";
                break;
        }
    } while (option != 0);
    // atualizar ficheiro users.txt caso haja alterações
}
