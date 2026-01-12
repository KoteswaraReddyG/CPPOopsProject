#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    virtual void sound() const
    {
        cout << "Animal makes a sound" << endl;
    }
    virtual ~Animal() = default; // Virtual destructor for proper cleanup
};

// Derived class Dog
class Dog : public Animal
{
public:
    void sound() const override
    {
        cout << "Dog barks" << endl;
    }
};

// Derived class Cat
class Cat : public Animal
{
public:
    void sound() const override
    {
        cout << "Cat meows" << endl;
    }
};

// Function to demonstrate polymorphism
void makeSound(const Animal &animal)
{
    animal.sound();
}
// You can add more classes and functionalities as needed.

class polymorphismExample
{
public:
    polymorphismExample()
    {
        cout << "Polymorphism Example Constructor called." << endl;
    }
    ~polymorphismExample()
    {
        cout << "Polymorphism Example Destructor called." << endl;
    }

    void add(int a, int b)
    {
        cout << "Sum: " << a + b << endl;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }

    void add(double a, double b)
    {
        cout << "Sum: " << a + b << endl;
    }

    // Function with default parameter
    // This will be called if only one argument is provided, but not if two arguments are provided
    // there is already a function with two parameters and 3 aruments function is also defined.
    // which is better than using function overloading with same number of parameters.
    // thus avoiding ambiguity. with default parameters we can reduce number of overloaded functions.
    // commenting this function will lead to resolve ambiguity between add(int, int) and add(int, int, int) when called with two arguments.
    // void add(int a, int b = 5)
    // {
    //     cout << "Sum with default parameter: " << a + b << endl;
    // }
};

// You can add more classes and functionalities as needed.