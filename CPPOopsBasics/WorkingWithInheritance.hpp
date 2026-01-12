#include <iostream>
using namespace std;

class WorkingWithInheritance
{
    // You can implement inheritance-related rules and functionalities here as per your project requirements.

public:
    WorkingWithInheritance()
    {
        cout << "WorkingWithInheritance Constructor called." << endl;
    }
    WorkingWithInheritance(int exampleVal, int protectedVal, int privateVal)
        : exampleMember(exampleVal), protectedMember(protectedVal), privateMember(privateVal)
    {
        cout << "WorkingWithInheritance Parameterized Constructor called." << endl;
    }
    ~WorkingWithInheritance()
    {
        cout << "WorkingWithInheritance Destructor called." << endl;
    }

    void display() const
    {
        cout << "This is WorkingWithInheritance class." << endl;
    }

    void setExampleMember(int value)
    {
        exampleMember = value;
    }
    int getExampleMember() const
    {
        return exampleMember;
    }
    void setProtectedMember(int value)
    {
        protectedMember = value;
    }
    int getProtectedMember() const
    {
        return protectedMember;
    }
    void setPrivateMember(int value)
    {
        privateMember = value;
    }
    int getPrivateMember() const
    {
        return privateMember;
    }

public:
    // Add member variables and methods as needed
    int exampleMember;

protected:
    // Protected members can be accessed by derived classes
    int protectedMember;

private:
    // Private members can only be accessed within this class
    int privateMember;
};

// Note: This file is currently a placeholder for the WorkingWithInheritance class.
// You can implement inheritance-related rules and functionalities here as per your project requirements.
class DerivedClass : public WorkingWithInheritance
{
public:
    DerivedClass()
    {
        cout << "DerivedClass Constructor called." << endl;
    }
    DerivedClass(int exampleVal, int protectedVal, int privateVal)
        : WorkingWithInheritance(exampleVal, protectedVal, privateVal)
    {
        cout << "DerivedClass Parameterized Constructor called." << endl;
    }
    ~DerivedClass()
    {
        cout << "DerivedClass Destructor called." << endl;
    }
    void displayDerived() const
    {
        cout << "This is DerivedClass inheriting from WorkingWithInheritance." << endl;
        cout << "Example Member: " << getExampleMember() << endl;
        cout << "Protected Member: " << getProtectedMember() << endl;
        // Note: Private members of the base class are not accessible here
        cout << "Private Member: Access Denied directly accessed" << endl;
        cout << "Private Member: " << getPrivateMember() << endl;
    }
};

// You can add more derived classes and functionalities as needed.
class AnotherDerivedClass : protected WorkingWithInheritance
{
public:
    AnotherDerivedClass()
    {
        cout << "AnotherDerivedClass Constructor called." << endl;
    }
    AnotherDerivedClass(int exampleVal, int protectedVal, int privateVal)
        : WorkingWithInheritance(exampleVal, protectedVal, privateVal)
    {
        cout << "AnotherDerivedClass Parameterized Constructor called." << endl;
    }
    ~AnotherDerivedClass()
    {
        cout << "AnotherDerivedClass Destructor called." << endl;
    }
    void displayAnotherDerived() const
    {
        cout << "This is AnotherDerivedClass inheriting from WorkingWithInheritance." << endl;
        cout << "Example Member: " << getExampleMember() << endl;
        cout << "Protected Member: " << getProtectedMember() << endl;
        // Note: Private members of the base class are not accessible here
        cout << "Private Member: Access Denied through direct access" << endl;
        cout << "Private Member: " << getPrivateMember() << endl;
        cout << "Private Member: " << protectedMember << endl;
    }
};
// You can add more derived classes and functionalities as needed.
class PrivateDerivedClass : private WorkingWithInheritance
{
public:
    PrivateDerivedClass()
    {
        cout << "PrivateDerivedClass Constructor called." << endl;
    }
    PrivateDerivedClass(int exampleVal, int protectedVal, int privateVal)
        : WorkingWithInheritance(exampleVal, protectedVal, privateVal)
    {
        cout << "PrivateDerivedClass Parameterized Constructor called." << endl;
    }
    ~PrivateDerivedClass()
    {
        cout << "PrivateDerivedClass Destructor called." << endl;
    }
    void displayPrivateDerived() const
    {
        cout << "This is PrivateDerivedClass inheriting from WorkingWithInheritance." << endl;
        cout << "Example Member: " << getExampleMember() << endl;
        cout << "Protected Member: " << getProtectedMember() << endl;
        // Note: Private members of the base class are not accessible here
        cout << "Private Member: Access Denied" << endl;
        cout << "Private Member: " << getPrivateMember() << endl;
    }
};
// You can add more derived classes and functionalities as needed.