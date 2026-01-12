#include <iostream>
using namespace std;

class WorkingWithAbstractionRules
{
public:
    WorkingWithAbstractionRules() : publicMember(0), privateMember(0), protectedMember(0)
    {
        cout << "WorkingWithAbstractionRules Constructor called." << endl;
    }
    WorkingWithAbstractionRules(int pubVal, int privVal, int protVal)
        : publicMember(pubVal), privateMember(privVal), protectedMember(protVal)
    {
        cout << "WorkingWithAbstractionRules Parameterized Constructor called." << endl;
    }
    ~WorkingWithAbstractionRules()
    {
        cout << "WorkingWithAbstractionRules Destructor called." << endl;
    }

    int getValue() const
    {
        return privateMember;
    }
    void setValue(int val)
    {
        privateMember = val;
    }

    int getProtectedValue() const
    {
        return protectedMember;
    }
    void setProtectedValue(int val)
    {
        protectedMember = val;
    }

    void display() const
    {
        cout << "publicMember: " << publicMember << endl;
        cout << "privateMember: " << privateMember << endl;
        cout << "protectedMember: " << protectedMember << endl;
    }

public:
    int publicMember;

private:
    int privateMember;

protected:
    int protectedMember;
};

// Note: This file is currently a placeholder for the WorkingWithAbstractionRules class.
// You can implement abstraction-related rules and functionalities here as per your project requirements.
