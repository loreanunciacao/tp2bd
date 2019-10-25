
#ifndef PARSER_CLASS
#define PARSER_CLASS

#include <vector>
#include <string>
#include "../structures/record.hpp"

void copyToString(string str, char * attribute);
void read_line(fstream fpointer);
void setRecord(std::vector<std::string> row);
void read_file();

#endif