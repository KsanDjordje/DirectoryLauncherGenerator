#include <iostream>
#include <cstdlib>
#include <direct.h>
#include <fstream>
#include  <filesystem>
#include "CCArray.h"
#include "StringArr.h"

// Generates a C++ source file with embedded code to change the current working directory
// to the specified 'directoryPath' and execute a series of files listed in 'fileList'
// using the 'system' function. The generated code includes necessary headers for input/output,
// standard library functions, and changing the current working directory. The generated program
// returns 0 on successful execution and outputs an error message to std::cerr in case of failure.
// The purpose is to create an executable that can conveniently change directories and execute
// a set of files, useful for automating tasks in a specific directory.
void generateSourceFile(const std::string& executableFileName, const std::string& directoryPath, const StringArray& fileList) {
    
    // std::string outputPath = "./generated/" + executableFileName;
    // std::ofstream outFile(outputPath);
    std::ofstream outFile(executableFileName);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the output file: " << executableFileName << std::endl;
        return;
    }

    outFile << "#include <iostream>" << std::endl;
    outFile << "#include <cstdlib>" << std::endl;
    outFile << "#include <direct.h>" << std::endl;  
    outFile << "int main(){" << std::endl;

    // Change the current working directory
    outFile << "    const char* directoryPath = \"" << directoryPath << "\";" << std::endl;
    outFile << "    if (_chdir(directoryPath) != 0) {" << std::endl;
    outFile << "        std::cerr << \"Error changing current directory to: \" << directoryPath << std::endl;" << std::endl;
    outFile << "        return 1;" << std::endl;
    outFile << "    }" << std::endl;

    // Execute the files
    for (size_t i = 0; i < fileList.getSize(); i++) {
        outFile << "    {" << std::endl;
        outFile << "        std::string filePath = \"" << fileList.getString(i) << "\";" << std::endl;
        outFile << "        std::string command = \"start \" + filePath;" << std::endl;
        outFile << "        system(command.c_str());" << std::endl;
        outFile << "    }" << std::endl;
    }

    outFile << "    return 0;" << std::endl;
    outFile << "}" << std::endl;
    outFile.close();
}

void compileSourceFile(const std::string& sourceFileName, const std::string& outputFileName) {
    std::string compileCommand = "g++ " + sourceFileName +" -o ./generated/" + outputFileName;

    int result  = system(compileCommand.c_str());
    if (result != 0) {
        std::cerr << "Error compiling the source file: " << sourceFileName << std::endl;
        std::cerr << "Compilation command: " << compileCommand << std::endl;
        exit(1);
        
    }
}
// Converts the input directory path string to use double backslashes (\\) instead of single backslashes (\).
// This is necessary when representing directory paths in C++ string literals, as a single backslash is an escape character.
std::string convertDirectoryPath(std::string& input){
    std::string result;
    for(char ch : input){
        if(ch == '\\'){
            result += "\\\\";
        }else{
            result += ch;
        }
    }
    return result;
}
int main()
{
    std::string executableFileName, directoryPath, directoryPathTemp, fileName;

    StringArray fileList;
    std::filesystem::create_directory("./generated");
    std::cout << "Enter the executable file name: ";
    std::cin >> executableFileName;

    std::cout << "Enter the desired directory path: ";
    std::cin >> directoryPathTemp;
    directoryPath = convertDirectoryPath(directoryPathTemp);

    std::cout << "Enter file names with the file extension (enter 'done' when finished)" << std::endl;
    while (true)
    {
        std::cin >> fileName;
        if (fileName == "done")
            break;
        fileList.addString(fileName);
    }
    // Generates a temporary .cpp file
    generateSourceFile(executableFileName+ ".cpp", directoryPath, fileList);
    // Compiles the .cpp file
    compileSourceFile(executableFileName + ".cpp", executableFileName);
    // Removes the temporary .cpp file
    std::filesystem::remove(executableFileName + ".cpp");
}
