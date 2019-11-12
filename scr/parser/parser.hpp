
#ifndef PARSER_CLASS
#define PARSER_CLASS

#include <vector>
#include <string>
#include "../structures/record.hpp"

void copyToString(string str, char * attribute);
void setRecord(std::vector<std::string> row);
void readFile(char const* fileName);

#endif