
/**
 * Small header file for removing duplicate values from a vector.
*/


#ifndef H_VEC_UTILS_
#define H_VEC_UTILS_

#include <vector>
#include <algorithm>


// Remove duplicate values from vector
template <typename T>
void remove_duplicates(T& v) {
    // Sort values
    std::sort(v.begin(), v.end());

    // Reduce duplicates
    auto uniq = std::unique(v.begin(), v.end());

    // Remove allocated space from the resulting vector, if any.
    v.erase(uniq, v.end());
}


#endif
