#include <iostream>
#include <cstdlib>
#include <direct.h>
#include "CCArray.h"

int main(int argc, char *argv[])
{
    
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }
    const char *directoryPath = argv[1];

    if (_chdir(directoryPath) != 0)
    {
        std::cerr << "Error changing directory." << std::endl;
        return 1;
    }
    CCArray arr;

    for (int i = 2; i < argc; i++)
    {
        arr.add(argv[i]);
    }

    int result = 0;
    for (int i = 0; i < arr.getSize(); i++)
    {
        std::cout << i + 1 << ". " << std::endl;
        result = std::system(arr.getString(i));
    }

    if (result == 0)
    {
        std::cout << "Commands executed successfully." << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error executing commands." << std::endl;
        return 1;
    }
}
