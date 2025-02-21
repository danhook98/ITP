#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
public:
    void MakeSound() const { cout << "Generic animal noise." << endl; }
};

class CartoonCharacter
{
public:
    void SayPhrase() { cout << "I'm a cartoon character!" << endl; }
};

class MickeyMouse : public Animal, public CartoonCharacter
{
public:
    void SayName() { cout << "I'm Mickey Mouse!" << endl; }
};

int main()
{
    MickeyMouse mickeyMouse;
    mickeyMouse.MakeSound();
    mickeyMouse.SayPhrase();
    mickeyMouse.SayName();

    return 0;
}