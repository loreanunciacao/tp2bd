#ifndef RECORD_CLASS
#define RECORD_CLASS

#define TITULO_SIZE 300
#define AUTORES_SIZE 150
#define ATUALIZACOES_SIZE 20
#define SNIPPET_SIZE 1024

#include <iostream>
#include <cstring>
using namespace std;

class Record{
    public:        
        int id;
        char titulo[TITULO_SIZE];
        int ano;
        char autores[AUTORES_SIZE];
        int citacoes;
        char atualizacoes[ATUALIZACOES_SIZE];  //XX-XX-XXXX XX:XX:XX
        char snippet[SNIPPET_SIZE];
        bool empty;

        Record(){
            empty = true;
        };
        
        Record(int id, char titulo[TITULO_SIZE], int ano, char autores[AUTORES_SIZE], int citacoes, char atualizacoes[ATUALIZACOES_SIZE], char snippet[SNIPPET_SIZE]){
            
            this->id = id;
            this->ano = ano;
            this->citacoes = citacoes;

            strcpy(this->titulo, titulo);
            strcpy(this->autores, autores);
            strcpy(this->atualizacoes, atualizacoes);
            strcpy(this->snippet, snippet);
            empty = false;

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