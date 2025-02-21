#include <iostream>

// An abstract class defines empty methods that must be implemented by the inheriting class. Abstract methods must be
// implemented by at least one child in the class hierarchy. They can also have concrete methods and member
// variables, which is known as a partial implementation. The methods must be virtual, and have to be followed by the
// 'pure' specifier (= 0).
class Shape
{
private:
    std::string _name{};
    void SetName(const std::string &name) { _name = name; }
public:
    virtual float Area() = 0;
    virtual void Print() {}
};

class Square : public Shape
{
private:
    float _width{};
    float _height{};
public:
    Square(float width, float height) : _width(width), _height(height) {}
    float Area() override { return _width * _height; }
};

// An interface explicitly tells the inheriting class that it must implement the interface's methods. An interface
// cannot have any concrete methods or member properties, and is also called a pure-abstract class.
class IInteractable {
public:
    virtual void interact(/*BaseEntity& user*/) = 0;
};

class IWeapon {
public:
    virtual void fire() = 0;
};

class BaseWeapon : public IInteractable, public IWeapon {
public:
    void interact(/*BaseEntity& user*/) override {
        // implementation
    }

    void fire() override {
        // implementation
    }
};

int main()
{
    Square square{10, 10};
    std::cout << square.Area() << std::endl;
    return 0;
}