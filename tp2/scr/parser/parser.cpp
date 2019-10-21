#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../structures/record.hpp"

using namespace std;
#define FILE_PATH "../test.csv" //Path related to main.cpp

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
        }
        cout << "Id: " << row[0] << endl;
        cout << "Titulo: " << row[1] << endl;
        cout << "Ano: " << row[2] << endl;
        cout << "Autores: " << row[3] << endl;
        cout << "Citações: " << row[4] << endl;
        cout << "Atualizações: " << row[5] << endl;
        cout << "Snippet: " << row[6] << endl;
        cout << endl;

    }
}