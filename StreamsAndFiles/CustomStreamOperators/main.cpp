#include <iostream>
#include <fstream>
#include <string>

using std::string; 

// By providing custom insertion and extraction operators for our classes, we can control how they
// work with streams. In order to define suitable operators, the friend keyword must be used. This
// tells the compiler that the specified function (or class) can access the private properties and
// methods of a class.

// A simple class that represents a 2D point in space.
class Point
{
private:
    int _x{};
    int _y{};
public:
    Point(const int x, const int y) : _x{x}, _y{y} {}
    void SetValues(const int x, const int y) { _x = x; _y = y; }
    friend std::ostream &operator<<(std::ostream &os, const Point &point);
    friend std::istream &operator>>(std::istream &is, Point &point);
};

// As the operator functions for ostream and istream exist outside of the point class, they need
// to be defined here (preferably in the same .cpp file as the class).
std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "Point(" << point._x << ", " << point._y << ")";
    return os;
}

// The below doesn't work properly. 
/*std::istream &operator>>(std::istream &is, Point &point)
{
    is >> point._x >> point._y;
    return is;
}*/

std::istream &operator>>(std::istream &is, Point &point)
{
    std::string initial;
    char bracket;
    is >> initial;

    // The stream we're reading is empty. 
    if (initial.empty())
    {
        return is;
    }

    // The x value has been pulled out of the stream as "Point(x, " 
    // so we need to put it back in to read it out again
    is.putback(initial[initial.size() - 2]);

    // the comma has gone as it was read out by the initial extraction.
    is >> point._x >> point._y >> bracket;

    return is;
}



int main()
{
    Point point{5, 10};

    std::cout << point << '\n';

    // Open a file to write the point object to.
    std::ofstream ofile("output.txt");
    if (ofile.is_open()) { ofile << point; }
    point.SetValues(20, 40);
    ofile.close();

    std::cout << point << '\n';

    // Read the file and extract the point object values.
    std::ifstream ifile("output.txt");
    if (ifile.is_open()) { ifile >> point; }
    ifile.close();

    std::cout << point << '\n';

    return 0;
}