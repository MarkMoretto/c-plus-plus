/**
 * CUDA summation exercise.
 * URL: https://devblogs.nvidia.com/even-easier-introduction-cuda/
 * 
 * Reworked to use vectors vs. arrays.
*/

#include <iostream>
#include <math.h>   // fabs, fmax
#include <vector>   // std::vector
#include <numeric>  // std::accumulate

using fvec = std::vector<float>;
const char nl = '\n';

void populate_vec(int num, float* val1, float* val2, fvec &outV) {
    *val1 += *val2;
    for (int i = 0; i < num; i++) {
        outV.push_back(*val1);
    }
}

float error_check(fvec &v) {
    float currentMax = 0.0f;
    for (auto &i : v) {
        currentMax = fmax(currentMax, fabs(i - 3.0f));
    }
    return currentMax;
}

int main() {
    int N = 1<<20;
    float fsum; // For summation of all vector values.
    fvec resV;
    resV.reserve(N);

    // Values to add.
    float x = 1.0f;
    float y = 2.0f;

    // Making pointers because why not.
    float * xp = &x;
    float * yp = &y;
    
    // Populate our vector with N values of x + y.
    populate_vec(N, xp, yp, resV);

    // Sum all values of vector starting from 0.
    fsum = std::accumulate(resV.begin(), resV.end(), 0.0f);

    // Write results to prompt.
    // Set precision value first.
    std::cout.precision(10);
    std::cout << "The sum of all values is: " << fsum << nl;

    // Check for any errors
    float err_ = error_check(resV);
    std::cout.precision(10);
    std::cout << "Max error found: " << err_ << nl;

    return 0;
}


void test_print(fvec & v) {
    std::cout << "The values in resV are:" << nl;
    std::cout.precision(2);
    for (auto &i : v) {
        std::cout << i << nl;
    }
}
