#ifndef BLOCK_CLASS
#define BLOCK_CLASS

#include "record.hpp"
class Block{
    public:
        Record vet[2];                  //Size = 2 * record (2*1508 = 3016)
        char filler[1080];              //Size = 4096 - 3016 = 1080
    
        Block(){
            Record rec = Record();
            vet[0] = rec;
            vet[1] = rec;
        };

        bool addRecord(Record record){
            
            if(vet[0].empty){
                vet[0] = record;
            }else if(vet[1].empty){
                vet[1] = record;
            }else{
                return false;
            }
            return true;
        };

        bool full(){
            return (!vet[0].empty && !vet[1].empty);
        };

        void print(){

            if(!vet[0].empty){
                cout << "1o registro do bloco" << endl << endl;
                vet[0].print();
            }
            else{
                cout << "1o registro do bloco está vazio" << endl << endl;
            }

            if(!vet[1].empty){
                cout << "2o registro do bloco" << endl << endl;
                vet[1].print();
            }
            else{
                cout << "2o registro do bloco está vazio" << endl << endl;
            }
        
        };
};
#endif