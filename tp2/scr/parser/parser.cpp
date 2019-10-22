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
        int idCurrent;
        char tituloCurrent[MAX_TITULO];
        int anoCurrent;
        char autoresCurrent[MAX_AUTORES];
        int citacoesCurrent;
        char atualizacoesCurrent[MAX_ATUALIZACOES];  
        char snippetCurrent[MAX_SNIPPET];

        idCurrent = stoi(row[0]);
        strcpy(tituloCurrent, row[1].c_str());

        if(!(row[2] == "NULL")){       //Check if attribute is null
            anoCurrent = stoi(row[2]);
        }
        
        strcpy(autoresCurrent, row[3].c_str());

        if(!(row[4] == "NULL")){       //Check if attribute is null
            citacoesCurrent = stoi(row[4]);
        }

        strcpy(atualizacoesCurrent, row[5].c_str());
        strcpy(snippetCurrent, row[6].c_str());

        Record current;
        // current = Record(idCurrent, tituloCurrent, anoCurrent, autoresCurrent, citacoesCurrent, atualizacoesCurrent, snippetCurrent);
        // print_record(current);
        return current;

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
                    if(temp == ";;"){
                        row.push_back("NULL");      //Assign null value to null attribute
                        row.push_back(attribute);   //Assign next value to next attribute
                    }else{
                        row.push_back(attribute);
                    }
                    
                }
            }

            vet.push_back(setRecord(row));      //Add new record to vector of records
        
            // cout << "Id: " << idCurrent << endl;
            // cout << "Titulo: " << tituloCurrent << endl;
            // cout << "Ano: " << anoCurrent << endl;
            // cout << "Autores: " << autoresCurrent << endl;
            // cout << "Citações: " << citacoesCurrent << endl;
            // cout << "Atualizações: " << atualizacoesCurrent << endl;
            // cout << "Snippet: " << snippetCurrent << endl;
            // cout << endl;
            
            // cout << "Id: " << row[0] << endl;
            // cout << "Titulo: " << row[1] << endl;
            // cout << "Ano: " << row[2] << endl;
            // cout << "Autores: " << row[3] << endl;
            // cout << "Citações: " << row[4] << endl;
            // cout << "Atualizações: " << row[5] << endl;
            // cout << "Snippet: " << row[6] << endl;
            // cout << endl;
        }
    }
}

