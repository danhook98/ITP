#include <iostream>

int main()
{
    // Declare a C-style string.
    char name[10];
    strcpy_s(name, "Daniel");

    std::cout << name << std::endl; 

    return 0; 
}