#include <iostream>

class DynamicArray
{
    int _size{};
    int* _array = nullptr;
public:
    explicit DynamicArray(const int sz)
    {
        _size = sz;
        _array = new int[sz];
    }
    ~DynamicArray()
    {
        delete[] _array;
        _array = nullptr;
    }

    int size() const;
    void resize(int sz);
};

/*
  Implement a class DynamicArray that dynamically allocates an array of integers, properly
  deallocates memory in its destructor, and allows resizing.
*/
int DynamicArray::size() const
{
    return _size;
}

void DynamicArray::resize(const int sz)
{
    if (sz < 0) return;

    // Create a new integer array with the given size.
    int* newArray = new int[sz];

    std::fill_n(newArray, sz, 0);

    if ((sz > _size) || (sz < _size))
    {
        memcpy(newArray, _array, (sz > _size ? _size : sz) * sizeof(*newArray));
    }

    delete[] _array;
    _array = newArray;
    _size = sz;
}

/*
  createArray should dynamically allocate an array of integers with the given size,
  initialize all elements to 0, and return a pointer to the array.
*/
int *createArray(int size)
{
    throw new std::runtime_error("not yet implemented");
}


int main()
{
    DynamicArray d{10};
    std::cout << d.size() << std::endl;
    d.resize(15);
    std::cout << d.size() << std::endl;

    return 0;
}