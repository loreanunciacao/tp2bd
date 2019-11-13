#ifndef HASHFILE_CLASS
#define HASHFILE_CLASS

#include <stdio.h>
#include <fstream>
#include "../structures/record.hpp"
#include "../structures/block.hpp"

using namespace std;

int calculateId(Record record);
void initFile();
void insertRecord(Record record);

#endif