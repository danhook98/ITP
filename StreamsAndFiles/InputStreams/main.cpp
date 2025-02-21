#include <iostream>
#include <string>

using std::string; 

/*
 * std::istream and its derived classes handle input operations.
 *
 * Some basic input streams include:
 *     std::cin - Standard input stream which is usually the keyboard.
 *     std::ifstream - Input file stream, used to read from files.
 *     std::istringstream - Input string stream, used to read from strings.
 *
 *  std::iostream is a special case as it combines input and output operations into a single object. It can therefore be
 *  used with insertion and extraction operators (<< and >>).
 *
 *  All input streams rely on the extraction operator (>>) to get data from a stream. 
 */ 

int main()
{
    // The stream extraction operator doesn't care about whitespaces or new lines and tabs. Entering two numbers separated
    // by a space is valid. 
    int x, y;
    std::cin >> x >> y; 
    std::cout << "You entered " << x << " and " << y << '\n';

    // The extraction operator understands all default data types. It can be used to read values for variables of different
    // data types in a single stream!
    string firstName;
    int age;
    float height;
    std::cin >> firstName >> age >> height;
    std::cout << "Your name is " << firstName << ", you are " << age << " years of age, and you are " << height << "cm tall.\n";

    // If we wanted spaces and other special characters, the extraction operator should be avoided for the std::getline method
    // from the <string> library.
    string fullName;
    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, fullName); // The use of std::cin >> std::ws skips the whitespace, in particular
                                                              // the newline, and carries on reading where the actual content is entered.
    std::cout << "Hello " << fullName << '\n';

    // There are manipulators that can be used to change the behaviour of the input stream. Below are a few of the most
    // impactful ones.

    // This extracts any trailing whitespace from the stream.
    // std::ws

    // Enables or disables the skipping of reading leading whitespaces.
    // std:skipws
    // std::noskipws
    char c1, c2, c3;
    std::cin >> std::noskipws >> c1 >> c2 >> c3 >> std::skipws;
    std::cout << "c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';

    // Modifies the default numeric base for integers.
    // std::dec
    // std::hex
    // std::oct
    int n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the stream.
    std::cin >> std::hex >> n; // If the user enters 2a, n will be 42.
    std::cout << n;

    return 0; 
}