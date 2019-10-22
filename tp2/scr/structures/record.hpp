#ifndef RECORD_CLASS
#define RECORD_CLASS

#define MAX_TITULO 300
#define MAX_AUTORES 150
#define MAX_ATUALIZACOES 19
#define MAX_SNIPPET 1024

class Record{
    public:
        Record(int id, char titulo[MAX_TITULO], int ano, char autores[MAX_AUTORES], int citacoes, char atualizacoes[MAX_ATUALIZACOES], char snippet[MAX_SNIPPET]);
        Record();
        
        int id;
        char titulo[MAX_TITULO];
        int ano;
        char autores[MAX_AUTORES];
        int citacoes;
        char atualizacoes[MAX_ATUALIZACOES];  //XX-XX-XXXX XX:XX:XX
        char snippet[MAX_SNIPPET];

};

void print_record(Record record);

#endif