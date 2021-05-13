#ifndef CODILITY_BINARY_GAP_H_
#define CODILITY_BINARY_GAP_H_


#include <string>       // std::string
#include <vector>       // std::vector


/*
 * Summary: newline character
*/
const char nl = '\n';


/*
 * Summary: typedefs to keep things maybe a little more readable.
*/
typedef unsigned int UINT;
typedef std::string S;
typedef std::vector<UINT> UIVEC;
typedef std::vector<S> SVEC;



void DecimalToBinaryString(UINT x, S & y);
// VEC StringSplit(const S &x, char y);
SVEC SmartStringSplit(const S &x, char y);
int MaxBinaryZeros(UINT x);
int solution(int N);

#endif
