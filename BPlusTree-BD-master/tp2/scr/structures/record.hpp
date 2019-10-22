#ifndef RECORD_CLASS
#define RECORD_CLASS

#define MAX_TITULO 300
#define MAX_AUTORES 150
#define MAX_ATUALIZACOES 20
#define MAX_SNIPPET 1024

#include <iostream>
#include <cstring>
using namespace std;

class Record{
    public:        
        int id;
        char titulo[MAX_TITULO];
        int ano;
        char autores[MAX_AUTORES];
        int citacoes;
        char atualizacoes[MAX_ATUALIZACOES];  //XX-XX-XXXX XX:XX:XX
        char snippet[MAX_SNIPPET];

        Record(int id, char titulo[MAX_TITULO], int ano, char autores[MAX_AUTORES], int citacoes, char atualizacoes[MAX_ATUALIZACOES], char snippet[MAX_SNIPPET]){
            
            this->id = id;
            this->ano = ano;
            this->citacoes = citacoes;

            memcpy(this->titulo, titulo, MAX_TITULO);
            memcpy(this->autores, autores, MAX_AUTORES);
            memcpy(this->atualizacoes, atualizacoes, MAX_ATUALIZACOES);
            memcpy(this->snippet, snippet, MAX_SNIPPET);

        };

        void print(){
            cout << "Id: " << id << endl;
            cout << "Titulo: " << titulo << endl;
            cout << "Ano: " << ano << endl;
            cout << "Autores: " << autores << endl;
            cout << "Citações: " << citacoes << endl;
            cout << "Atualizações: " << atualizacoes << endl;
            cout << "Snippet: " << snippet << endl;
            cout << endl;
        };
};
#endif