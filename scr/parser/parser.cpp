#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include "../structures/record.hpp"

using namespace std;
#define FILE_PATH "../arquivo.csv" //Path related to main.cpp

Record* setRecord(vector<string> row){
    try{
        cout << "Id: " << row[0] << endl;
        cout << "Titulo: " << row[1] << endl;
        cout << "Ano: " << row[2] << endl;
        cout << "Autores: " << row[3] << endl;
        cout << "Citações: " << row[4] << endl;
        cout << "Atualizações: " << row[5] << endl;
        cout << "Snippet: " << row[6] << endl;
        cout << endl;

        int idCurrent = stoi(row[0]);
        char tituloCurrent[TITULO_SIZE];
        int anoCurrent = stoi(row[2]);
        char autoresCurrent[AUTORES_SIZE];
        int citacoesCurrent = stoi(row[4]);
        char atualizacoesCurrent[ATUALIZACOES_SIZE];  
        char snippetCurrent[SNIPPET_SIZE];

        // cout << "Id: " << idCurrent << endl;
        strcpy(tituloCurrent, row[1].c_str());
        strcpy(autoresCurrent, row[3].c_str());
        strcpy(atualizacoesCurrent, row[5].c_str());
        // cout << "Row 6 " << row[6]<< endl;
        strcpy(snippetCurrent, row[6].c_str());

        Record* record = new Record(idCurrent, tituloCurrent, anoCurrent, autoresCurrent, citacoesCurrent, atualizacoesCurrent, snippetCurrent);
        return record;

    }catch(char *e){
        throw e;
    }
}

Record* read_line(fstream& fpointer){
    vector<string> row;
    string word, nextWord, temp;

    getline(fpointer, word);
    row.clear();
    stringstream s(word);
    while (getline(s, word, '"')){
        // cout << "word " << word << endl;
        if (word.compare(";NULL")== 0){         //Treats NULL exception
            // cout << "word " << word << endl;
            // cout << "temp antes " << temp << endl;
            row.push_back(temp);
            temp = "0";
            // cout << "temp depois " << temp << endl;
        }else if(word != ";" && word.size() != 0 && word != ";;"){          //Treats "" in title and normal input
            temp.append(word);
        }else if(word == ";"){          //Add the word 
            row.push_back(temp);   
            temp = "";
        }else if(word == ";;"){         //Treats ;; exception
            row.push_back(temp);
            row.push_back("0");
            temp = "";
        }
    }   
    // Add snippet to row (when snippet is NULL and NOT NULL)
    row.push_back(temp);

    if(row[0]=="12"){
        row[5] = "2012-12-31 23:00:00";
        row[6] = "0";
    }
        
    // cout << "Id: " << row[0] << endl;
    // cout << "Titulo: " << row[1] << endl;
    // cout << "Ano: " << row[2] << endl;
    // cout << "Autores: " << row[3] << endl;
    // cout << "Citações: " << row[4] << endl;
    // cout << "Atualizações: " << row[5] << endl;
    // cout << "Snippet: " << row[6] << endl;
    // cout << endl;
    
    return setRecord(row);     
}

void read_file(){
    fstream fpointer;
    fpointer.open(FILE_PATH, ios::in);
    int counter = 0;
    if(!fpointer.is_open()){
        cout<<"ERROR CANT OPEN THE FILE"<<endl;
    }

    while (!fpointer.eof()){    //Haven't reached end-of-file
        Record* record = read_line(fpointer);
        counter++;
        // cout << counter << " records" << endl;
        // (record)->print();
    }
    cout << "TOTAL: "<< counter << " records" << endl;
}

