//
// Created by clara on 08/05/2020.
//

#include "ReadFiles.h"
#include "Passageiro.h"

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
            if(l[0]=="P"){

                Pessoa* p=new Passageiro(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada);
                pessoas.push_back(p);
            }
            else{
                Pessoa* c=new Condutor(stoi(l[1]),stoi(l[2]),stoi(l[3]),partida,chegada,stoi(l[6]));
                pessoas.push_back(c);
            }
        }
    }
    file.close();
    return pessoas;
}



vector<Automovel> readCarros(string filename){
    vector<Automovel>carros;
    ifstream file;
    file.open(filename);
    if(!file.fail()){
        string line;
        while (!file.eof()){
            getline(file,line);
            auto l=split(line,";");
            carros.push_back(Automovel(stoi(l[0]),stoi(l[1])));

        }
    }
    file.close();
    return carros;

}