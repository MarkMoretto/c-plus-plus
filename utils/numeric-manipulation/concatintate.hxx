/*
Tenplate to join two numbers in char-like fashion.

Simple example:

#include <iostream>
#include "concatintate.hxx"

int main() {

    int a = 2, b = 9;
    
    int res = Concat<int>(a, b);
    
    std::cout << "The combination of " << a << " and " << b << " is: " << res << "." << std::endl;
}


Output: The combination of 2 and 9 is 29.

*/


#ifndef CONCAT_INT_UTIL_H_
#define CONCAT_INT_UTIL_H_

#include <iostream>


template<typename T>
T Concat(T& x, T& y) {
    int factor = 1;
    while (factor <= y) {
        factor *= 10;
    }
    return factor * x + y;
}

#endif
