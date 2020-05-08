//
// Created by clara on 08/05/2020.
//

#include "ReadFiles.h"

vector<Pessoa *> readUsers(string filename) {
    vector<Pessoa *>pessoas;
    ifstream file;
    file.open(filename);
    if(!file.fail()){
        string line;
        while (!file.eof()){
            getline(file,line);
            auto l=split(line,";");
            Time partida(l[4]);
            Time chegada(l[5]);
            if(l[0]=="C"){

                Pessoa p(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada);
                pessoas.push_back(&p);
            }
            else{
                Condutor c(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada,stoi(l[6]));
                pessoas.push_back(&c);
            }
        }
    }
}
