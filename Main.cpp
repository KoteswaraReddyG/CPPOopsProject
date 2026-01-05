#include "SampleClass.hpp"
#include "StaticConstRefMembersExamples.hpp"
#include "WorkingWithAbsractionRules.hpp"
#include "WorkingWithInheritance.hpp"

int main()
{

    // Create an object of SampleClass using parameterized constructor
    SampleClass obj(10, 20.5, 'A', 30.7f);

    cout << "Sizeof obj:  " << sizeof(obj) << endl;

    cout << "Address of a: " << &obj.a << endl;
    cout << "Address of b: " << &obj.b << endl;
    cout << "Address of c: " << static_cast<void *>(&obj.c) << endl;
    cout << "Address of d: " << &obj.d << endl;

    cout << "Value of a: " << obj.a << endl;
    cout << "Value of b: " << obj.b << endl;
    cout << "Value of c: " << obj.c << endl;
    cout << "Value of d: " << obj.d << endl;

    // Create an object of StaticConstRefMembersExamples
    StaticConstRefMembersExamples example(42, 84, 168);
    example.display();
    cout << "Sizeof example:  " << sizeof(example) << endl;
    cout << " Static Member : " << StaticConstRefMembersExamples::staticMember << endl;

    // Create an object of WorkingWithAbstractionRules
    WorkingWithAbstractionRules abstractionObj;
    abstractionObj.setValue(100);
    abstractionObj.setProtectedValue(200);
    abstractionObj.publicMember = 300;
    abstractionObj.display();

    WorkingWithAbstractionRules *ptr = new WorkingWithAbstractionRules(400, 500, 600);
    ptr->display();
    delete ptr;

    // Create an object of WorkingWithInheritance
    WorkingWithInheritance inheritanceObj(1, 2, 3);
    inheritanceObj.display();
    cout << "Sizeof inheritanceObj:  " << sizeof(inheritanceObj) << endl;

    DerivedClass derivedObj(10, 20, 30);
    derivedObj.displayDerived();

    AnotherDerivedClass anotherDerivedObj(40, 50, 60);
    anotherDerivedObj.displayAnotherDerived();

    PrivateDerivedClass privateDerivedObj(70, 80, 90);
    privateDerivedObj.displayPrivateDerived();

    return 0;
}