#include <iostream>
#include "support/parser.hpp"
#include "support/hashFile.hpp"

int main(int argc, char const* argv[]){

    initFile();
    readFile(argv[1]);

    return 0;
}