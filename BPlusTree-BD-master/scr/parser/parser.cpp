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

    while (!fpointer.eof()){    //Haven't reached end-of-file

        vector<string> row;
        string word, nextWord, temp;
        
        while (getline(fpointer, word)){
            row.clear();
            stringstream s(word);

            while (getline(s, word, '"')){
                // cout <<"word " << word << endl;

                if (word.compare(";NULL")== 0){
                    // cout << "word null " << word << endl;
                    // cout << "temp(data) null " << temp << endl;
                    row.push_back(temp);
                    row.push_back("0");
                    // cout << "word depois null " << word << endl;
                }

                if(word != ";" && word.size() != 0 && word != ";;"){
                   temp.append(word);
                }else if(word == ";"){
                    cout << "temp final " << temp << endl;
                    row.push_back(temp);   //Assign next value to next attribute
                    temp = "";
                }else if(word == ";;"){
                    row.push_back("0");
                    temp = "";
                }
                // cout << "word " << word << endl;
            }   
                cout << endl;
            
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

