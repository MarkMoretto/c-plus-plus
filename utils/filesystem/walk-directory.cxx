/*
Recursively walk a file directory and return files based on extension

Compiles successfully on Windows with msys2 and -std=c++17 flag
>>> g++ -std=c++17 -Wall -Wextra -o <executable name> <file name>.c__

Optional syntax:
>>> g++ -std=c++17 -Wall -Wextra -o <executable name> <file name>.c__ -lstdc++fs -static-libgcc -static-libstdc++

*/

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;


std::string createPath(std::string root, std::string basename) {
    return root + "\\" + basename;
}



int main(int argc, char *argv[]) {
    
    if (argc < 2 || argc > 3) {
        const char *arg_text = " takes takes one or two arguments.\n"
                "The first argument should be a folder path.\n"
                "The second argument should be a file extension (e.g. - .txt, .sql).\n"
                "If no extension is provided, the current action is to look for text files.";

        std::cout << argv[0] << arg_text << std::endl;
    
    } else {

        std::string top_level_folder;
        std::string file_extension;
        std::string arg1;
        std::string arg2;

        top_level_folder = argv[1];
        if (argv[2]) {
            file_extension = argv[2];    
        } else {
            file_extension = ".txt";    
        }

        // std::string test_path = R"(C:\path\to\folder)";
        // std::string file_extension = ".sql";
        // std::string file_extension = ".txt";

        fs::path current_dir(top_level_folder);


        for (auto &file : fs::recursive_directory_iterator(current_dir)) {
            if (file.path().extension() == file_extension) {
                std::cout << createPath(file.path().parent_path().string(), file.path().filename().string()) << std::endl;
            }
        }
    }
}
