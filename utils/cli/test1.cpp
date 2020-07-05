
#include <iostream>

#include "replacer.hpp"

const char nl = '\n';

int main() {
    STRING sample_input = "1,2, 3|||6  &9";
    STRING scleaned = replacer(sample_input);
    std::cout << scleaned << nl;
}
