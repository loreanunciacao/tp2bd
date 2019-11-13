#include <stdio.h>
#include <fstream>
#include "../structures/record.hpp"
#include "../structures/block.hpp"

#define PRIME_NUMBER 187631
#define TAM_BUCKET 16384 // 4 * 4096
#define N_BLOCKS 786452
#define HASH_FILE_PATH "../hashfile.bin"

using namespace std;

int calculateId(Record record){
    return record.id % PRIME_NUMBER;
}

void initFile(){
    fstream fpointer;
    fpointer.open(HASH_FILE_PATH, ios::in);

    if(!fpointer.is_open()){
        cout << "[HASH] Gerando arquivo hash..." << endl;

        ofstream fbinaryfile;
        fbinaryfile.open(HASH_FILE_PATH, ios::binary);

        Block block;

        for (int i = 0; i < N_BLOCKS; i++){
            fbinaryfile.write((char*) &block, sizeof(Block));
        }
        fbinaryfile.close();
    }

}

void insertRecord(Record record){
    Block block;
    long bucket = calculateId(record)*TAM_BUCKET;
    int count;

    ifstream read(HASH_FILE_PATH, ios::binary);
    ofstream write(HASH_FILE_PATH, ios::binary | ios::app);

    if(read.is_open()){
        read.seekg(bucket, ios::beg);

        while (count < 4){
            read.read((char *) &block, sizeof(Block));

            if(!block.full()){
                block.addRecord(record);
                // block.print();
                
                write.seekp(bucket, ios::beg);
                write.write((char *) &block, sizeof(Block));
                break;
            }
            count++;
        }
        read.close();
    }else{
        cout<< "[HASH] Erro ao abrir arquivo hash" << endl;
    }
}