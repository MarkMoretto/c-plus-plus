

#ifndef H_VEC_PROD_
#define H_VEC_PROD_

// Calculate product of vector values. Or, array values if using C++11+

template <typename NUM> // Typename indicates usage of vector with numeric types
long xproduct(NUM& v) {
    // Start at 1 since 0 will return 0 after multiplication.
    long out = 1;

    for (auto &i : v) {
        out *= i;
    }
    
    return out;
}


#endif
