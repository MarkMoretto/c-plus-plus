/*
 * Summary: Codility Binary Zeroes
 * 
 * See: https://app.codility.com/demo/results/trainingAV67D4-VP5/
 * 
 * Compilation with gcc:
 *      >>> g++ --std=c++17 -Wall -Wextra -o binarygap binary-gap.cxx
*/



#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <sstream>      // std::ostringstream

#include "binary-gap.hxx"



/*
Summary:Converts unsigned integer to binary string

Note: Requires string reference.
 
Returns: nothing
*/
void DecimalToBinaryString(UINT N, S & outstr) {
    UINT * pN = &N;

    UIVEC uv;
    std::ostringstream oss;

    while (*pN > 0) {
        uv.push_back(*pN % 2);
        *pN /= 2;
    }

    std::reverse(uv.begin(), uv.end());

    for (auto &it : uv) {
        oss << it << "";
    }
    // std::cout << oss.str() << nl;
    outstr = oss.str();
}


/*
Summary: Split strings without regard to delimiter position.

Returns: std::vector<std::string>
*/
SVEC StringSplit(const S &str, char delim) {
    SVEC result;
    std::stringstream ss(str);
    S el;

    while (std::getline(ss, el, delim)) {
        result.push_back(el);
    }
    return result;
}


/*
Summary: Split binary strings, but only if a delimiter begins
        and ends the string.  This is a pupose-driven method.
        To just split and get all chunks, uncomment and implement
        StringSplit above.

Returns: std::vector<std::string>
*/
SVEC SmartStringSplit(const S &str, char delim) {
    SVEC result;
    S el;

    auto start = 0U;
    auto stop = str.find(delim);

    while (stop != std::string::npos) {
        result.push_back(str.substr(start, stop - start));
        start = stop + 1; // 1 == length of delimiter.  Adjust/calculate if using a larger delimiter.
        stop = str.find(delim, start);
    }
    return result;
}


/*
Summary: SCount the maximum number of zeroes within
        a numeric binary string representation.
        The method doesn't include substrings where a 1
        is missing from the start or end,
        via the SmartStringSplit() function above.
        
Returns: integer
*/
int MaxBinaryZeros(UINT n) {
    int maxSize {0};
    int * pMaxSize = &maxSize;
    char DELIM = '1';
    S binstr;
    DecimalToBinaryString(n, binstr);

    // Check for more than one 1
    if (std::count(binstr.begin(), binstr.end(), DELIM) == 1) {
        return maxSize;
    } else {

        SVEC vsplit = SmartStringSplit(binstr, DELIM);

        for (auto &qq : vsplit) {
            int tmp = qq.size();
            if (tmp > maxSize) {
                *pMaxSize = tmp;
            }
        }

        return maxSize;
    }
}

/*
For submission of solution to Codility.

Returns: integer
*/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int result;
    result = MaxBinaryZeros((UINT)N);
    return result;
}

/*
Summary: Compiling and running the executable is interactive.
        You will need to supply a positive integer when asked.
        
Returns: integer
*/
int main() {
    UINT aNumber;
    int result;
    std::cout << "Please enter an integer: " << nl;
    std::cin >> aNumber;
    result = MaxBinaryZeros(aNumber);
    std::cout << "Longest string of zeros in the binary number " << aNumber << " is " << nl;
    std::cout << result << nl;
    return 0;
}
