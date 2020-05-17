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
        cout << "[7] Mudar grafo\n";
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

            case 7:
                chooseMap(dados);
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

void Menu::chooseMap(Dados & dados) {
    int option;
    string edges,nodes;

    cout << "\nMapas\n\n";
    cout << "[1] 16x16\n";
    cout << "[2] Braga\n";
    cout << "[3] Lisboa\n";
    cout << "[4] Porto\n";
    cout << "[5] Portugal\n";
    cout << "[6] 8x8\n";
    cout << "[0] Back\n";
    cin >> option;

    switch(option) {
        case 1:
            nodes="../mapas/GridGraphs/16x16/nodes.txt";
            edges="../mapas/GridGraphs/16x16/edges.txt";
            dados.changeGraph(nodes,edges,false);
            break;
        case 2:
            nodes="../mapas/PortugalMaps/Braga/nodes_x_y_braga.txt";
            edges="../mapas/PortugalMaps/Braga/edges_braga.txt";
            dados.changeGraph(nodes,edges,true);
            break;
        case 3:
            nodes="../mapas/PortugalMaps/Lisboa/nodes_x_y_lisboa.txt";
            edges="../mapas/PortugalMaps/Lisboa/edges_lisboa.txt";
            dados.changeGraph(nodes,edges,true);
            break;
        case 4:
            nodes="../mapas/PortugalMaps/Porto/nodes_x_y_porto.txt";
            edges="../mapas/PortugalMaps/Porto/edges_porto.txt";
            dados.changeGraph(nodes,edges,true);
            break;
        case 5:
            nodes="../mapas/PortugalMaps/Portugal/nodes_x_y_portugal.txt";
            edges="../mapas/PortugalMaps/Portugal/edges_portugal.txt";
            dados.changeGraph(nodes,edges,true);
            break;
        case 6:
            nodes="../mapas/GridGraphs/8x8/nodes.txt";
            edges="../mapas/GridGraphs/8x8/edges.txt";
            dados.changeGraph(nodes,edges,false);
        case 0:
            break;
        default:
            cout << "Numero invalido\n";
            break;
    }
}
