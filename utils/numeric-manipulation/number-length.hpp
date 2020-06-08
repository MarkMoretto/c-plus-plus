/***************************************************
Header for counting number of digits in a positive integer value.

** Template allows for data type flexibility

TODO:
    * modify to check for negative values
    * modify to handle floating-point values


############################################################
Example usage:

#include <iostream>
#include "number-length.hpp"

int main() {
    int testnum = 454545;
    unsigned res;
    res = digit_count(testnum);
    std::cout << "The number if digits in " << usr_num << " is " << res << nl;

}
############################################################
***************************************************/

#pragma once

#ifndef _H_PE_PROB_25_
#define _H_PE_PROB_25_


const char nl = '\n';

const int base10 = 10;

// Count number of digits in an integer
// General base should be 10
template<typename T>
T digit_count(T n) {

    unsigned int digit_count = 0;

    do {
        ++digit_count;
        n /= base10;
    } while (n);

    return digit_count;
}



#endif
