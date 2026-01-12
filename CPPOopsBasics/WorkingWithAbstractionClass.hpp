#include <iostream>
using namespace std;

class WorkingWithAbstractionClass
{
public:
    WorkingWithAbstractionClass()
    {
        cout << "WorkingWithAbstractionClass Constructor called." << endl;
    }
    ~WorkingWithAbstractionClass()
    {
        cout << "WorkingWithAbstractionClass Destructor called." << endl;
    }
    virtual void display() const = 0; // Pure virtual function making this an abstract class
};
// Note: This file is currently a placeholder for the WorkingWithAbstractionClass class.
// You can implement abstraction-related functionalities here as per your project requirements.

class DerivedFromAbstraction : public WorkingWithAbstractionClass
{
public:
    DerivedFromAbstraction()
    {
        cout << "DerivedFromAbstraction Constructor called." << endl;
    }
    ~DerivedFromAbstraction()
    {
        cout << "DerivedFromAbstraction Destructor called." << endl;
    }
    void display() const override
    {
        cout << "DerivedFromAbstraction implementing display from WorkingWithAbstractionClass." << endl;
    }
};
