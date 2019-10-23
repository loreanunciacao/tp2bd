
#ifndef PARSER_CLASS
#define PARSER_CLASS

#include <vector>
#include <string>
#include "../structures/record.hpp"

Record* read_line(fstream fpointer);
Record* setRecord(std::vector<std::string> row);
void read_file();

#endif