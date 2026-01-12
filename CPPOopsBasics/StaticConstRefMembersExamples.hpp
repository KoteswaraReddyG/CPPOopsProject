#include <iostream>
using namespace std;

class StaticConstRefMembersExamples {
public:
    StaticConstRefMembersExamples(int val, int val2, int val3): constMember(val), refMember(val2) {
        cout << "Constructor called." << endl;
        staticMember = val3;
    }
    ~StaticConstRefMembersExamples() {
        cout << "Destructor called." << endl;
    }
    void display() const {
        cout << "Const Member: " << constMember << endl;
        cout << "Ref Member: " << refMember << endl;
        cout << "Static Member: " << staticMember << endl;
    }
public:
    const int constMember;   // Constant member
    const int& refMember;    // Reference member
    static int staticMember; // Static member
};

int StaticConstRefMembersExamples::staticMember = 0; // Definition of static member

// Note: The above class demonstrates the use of static, const, and reference members in C++.

// The constructor initializes the const and reference members.
// The static member is shared across all instances of the class.
// The display function prints the values of the const and reference members.


