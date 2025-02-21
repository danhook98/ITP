#include <iostream>
#include <fstream>
#include <string>

using std::string; 

/*
 * Working with file streams is very similar to any other stream. The <fstream> header gives
 * access to file stream functionality.
 *
 * Like other types of streams, there are three file stream types:
 *     std::ifstream - Input file stream, used to read from files.
 *     std::ofstream - Output file stream, used to write to files.
 *     std::fstream - File stream, used for both input and output.
 */

int main()
{
    // Open the example.txt file as an input stream.
    std::ifstream file("example.txt");

    std::cout << (file.is_open() ? "File opened successfully." : "Failed to open file.") << '\n';

    // As C++ treats streams as character sequences, we can use the typical extraction and insertion
    // operators to work with them. The below code keeps looping as each word is extracted and printed.
    string line;
    //while (file >> line) { std::cout << line << '\n'; }

    // Only run one of these \/ or /\

    // If we wanted to get each line of the text file, std::getline can be used.
    while (std::getline(file, line)) { std::cout << line << '\n'; }

    file.close();



    // Writing to a file is also easy, it's just the reverse.
    std::ofstream ofile{"output.txt"};

    if (ofile.is_open())
    {
        ofile << "Hello, world!\n";
        ofile << "My name is Dan.\n";
    }

    ofile.close();


    // When a file is opened for writing with ofstream, the default behaviour is to overwrite any file
    // with the same name. We can use flags as part of the constructor to specify the behaviour to use
    // when interacting with a file. The full list of open modes are:
    //     std::ios::ate - Set the position to the end of the stream upon opening.
    //     std::ios::app - Set the position to the end of the stream before each write.
    //     std::ios::binary - Open in binary mode.
    //     std::ios::in - Open for reading.
    //     std::ios::out - Open for writing.
    //     std::ios::trunc - Discard the contents of the stream upon opening.

    std::fstream ofile2("output.txt", std::ios::app | std::ios::out);

    if (ofile2.is_open())
    {
        ofile2 << "This is an extra line!\n";
        ofile2 << "So is this!\n";
    }

    // When a file goes out of scope, it is closed automatically. It helps to be more direct by closing
    // the file manually.
    ofile2.close();


    // We can change the current position in a stream by using seekg() (g for get) for input streams, and
    // seekp() (p for put) fot output streams. These functions are available for any type of stream!
    std::ifstream file2("example.txt");

    // An absolute value can be used.
    file2.seekg(5);

    // Or reference points within the file can be used as a base.
    file2.seekg(-5, std::ios::end); 

    // The current position in the stream can also be received by using tellg() and tellp().

    return 0;
}