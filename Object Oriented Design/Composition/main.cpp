#include <iostream>
#include <memory>
#include <utility>

using namespace std;

// Inheritance represents an 'is-a' relationship, Composition represents a 'has-a' relationship. For example, a Dog is
// an Animal, a Car has an engine and wheels.

class Engine
{
public:
    virtual void StartEngine() { cout << "Starting the engine!" << endl; }

    virtual ~Engine() = default;
};

class DieselEngine : public Engine
{
public:
    void StartEngine() override { cout << "Starting the diesel engine!" << endl; }
};

class PetrolEngine : public Engine
{
public:
    void StartEngine() override { cout << "Starting the petrol engine!" << endl; }
};

class Wheel final
{
public:
    void Rotate() const { cout << "Wheel rotating!" << endl; }

    ~Wheel() = default;
};

class Car
{
public:
    explicit Car(unique_ptr<Engine> engine) : _engine(move(engine)) {}

    ~Car() = default;

    void Start()
    {
        _engine->StartEngine();

        for (auto &wheel : _wheels) wheel.Rotate();
    }

private:
    unique_ptr<Engine> _engine;
    Wheel _wheels[4];
};

int main()
{
    // DieselEngine dieselEngine;
    // PetrolEngine petrolEngine;
    //
    // Car car{dieselEngine};
    // car.Start();

    auto dieselEngine = make_unique<DieselEngine>();
    auto petrolEngine = make_unique<PetrolEngine>();

    Car car{move(dieselEngine)};
    car.Start();

    return 0;
}