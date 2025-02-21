#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
private:
    string sound {"Generic animal sound."};
public:
    void setSound(const string &s) { sound = s; }
    void makeSound() const { cout << sound << endl; }
};

// Dog has to inherit from public Animal, if it was just Animal, then every method would be made private.
class Dog : public Animal
{
public:
    void Eat() { cout << "The dog eats." << endl; }
};

class JackRussell : public Dog
{
public:
    void Attack() { cout << "The jack russell attacks!" << endl; }
};

int main()
{
    Dog dog;
    dog.setSound("Woof");
    dog.makeSound();
    dog.Eat();

    JackRussell jackRussell;
    jackRussell.Attack();
}