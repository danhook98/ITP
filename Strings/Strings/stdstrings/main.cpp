#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl; 

int main()
{
    const string empty;
    const string name = "Dan"; // String defined with a literal.
    const string copy = name;
    const string& copy_2(name);
    const string repeated(5, 'B');

    cout << empty << '\n';
    cout << name << '\n';
    cout << copy << '\n';
    cout << copy_2 << '\n';
    cout << repeated << '\n';

    string a = "Hello";
    string b = "World";
    string whole = a + " " + b;
    a += " Dan";

    cout << a << '\n';
    cout << b << '\n';
    cout << whole << '\n';
    cout << a << '\n';

    size_t pos = whole.find("World");
    size_t notFound = whole.find("Dan");

    cout << pos << '\n';
    cout << notFound << '\n';
    cout << (notFound == string::npos) << '\n';

    cout << whole.size() << '\n';

    return 0; 
}