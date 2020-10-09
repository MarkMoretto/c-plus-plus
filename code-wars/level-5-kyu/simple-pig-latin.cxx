/***************************************************************
Topic: Code Wars
Problem: Simple Pig Latin
Date: 2020-10-08
URL: https://www.codewars.com/kata/520b9d2ad5c005041100000f

Compilation -
>>>g++ -Wall -Wextra -o spl simple-pig-latin.cpp
***************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <regex>


using S = std::string;
using svec = std::vector<S>;

std::regex nospaces("[^\\s]+");
std::regex isalphnum("[\\w]+");


/**
 * Got lazy, so this is a function to trim excess whitespace from
 * the right-side of a string.  Probably could use regex for a similar result.
*/
const char* ws = " \t\n\r\f\v";

inline std::string& rtrim(std::string& s, const char* t = ws) {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}


/**
 * Provided function to complete.
*/
std::string pig_it(std::string str) {
    // Output string variable.
    S output;
    
    std::smatch m;

    // match everything but one or more whitespace characters
    // Continue matching until exhausted.
    while (std::regex_search(str, m, nospaces)) {
    
        // Populate vector with matched result.
        svec sv(m.begin(), m.end());

        // Iterate vector
        for (S q : sv) {
            // Check if word is alphanumeric.
            if (std::regex_match(q, isalphnum)) {
                // Variable for conversion of char& to std::string.
                S front;
                
                // Grab firs character in string.
                char & f = q.at(0);
                
                // Set to temp variable.
                front.push_back(f);
                
                // Set another string to the word, starting with the second character.
                S shortq = q.substr(1, q.size()-1);

                // Add truncated string, first chracter, and 'ay' to output variable.
                output += shortq + front + "ay";
            } else {
                // If not alphanumeric, add value to output sans modification.
                output += q;
            }
        }
        // Add whitspace between words.
        output += " ";
        
        // Set string to next match result
        str = m.suffix().str();
        
        // Clear vector values.
        sv.clear();
    }
    // Return trimmed string.
    return rtrim(output);
}


int main() {
    // Test phrases.
    S s1 = "This is my string"; // hisTay siay ymay tringsay
    S s2 = "Pig latin is cool"; // igPay atinlay siay oolcay
    S s3 = "Acta est fabula"; // ctaAay steay abulafay
    S s4 = "Hello world !"; // elloHay orldway !

    svec samples{s1, s2, s3, s4};

    for (S el : samples) {
        S res = pig_it(el);
        std::cout << res << std::endl;
    }

    // S res = pig_it(s1);
    // std::cout << res << std::endl;


    
    return 0;

}
