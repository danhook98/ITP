#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> IntPassthrough(unique_ptr<int> ptr) { return ptr; }
void PrintSharedUses(shared_ptr<int> ptr) { cout << ptr.use_count() << endl; }

int main()
{
    // A unique pointer has complete ownership of the object that it points to. Due to how it works, std::move() must
    // be used if the pointer needs to be transferred between methods. Making a unique_ptr const means it cannot be
    // transferred.
    unique_ptr<int> intPtr = make_unique<int>(5);
    intPtr = IntPassthrough(move(intPtr)); // Gets transferred into the 'IntPassthrough' method, and then returned.

    // A shared pointer allows multiple pointers to share ownership of the object it points to. It will only delete
    // itself once the last owner goes out of scope. This is great for when we want multiple objects to reference the
    // same resource, but we don't want to worry about who will be responsible for deleting the pointer and cleaning up
    // the resource.
    shared_ptr<int> sharedPtr1 = make_shared<int>(50);
    PrintSharedUses(sharedPtr1);

    {
        shared_ptr<int> sharedPtr2 = sharedPtr1;
        PrintSharedUses(sharedPtr2);
        cout << sharedPtr1.use_count() << endl;
    }

    PrintSharedUses(sharedPtr1);

    return 0;
}