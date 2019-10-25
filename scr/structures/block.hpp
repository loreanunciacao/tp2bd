#ifndef BLOCK_CLASS
#define BLOCK_CLASS

#include "record.hpp"
class Block{
    public:
        Record vet[2];                  //Size = 2 * record (2*1508 = 3016)
        char filler[1080];              //Size = 4096 - 3016 = 1080
    
        bool add_record(Record record){
            if(vet[0].empty()){
                vet[0] = record;
            }else if(vet[1].empty()){
                vet[1] = record;
            }else{
                return false;
            }
            return true;
        }
}
#endif