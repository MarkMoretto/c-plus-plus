/**
 * Using regular expressions to reformat command-line input strings
 * 
 * Example input
 * >>> 1,2, 3|||6  &9
 * 
 * Example output:
 * >>> 1 2 3 6 9
*/

#ifndef INPUT_CLEANER_H_
#define INPUT_CLEANER_H_

#include <iostream>
#include <string>
#include <regex>

typedef std::string STRING;


STRING replacer(STRING sline, STRING pattern = "([\\D]+)", STRING replacement = " ") {
    STRING out;
    
    // Init regex constructor with pattern
    std::regex ptrn (pattern);
    
    out = std::regex_replace(sline, ptrn, replacement);
    
    return out;
}

#endif
