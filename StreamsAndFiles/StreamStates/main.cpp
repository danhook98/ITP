#include <iostream>

/*
 * Stream states are utilised to determine the state of a stream after performing input
 * and/or output operations.
 *
 * These states can be used to help handle errors or certain specific conditions during
 * input/output operations. There are four state flags:
 *     goodbit - indicates the stream is in a good state. 
 *     eofbit - indicates that the end of an input sequence has been reached.
 *     failbit - indicates that a logical error has occured on the stream.
 *     badbit - indicates that a read/write operation has failed.
 *
 *  There are a few functions that can be called to check for these flags in a stream:
 *      good() - returns true if the stream is in a good state (i.e. none of the error flags are set).
 *      eof() - returns true if eofbit is set (end of file).
 *      fail() - returns true if either failbit or badbit is set.
 *      bad() - returns true if badbit is set.
 *
 *  Status flags can be reset on a stream by calling clear().
 */

int main()
{
    int number;
    std::cin >> number;

    // The stream has failed to extract the desired data type, as the user didn't enter a number.
    if (std::cin.fail())
    {
        std::cout << "Invalid input.\n";

        // Clear the status flag(s), as we're handling the error.
        std::cin.clear(); 

        // Clear the input stream. 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout << "Valid input.\n";
    }

    return 0;
}