#ifndef RECORD_CLASS
#define RECORD_CLASS

#define MAX_TITULO 300
#define MAX_AUTORES 150
#define MAX_ATUALIZACOES 19
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
};

// void print_record(Record record){

//     cout << "Id: " << record.id << endl;
//     cout << "Titulo: " << record.titulo << endl;
//     cout << "Ano: " << record.ano << endl;
//     cout << "Autores: " << record.autores << endl;
//     cout << "Citações: " << record.citacoes << endl;
//     cout << "Atualizações: " << record.atualizacoes << endl;
//     cout << "Snippet: " << record.snippet << endl;
//     cout << endl;
// }
#endif