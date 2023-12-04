<h1 align="center">
Directory Launcher Generator
</h1>

The Directory Launcher Generator is a C++ program designed to facilitate the creation of a launcher executable. This executable enables users to seamlessly navigate directories and execute a series of specified files. The program streamlines the process of automating tasks within a targeted directory, enhancing efficiency and convenience.
<h2>
Features
</h2>
User-Friendly Input: Utilize simple prompts to gather user input for the executable name, target directory, and a list of files to execute.

Dynamic Code Generation: Automatically generates a C++ source file containing embedded code for changing the current working directory and executing a sequence of files.

Compilation and Execution: Compiles the generated source file into an executable, storing both in a "generated" folder. The compiled executable facilitates the desired directory navigation and file execution.

Clean-Up Functionality: Removes the temporary C++ source file after successful compilation, ensuring a tidy and efficient workflow.
<h2>
Getting Started
</h2>
Clone the Repository:


```
git clone https://github.com/yourusername/directory-launcher-generator.git
cd directory-launcher-generator
```

Compile the Program:


```
g++ main.cpp -o directory_launcher_generator
```

Run the Program:


```
./directory_launcher_generator
```

Follow the Prompts:

Enter the desired executable name.
Provide the target directory path.
Input file names to be executed (type 'done' when finished).
Generated Output:

The compiled executable and the temporary C++ source file will be located in the "generated" folder.
<h2>
Example Usage
</h2>
```
Enter the executable file name: my_launcher
Enter the desired directory path: /path/to/target/directory
Enter file names with the file extension (enter 'done' when finished):
file1.txt
file2.txt
file3.txt
done
```

Note
Ensure that your compiler supports C++17 or later, and the necessary filesystem support is available.

Customize the program as needed for specific use cases.
