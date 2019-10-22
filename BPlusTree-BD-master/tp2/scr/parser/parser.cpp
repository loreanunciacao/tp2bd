#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include "../structures/record.hpp"

using namespace std;
#define FILE_PATH "../test.csv" //Path related to main.cpp

Record setRecord(vector<string> row){
    try{
        int idCurrent = stoi(row[0]);
        char tituloCurrent[MAX_TITULO];
        int anoCurrent = stoi(row[2]);
        char autoresCurrent[MAX_AUTORES];
        int citacoesCurrent = stoi(row[4]);
        char atualizacoesCurrent[MAX_ATUALIZACOES];  
        char snippetCurrent[MAX_SNIPPET];

        strcpy(tituloCurrent, row[1].c_str());
        strcpy(autoresCurrent, row[3].c_str());
        strcpy(atualizacoesCurrent, row[5].c_str());
        strcpy(snippetCurrent, row[6].c_str());

        Record record = Record(idCurrent, tituloCurrent, anoCurrent, autoresCurrent, citacoesCurrent, atualizacoesCurrent, snippetCurrent);
        // record.print();        
        return record;

    }catch(char *e){
        throw e;
    }
}

void read_file(){
    fstream fpointer;

    fpointer.open(FILE_PATH, ios::in);

    if(!fpointer.is_open()){
        cout<<"ERROR CANT OPEN THE FILE"<<endl;
    }

    vector<Record> vet;

    while (!fpointer.eof()){    //Haven't reached end-of-file

        vector<string> row;
        string line, attribute, temp;
        
        while (getline(fpointer, line)){
            row.clear();
            stringstream s(line);

            if (line.find(';')){
                while (getline(getline(s, temp, '"'), attribute, '"')){     //Remove "" of attributes
                    if(temp == ";;" || temp == ";NULL"){
                        row.push_back("0");      //Assign null value to null attribute
                        row.push_back(attribute);   //Assign next value to next attribute
                    }else{
                        row.push_back(attribute);
                    }
                }    
                getline(s,temp,'N');
                if(temp==";NULL"){       //Assign null if attribute has NULL in line
                    row.push_back("0");
                }   
            }
            vet.push_back(setRecord(row));      //Add new record to vector of records
        }
    }
}

