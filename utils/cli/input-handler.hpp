/**
 * Input conversion
 * 
 * Base premise was intake of user-provided data and reformat for use in another process.
 * Input would be string type and output would be a vector of integers
*/

#pragma once

#ifndef INPUTCONV_H_
#define INPUTCONV_H_

#include <vector>
#include <string>
#include <sstream>

// Required from within this folder.
#include "cleaner.hpp"


typedef std::string STRING;
typedef std::vector<int> IntVec;
typedef std::vector<std::string> StrVec;
typedef std::stringstream StringStream;


StrVec string_split(STRING s, STRING delim = " ") {
    StrVec tmps;

    // Clean-up input string with regex.
    STRING only_ints_ptrn = "([\\D]+)";
    STRING sclean = replacer(s, only_ints_ptrn, delim);

    auto start = 0U;
    auto end = sclean.find(delim);

    while (end != STRING::npos) {
        tmps.push_back(sclean.substr(start, end - start));
        start = end + delim.length();
        end = sclean.find(delim, start);
    }
    tmps.push_back(sclean.substr(start, end));
    return tmps;
}


IntVec string_to_int(STRING sinput) {
    IntVec outv;
    StringStream ss;
    // Convert to integer.

    StrVec sv = string_split(sinput);

    int ii;
    for (auto &c : sv) {
        ss << c;
        ss >> ii;
        outv.push_back(ii);
    }
    return outv;
}

#endif
