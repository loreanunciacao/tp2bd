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
        char tituloCurrent[TITULO_SIZE];
        int anoCurrent = stoi(row[2]);
        char autoresCurrent[AUTORES_SIZE];
        int citacoesCurrent = stoi(row[4]);
        char atualizacoesCurrent[ATUALIZACOES_SIZE];  
        char snippetCurrent[SNIPPET_SIZE];

        strcpy(tituloCurrent, row[1].c_str());
        strcpy(autoresCurrent, row[3].c_str());
        strcpy(atualizacoesCurrent, row[5].c_str());
        strcpy(snippetCurrent, row[6].c_str());

        Record record = Record(idCurrent, tituloCurrent, anoCurrent, autoresCurrent, citacoesCurrent, atualizacoesCurrent, snippetCurrent);
        record.print();        
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

                    if(attribute == ""){
                        getline(getline(s, temp, '"'), attribute, '"');
                        cout << "att: " << attribute << endl; 
                    }
                    if(temp == ";;"){
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

            // cout << "Id: " << row[0] << endl;
            // cout << "Titulo: " << row[1] << endl;
            // cout << "Ano: " << row[2] << endl;
            // cout << "Autores: " << row[3] << endl;
            // cout << "Citações: " << row[4] << endl;
            // cout << "Atualizações: " << row[5] << endl;
            // cout << "Snippet: " << row[6] << endl;
            // cout << endl;
            
            // vet.push_back(setRecord(row));      //Add new record to vector of records
        }
    }
}

