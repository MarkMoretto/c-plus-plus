/*
Recursively walk a file directory
Write results to text file

Takes arguments:
    folder path (must use forward slash or double backslash)
    file extension (with period at beginning)


Run in bash:
./walkdir <folder path> <extension>
*/
#include <filesystem>
#include <iostream>
// #include <fstream>
#include <string>
#include <vector>

#include "walk-directory.hxx"

namespace fs = std::filesystem;


std::string CreatePath(std::string root, std::string basename) {
    return root + "\\" + basename;
}



int main(int argc, char *argv[]) {
    
    if (argc < 2 || argc > 3) {
        const char *arg_text = " takes takes one or two arguments.\n"
                "The first argument should be a folder path.\n"
                "The second argument should be a file extension (e.g. - .txt, .sql).\n"
                "If no extension is provided, the current action is to look for text files.";

        std::cout << argv[0] << arg_text << std::endl;
        return 1;
    
    } else {

        std::string top_level_folder;
        std::string file_extension;
        std::string arg1;
        std::string arg2;
        std::string output_path;

        std::vector<std::string> results_vec;

        top_level_folder = argv[1];


        if (argv[2]) {
            file_extension = argv[2];    
        } else {
            file_extension = ".txt";    
        }

        
        fs::path current_dir(top_level_folder);

        // Populate vector
        for (auto &file : fs::recursive_directory_iterator(current_dir)) {
            if (file.path().extension() == file_extension) {
                results_vec.push_back(CreatePath(file.path().parent_path().string(), file.path().filename().string()));
                // std::cout << createPath(file.path().parent_path().string(), file.path().filename().string()) << std::endl;
            }
        }

        // Print results to console
        for (const auto &element : results_vec) {
            std::cout << element << std::endl;
        }


        // Write output to programming/Cpp/file-system directory
        // This function comes from `utils.hxx`
        output_path = "S:\\path\\to\\my-file.txt";
        WriteResults(output_path, results_vec);


        return 0;
    }
}
