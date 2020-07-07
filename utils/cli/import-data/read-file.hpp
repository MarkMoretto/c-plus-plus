/**
 * Import datafrom a given filepath and output each line to the command prompt.
*/

#ifndef READFILE_HPP_BASE_
#define READFILE_HPP_BASE_

#include <vector>
#include <string>


const char nl = '\n';
const unsigned int default_linebuff {1000};


typedef std::string STRING;
typedef std::vector<STRING> sVEC;



int read_to_vector(char* file_path, sVEC& sv) {
    /**
     * Variable definitions
    */
    FILE * f_ptr; // File pointer
    char * line;  // Line pointer
    int line_sz;  // Line size value

    /**
     * Open file ("r" -> read only)
     * Return nonzero value if no file found.
    */
    f_ptr = fopen(file_path, "r");
    if (f_ptr == NULL) { return -1; }    

    /**
     * Create line buffer
     * Note: This is creating a new memory allocation in lieu of using `line = (char*) std::malloc(line_sz);`
    */
    line_sz = default_linebuff;
    line = (char*)::operator new (sizeof(char) * line_sz);

    /**
     * Read file
     * Note: This is creating a new memory allocation in lieu of using std::
    */
    while(fgets(line, line_sz, f_ptr) != NULL) {
        // Convert char to string
        STRING sline = line;

        // Push string onto vector.
        sv.push_back(sline);
    }

    return 0;
}

#endif
