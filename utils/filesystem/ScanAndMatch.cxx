
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;


std::string ExtensionCheck(std::string extension) {
    if (extension.find(".") == std::string::npos) {
        return extension.insert(0, ".");
    } else {
        return extension;
    }
}

std::string CreatePath(std::string root, std::string basename) {
    return root + "\\" + basename;
}


void WriteResults(std::string outpath, std::vector<std::string> &data_collection) {
    // Write vector to specified text file.
    std::ofstream outf(outpath);

    if (!outf) {
        std::cout << "Couldn't open file " << outpath << " for writing!" << std::endl;
    } else {
        for (const auto &element : data_collection) {
            outf << element << std::endl;
        }
    }
}


int main(int argc, char *argv[]) {

    setlocale(LC_ALL, ""); // Should output Unicode.

    unsigned int line_count = 0;

    std::vector<std::string> vec_files;
    std::vector<std::string> vec_filelines;
    // std::string test_folder = "S:\\OFP\\Analytics\\Population Management\\Mark M\\Gaps_Loading\\Table_Queries";
    // std::string search_term = "MMorett1"; // This should be a command line argument.
    // std::string input_extension = "sql";
    std::string search_term;
    std::string input_extension;
    std::string file_extension;
    fs::path current_dir;

    std::string ln;
    
    
    // std::cout << "Current folder: " << test_folder << std::endl;
    if (argc == 4) {

        if (argv[1]) {
            current_dir = argv[1];
        } else {
            current_dir = ".";
        }
        // fs::path current_dir(test_folder);
        // fs::path current_dir("."); // For dropping into a folder

        /* Keyword to find. */
        if (argv[2]) {
            search_term = argv[2];
        } else {
            std::cout << "Please enter keyword as second argument." << std::endl;
        }

        /* File extension. Defaults to sql */
        if (argv[3]) {
            input_extension = argv[3];
        } else {
            input_extension = "sql";
        }

        file_extension = ExtensionCheck(input_extension);
        // std::cout << "Current file extension: " << file_extension << std::endl;
        

        // Populate vector
        for (auto &file : fs::recursive_directory_iterator(current_dir)) {
            if (file.path().extension() == file_extension) {
                vec_files.push_back(CreatePath(file.path().parent_path().string(), file.path().filename().string()));
            }
        }


        bool filename_written_tf; // Determine if filename written or not
        std::uint16_t tot_n_found = 0; // Match counter
        std::uint16_t n_found_in_file; // Match counter
        std::string worker_str;

        for (const auto &element : vec_files) {
            // std::cout << element << std::endl;
            // std::cout << "\n" << std::endl; // Pad the top a bit.
            filename_written_tf = false;
            std::fstream infile(element);
            if (infile) {
                n_found_in_file = 0;
                // std::cout << "Searching file " << element << "...\n" << std::endl;
                while (getline(infile, ln)) {
                    line_count++;
                    if (ln.find(search_term, 0) != std::string::npos) {
                        n_found_in_file++;
                        // Only need to write filename once.
                        if (filename_written_tf == false) {
                            worker_str = "File: " + element + "\n";
                            vec_filelines.push_back(worker_str);
                            filename_written_tf = true;
                        }
                        // std::cout << line_count << ": " << ln << std::endl;
                        worker_str = line_count + ": " + ln;
                        vec_filelines.push_back(worker_str);
                        
                    }
                }
            }
        }

        if (n_found > 0) {
            std::cout << "Number of keyword matches: " << n_found << std::endl;
        }


        // Write output to programming/Cpp/file-system directory
        // This function comes from `utils.hxx`
        if (vec_filelines.size() > 0) {
            std::string filename = "FileScanner-results.txt";
            std::string output_path = "S:\\OFP\\Analytics\\Population Management\\Mark M\\Programming\\Cpp\\file-system\\" + filename;
            WriteResults(output_path, vec_filelines);        
        }
        return 0;

    } else {

        const char *arg_text = " takes takes three arguments.\n\n"
                "The first argument should be a folder path.\n"
                "The second argument should be a search term.\n"
                "The third argument should be a file extension (e.g. - .txt, .sql).\n"
                "If no extension is provided, the current action is to look for SQL files.\n\n";

        std::cout << argv[0] << arg_text << std::endl;

        return 1;    
    }
}
