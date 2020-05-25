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
        cout << "[4] Visualizar informacao de pessoas\n";
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
                if (dados.visualizeGraph() != 0) exit(3);
                break;

            case 4:
                if (dados.visualizeInfo() != 0) exit(4);
                break;

            case 5:
                if (dados.addPessoa() != 0) exit(5);
                break;

            case 6:
                if (dados.elimPessoa() != 0) exit(6);
                break;

            case 7:
                if (dados.analiseComplexity() != 0) exit(7);
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
    cout << "[1] Porto\n";
    cout << "[2] Porto (conexo)\n";
    cout << "[3] Penafiel\n";
    cout << "[4] Penafiel (conexo)\n";
    cout << "[5] Espinho\n";
    cout << "[6] Espinho (conexo)\n";
    cout << "[7] GridGraph 4x4\n";
    cout << "[8] GridGraph 8x8\n";
    cout << "[9] GridGraph 16x16\n";
    cout << "[10] Grid 10x10\n";
    cout << "[0] Voltar\n";
    cin >> option;

    switch(option) {
        case 1:
            dados.changeGraph("../mapas/PortugalMaps/Porto/porto_full_nodes_xy.txt",
                    "../mapas/PortugalMaps/Porto/porto_full_edges.txt", true);
            break;
        case 2:
            dados.changeGraph("../mapas/PortugalMaps/Porto/porto_strong_nodes_xy.txt",
                              "../mapas/PortugalMaps/Porto/porto_strong_edges.txt", true);
            break;
        case 3:
            dados.changeGraph("../mapas/PortugalMaps/Penafiel/penafiel_full_nodes_xy.txt",
                              "../mapas/PortugalMaps/Penafiel/penafiel_full_edges.txt", true);
            break;
        case 4:
            dados.changeGraph("../mapas/PortugalMaps/Penafiel/penafiel_strong_nodes_xy.txt",
                              "../mapas/PortugalMaps/Penafiel/penafiel_strong_edges.txt", true);
            break;
        case 5:
            dados.changeGraph("../mapas/PortugalMaps/Espinho/espinho_full_nodes_xy.txt",
                              "../mapas/PortugalMaps/Espinho/espinho_full_edges.txt", true);
            break;
        case 6:
            dados.changeGraph("../mapas/PortugalMaps/Espinho/espinho_strong_nodes_xy.txt",
                              "../mapas/PortugalMaps/Espinho/espinho_strong_edges.txt", true);
            break;
        case 7:
            dados.changeGraph("../mapas/GridGraphs/4x4/nodes.txt",
                              "../mapas/GridGraphs/4x4/edges.txt", false);
            break;
        case 8:
            dados.changeGraph("../mapas/GridGraphs/8x8/nodes.txt",
                              "../mapas/GridGraphs/8x8/edges.txt", false);
            break;
        case 9:
            dados.changeGraph("../mapas/GridGraphs/16x16/nodes.txt",
                              "../mapas/GridGraphs/16x16/edges.txt", false);
            return 0;
        case 10:
            dados.changeGraph("../mapas/GridGraphs/Test/nodes.txt",
                                "../mapas/GridGraphs/Test/edges.txt", true);
            return 0;
        case 0:
            return -1;
        default:
            cout << "Numero invalido\n";
            return -1;
    }
}
