#include <iostream>

using namespace std;

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void MakeNoise() { cout << "Generic animal noise." << endl; }
};

class Dog : public Animal
{
public:
    void MakeNoise() override { cout << "Woof, woof!" << endl; }
};

void MakeAnimalSound(Animal &animal)
{
    animal.MakeNoise();
}

int main()
{
    Dog dog;
    MakeAnimalSound(dog);

    Animal *animal = new Dog();

    // Either of the below work.
    //animal->MakeNoise();
    Dog *dog2 = dynamic_cast<Dog*>(animal);

    dog2->MakeNoise();

    delete animal;

    return 0;
}