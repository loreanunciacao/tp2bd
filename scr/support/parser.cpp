#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include "../structures/record.hpp"
#include "../structures/block.hpp"
#include "../support/hashFile.hpp"

using namespace std;

void copyToString(string str, char * attribute){
    str.copy(attribute, str.size() + 1);
    attribute[str.size()] = '\0';
}

void setRecord(vector<string> &row){

    int idCurrent = stoi(row[0]);
    char tituloCurrent[TITULO_SIZE];
    int anoCurrent = stoi(row[2]);
    char autoresCurrent[AUTORES_SIZE];
    int citacoesCurrent = stoi(row[4]);
    char atualizacoesCurrent[ATUALIZACOES_SIZE];  
    char snippetCurrent[SNIPPET_SIZE];

    copyToString(row[1].c_str(), tituloCurrent);
    copyToString(row[3].c_str(), autoresCurrent);
    copyToString(row[5].c_str(), atualizacoesCurrent);

    //Trim the snippets bigger than 1024
    if(row.at(6).length() > 1023){
        row.at(6) = row.at(6).substr(0,1022);
    }
    copyToString(row[6].c_str(), snippetCurrent);
    
    Record record(idCurrent, tituloCurrent, anoCurrent, autoresCurrent, citacoesCurrent, atualizacoesCurrent, snippetCurrent);
    insertRecord(record);
}

void readFile(char const* fileName){
    fstream fpointer;
    fpointer.open(fileName, ios::in);
    int counter = 0;

    if(!fpointer.is_open()){
        cout<<"ERROR CANT OPEN THE FILE"<<endl;
        return;
    }
    vector<string> row;
    string word, line, temp;

    cout << "[PARSER] Lendo o arquivo e gerando os registros ..." << endl;
    cout << "[HASH] Inserindo no arquivo hash ..." << endl;
    while (!fpointer.eof()){    //Haven't reached end-of-file

        getline(fpointer, line);
        stringstream s(line);
        while (getline(s, word, '"')){
            // cout << "word" <<word << endl;

            if ((word.compare(";NULL") == 0) || (word.compare(";NULL") == 1 && word.at(0) == ';')){         //Treats NULL exception
                // cout << "a"<< endl;
                row.push_back(temp);
                temp = "0";
            }else if(word != ";" && word.size() != 0 && word != ";;"){          //Treats "" in title and normal input
                // cout << "b" << endl;
                temp.append(word);
            }else if(word == ";"){          //Add the word
                // cout << "c" << endl;
                row.push_back(temp);   
                temp = "";
            }else if(word == ";;"){         //Treats ;; exception
                // cout << "d" << endl;
                row.push_back(temp);
                row.push_back("0");
                temp = "";
            }
        }   
        if(row.size() < 6){
            continue;
        }
        // Add snippet to row (when snippet is NULL and NOT NULL)
        row.push_back(temp);
        
        setRecord(row);
        row.clear();
        temp = "";
        counter++;
        // cout << counter << " records" << endl;
        
    }
    cout << "[PARSER] TOTAL: "<< counter << " records" << endl;
    cout << "[PARSER] Leitura do arquivo finalizada" << endl;
    cout << "[HASH] Criação do arquivo hash com base nos registros finalizada" << endl;
}