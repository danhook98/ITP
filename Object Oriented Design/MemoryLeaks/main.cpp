#include <iostream>

int main()
{
    // Create a new integer on the heap.
    const int *p = new int{5};

    std::cout << p << " = " << *p << std::endl;

    // It's very important to delete the integer when we're done with it.
    delete p;

    std::cout << p << " = " << *p << std::endl;

    // Set the pointer to 'nullptr', otherwise we'll have a 'dangling pointer'.
    p = nullptr;

    std::cout << p << " = " << *p << std::endl;

    return 0;
}