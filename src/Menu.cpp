#include "Menu.h"
#include "ReadFiles.h"

#include <iostream>

using namespace std;


Menu::Menu() {}

void Menu::showMenu(Dados &dados) {
    int option = -1;
    do {
        cout << "\nMeetUpRider\n\n";
        cout << "[1] Escolher Localizacao\n";
        cout << "[2] Correr algoritmo\n";
        cout << "[3] Visualizar grafo\n";
        cout << "[4] Visualizar informacao de uma pessoa especifica\n";
        cout << "[5] Adicionar pessoa\n";
        cout << "[6] Remover pessoa\n";
        cout << "[7] Analisar complexidade\n";
        cout << "[0] Terminar programa\n";
        cin >> option;

        switch (option)
        {
            case 1:
                chooseMap(dados);
                break;

            case 2:
                if (dados.runAlgorithm() != 0) exit(2);
                break;

            case 3:
                if (dados.visualizeGraph() != 0) exit(1);
                break;

            case 4:
                //if (dados.visualizeInfo() != 0) exit(4);
                break;

            case 5:
                if (dados.addPessoa() != 0) exit(5);
                break;

            case 6:
                //if (dados.delPessoa() != 0) exit(6);
                break;

            case 7:
                //if (dados.analiseComplexity() != 0) exit(7);
                break;

            case 0:
                break;

            default:
                option = -1;
                cout << "Numero invalido\n";
                break;
        }
    } while (option != 0);
}

int Menu::chooseMap(Dados &dados) {
    int option;
    string edges,nodes;

    cout << "\nMapas\n\n";
    cout << "[1] Portugal\n";
    cout << "[2] Aveiro\n";
    cout << "[3] Braga\n";
    cout << "[4] Coimbra\n";
    cout << "[5] Ermesinde\n";
    cout << "[6] Fafe\n";
    cout << "[7] Gondomar\n";
    cout << "[8] Lisboa\n";
    cout << "[9] Maia\n";
    cout << "[10] Porto\n";
    cout << "[11] Viseu\n";
    cout << "[12] GridGraph 4x4\n";
    cout << "[13] GridGraph 8x8\n";
    cout << "[14] GridGraph 16x16\n";
    cout << "[0] Voltar\n";
    cin >> option;

    switch(option) {
        case 1:
            dados.changeGraph("../mapas/PortugalMaps/Portugal/nodes_x_y_portugal.txt",
                    "../mapas/PortugalMaps/Portugal/edges_portugal.txt", true);
            break;
        case 2:
            dados.changeGraph("../mapas/PortugalMaps/Aveiro/nodes_x_y_aveiro.txt",
                              "../mapas/PortugalMaps/Aveiro/edges_aveiro.txt", true);
            break;
        case 3:
            dados.changeGraph("../mapas/PortugalMaps/Braga/nodes_x_y_braga.txt",
                              "../mapas/PortugalMaps/Braga/edges_braga.txt", true);
            break;
        case 4:
            dados.changeGraph("../mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt",
                              "../mapas/PortugalMaps/Coimbra/edges_coimbra.txt", true);
            break;
        case 5:
            dados.changeGraph("../mapas/PortugalMaps/Ermesinde/nodes_x_y_ermesinde.txt",
                              "../mapas/PortugalMaps/Ermesinde/edges_ermesinde.txt", true);
            break;
        case 6:
            dados.changeGraph("../mapas/PortugalMaps/Fafe/nodes_x_y_fafe.txt",
                              "../mapas/PortugalMaps/Fafe/edges_fafe.txt", true);
            break;
        case 7:
            dados.changeGraph("../mapas/PortugalMaps/Gondomar/nodes_x_y_gondomar.txt",
                              "../mapas/PortugalMaps/Gondomar/edges_gondomar.txt", true);
            break;
        case 8:
            dados.changeGraph("../mapas/PortugalMaps/Lisboa/nodes_x_y_lisboa.txt",
                              "../mapas/PortugalMaps/Lisboa/edges_lisboa.txt", true);
            break;
        case 9:
            dados.changeGraph("../mapas/PortugalMaps/Maia/nodes_x_y_maia.txt",
                              "../mapas/PortugalMaps/Maia/edges_maia.txt", true);
            break;
        case 10:
            dados.changeGraph("../mapas/PortugalMaps/Porto/nodes_x_y_porto.txt",
                              "../mapas/PortugalMaps/Porto/edges_porto.txt", true);
            break;
        case 11:
            dados.changeGraph("../mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt",
                              "../mapas/PortugalMaps/Viseu/edges_viseu.txt", true);
            break;
        case 12:
            dados.changeGraph("../mapas/GridGraphs/4x4/nodes.txt",
                              "../mapas/GridGraphs/4x4/edges.txt", false);
            break;
        case 13:
            dados.changeGraph("../mapas/GridGraphs/8x8/nodes.txt",
                              "../mapas/GridGraphs/8x8/edges.txt", false);
            break;
        case 14:
            dados.changeGraph("../mapas/GridGraphs/16x16/nodes.txt",
                              "../mapas/GridGraphs/16x16/edges.txt", false);
            break;
        case 0:
            return -1;
        default:
            cout << "Numero invalido\n";
            break;
    }
}
