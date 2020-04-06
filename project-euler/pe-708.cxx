// Working on projecteuler.com question 708.
// URL: https://projecteuler.net/problem=708

#include <iostream>
#include <vector>

using uint = std::uint64_t;
using ivec = std::vector<uint>;
const char nl = '\n';
const uint zero = 0;


void decompose(uint n, ivec &v) {
    // Prime decomposition of a number.
    uint i = 2;
    while (n != 1) {
        while (n % i == zero) {
            v.push_back(i);
            n /= i;
        }
        ++i;
    }
}


void PrintSample(uint * n, ivec *v);

int main() {
    ivec v1;
    uint n1 = 90;
    decompose(n1, v1);
    PrintSample(&n1, &v1);
}


void PrintSample(uint * n, ivec *v) {
    std::cout << "The prime factors of " << *n << " are:" << nl;
    for (uint &i : *v) {
        std::cout << i << nl;
    }
}
