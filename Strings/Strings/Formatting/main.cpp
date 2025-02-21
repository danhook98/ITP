#include <iostream>
#include <string>
#include <sstream>
#include <format>
#include <chrono>

using namespace std;

int main()
{
    string question = "What is the meaning of life, the universe and everything?\n";
    int x = 42;

    // C-style string formatting. - Horrible.
    char buffer[200];
    sprintf_s(buffer, "%s The answer is: %d\n", question.c_str(), x);
    cout << buffer; 

    // C-style string formatting without writing to a buffer.
    printf("%sThe answer is: %d\n", question.c_str(), x);

    // String stream formatting. These could also be used to write to a file, or anything else.
    ostringstream oss;
    oss << question << "The answer is: " << x << "\n";
    cout << oss.str();


    // New string formatting with C++20!
    string answer = format("{}The answer is: {}", question, x);
    cout << answer;

    // Writing a formatted string into a stream.
    // vector<char> vecBuffer;
    // format_to(ostream_iterator(vecBuffer), "{}The answer is: {}", question, x);

    // Date and time formatting!
    chrono::time_point time = chrono::system_clock::now();
    string now = std::format("\n\nIt is {:%A %d %B, %Y %T}\n", time);
    cout << now;

    return 0; 
}