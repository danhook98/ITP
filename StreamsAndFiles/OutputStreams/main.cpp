#include <iostream>

/*
 * std::ostream and its derived classes handle output operations.
 *
 * Some basic output streams include:
 *     std::cout - The standard output stream, typically to a console.
 *         std::cerr, std::clog
 *     std::ofstream - Output file stream, writes to files.
 *     std::ostringstream - Output string stream, used to write to strings.
 *
 * Output streams are written with the insertion operator (<<).
 */

int main()
{
    // The most common use of the stream insertion operator.
    std::cout << "Hello, World!" << std::endl;

    // The std::endl is used to signify a line end. This creates a new line, and
    // flushes the stream. It does have a performance impact, so '\n' can be used
    // instead. If you want to flush the stream, then std::flush can be used.
    std::cout << "I'm ending with a new line!\n";
    std::flush(std::cout);

    return 0;
}