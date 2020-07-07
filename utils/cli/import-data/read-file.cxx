/**
 * Demo of `read-file.hpp`
 * 
 * For this demo, the local file is `input-large.txt`:
 * >>> g++ -o demo-reader read-file.hpp
 * >>> demo-reader input-large.txt
*/


#include <iostream>
#include "read-file.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cout << stderr << "Error: Please pass filepath argument." << nl;
        return -1;
    }

    // Create a string vector variable.
    sVEC vv;

    // Populate our vector with filepath passed as argument.
    read_to_vector(argv[1], vv);
    
    // Print results to terminal.
    for (auto &ln : vv) {
        std::cout << ln;
    }
    return 0;
}
