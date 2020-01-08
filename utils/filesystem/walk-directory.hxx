// Header file for various functions
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef WALK_DIRECTORY_H_
#define WALK_DIRECTORY_H_



std::string ReplaceAll(std::string string_value, std::string to_replace, std::string replace_with) {
    // Replace all occurrences of a character or string within a string.
    std::size_t char_pos;
    while ((char_pos = string_value.find(to_replace)) != std::string::npos) {
        string_value.replace(char_pos, 1, replace_with);
    }
    return string_value;
}



void WriteResults(std::string outpath, std::vector<std::string> &data_collection) {
    // Write vector to specified text file.
    
    std::ofstream outf(outpath);

    if (!outf) {
        std::cout << "Couldn't open file " << outpath << " for writing!" << std::endl;
    } else {
        for (const auto &element : data_collection) {
            outf << element << std::endl;
        }
    }
}

#endif
