#include "SampleClass.hpp"
#include "StaticConstRefMembersExamples.hpp"
#include "WorkingWithAbsractionRules.hpp"
#include "WorkingWithInheritance.hpp"
#include "WorkingWithPolymorphysim.hpp"
#include "WorkingWithAbstractionClass.hpp"
#include "WorkingWithBasicSyntaxandTypesinCPP.hpp"
#include <iostream>
#include <memory>

int main()
{

    // // Create an object of SampleClass using parameterized constructor
    // SampleClass obj(10, 20.5, 'A', 30.7f);

    // cout << "Sizeof obj:  " << sizeof(obj) << endl;

    // cout << "Address of a: " << &obj.a << endl;
    // cout << "Address of b: " << &obj.b << endl;
    // cout << "Address of c: " << static_cast<void *>(&obj.c) << endl;
    // cout << "Address of d: " << &obj.d << endl;

    // cout << "Value of a: " << obj.a << endl;
    // cout << "Value of b: " << obj.b << endl;
    // cout << "Value of c: " << obj.c << endl;
    // cout << "Value of d: " << obj.d << endl;

    // // Create an object of StaticConstRefMembersExamples
    // StaticConstRefMembersExamples example(42, 84, 168);
    // example.display();
    // cout << "Sizeof example:  " << sizeof(example) << endl;
    // cout << " Static Member : " << StaticConstRefMembersExamples::staticMember << endl;

    // // Create an object of WorkingWithAbstractionRules
    // WorkingWithAbstractionRules abstractionObj;
    // abstractionObj.setValue(100);
    // abstractionObj.setProtectedValue(200);
    // abstractionObj.publicMember = 300;
    // abstractionObj.display();

    // WorkingWithAbstractionRules *ptr = new WorkingWithAbstractionRules(400, 500, 600);
    // ptr->display();
    // delete ptr;

    // // Create an object of WorkingWithInheritance
    // WorkingWithInheritance inheritanceObj(1, 2, 3);
    // inheritanceObj.display();
    // cout << "Sizeof inheritanceObj:  " << sizeof(inheritanceObj) << endl;

    // DerivedClass derivedObj(10, 20, 30);
    // derivedObj.displayDerived();

    // AnotherDerivedClass anotherDerivedObj(40, 50, 60);
    // anotherDerivedObj.displayAnotherDerived();

    // PrivateDerivedClass privateDerivedObj(70, 80, 90);
    // privateDerivedObj.displayPrivateDerived();

    // Polymorphism Example
    // Dog dog;
    // Cat cat;
    // makeSound(dog); // Outputs: Dog barks
    // makeSound(cat); // Outputs: Cat meows
    // polymorphismExample polyExample;
    // polyExample.add(5, 10);
    // int ret = polyExample.add(5, 10, 15);
    // cout << "Sum of three integers: " << ret << endl;
    // polyExample.add(5.5, 10.5);
    // // polyExample.add(20);

    // // Demonstrating pointers and dynamic_cast with polymorphism
    // // Base class pointer pointing to derived class object
    // // downcasting
    // std::unique_ptr<Animal> animalPtr = std::make_unique<Dog>();
    // animalPtr->sound(); // Outputs: Dog barks

    // std::unique_ptr<Dog> dogUPtr = std::make_unique<Dog>();
    // Dog *dogPtr = dogUPtr.get();
    // dogPtr->sound(); // Outputs: Dog barks

    // // Demonstrating dynamic_cast: upcasting
    // dogPtr = dynamic_cast<Dog *>(animalPtr.get());
    // if (dogPtr)
    // {
    //     dogPtr->sound(); // Outputs: Dog barks
    // }
    // else
    // {
    //     cout << "Dynamic cast failed." << endl;
    // }

    // std::unique_ptr<Cat> catUPtr = std::make_unique<Cat>();
    // Cat *catPtr = catUPtr.get();
    // catPtr->sound(); // Outputs: Cat meows

    // // Attempting invalid dynamic_cast
    // std::unique_ptr<Animal> animalPtr1 = std::make_unique<Cat>();
    // catPtr = dynamic_cast<Cat *>(animalPtr1.get());
    // if (catPtr)
    // {
    //     catPtr->sound(); // Outputs: Cat meows
    // }
    // else
    // {
    //     cout << "Dynamic cast to Cat failed." << endl;
    // }

    // Animal *animalPtr2;
    // animalPtr2 = dogPtr; // Upcasting is safe and implicit
    // cout << "implicit upcasting: ";
    // animalPtr2->sound(); // Outputs: Dog barks

    // Animal &animalRef = *catPtr; // Upcasting is safe and implicit
    // cout << "implicit upcasting using reference: ";
    // animalRef.sound(); // Outputs: Cat meows

    // Animal &animalRef1 = *dogPtr; // Upcasting is safe and implicit
    // cout << "implicit upcasting using reference: ";
    // animalRef1.sound(); // Outputs: Dog barks

    // Animal &animalRef2 = dynamic_cast<Animal &>(*catPtr); // Upcasting is safe and implicit
    // cout << "explicit upcasting using reference: ";
    // animalRef2.sound(); // Outputs: Cat meows

    // Animal &animalRef3 = dynamic_cast<Animal &>(*dogPtr); // Upcasting is safe and implicit
    // cout << "explicit upcasting using reference: ";
    // animalRef3.sound(); // Outputs: Dog barks

    // Animal *animalPtr3;
    // animalPtr3 = &dog; // Upcasting is safe and implicit
    // cout << "implicit upcasting using object: ";
    // animalPtr3->sound(); // Outputs: Dog barks

    // Animal *animalPtr4;
    // animalPtr4 = &cat; // Upcasting is safe and implicit
    // cout << "implicit upcasting using object: ";
    // animalPtr4->sound(); // Outputs: Cat meows

    // // smart pointers with polymorphism
    // std::unique_ptr<Animal> uniqueDogPtr = std::make_unique<Dog>();
    // cout << "using unique_ptr: " << endl;
    // uniqueDogPtr->sound(); // Outputs: Dog barks

    // std::shared_ptr<Animal> sharedCatPtr = std::make_shared<Cat>();
    // cout << "using shared_ptr: " << endl;
    // sharedCatPtr->sound(); // Outputs: Cat meows

    // // tricky dynamic_cast with smart pointers
    // std::shared_ptr<Animal> sharedAnimalPtr = std::make_shared<Dog>();
    // std::shared_ptr<Dog> sharedDogPtr = std::dynamic_pointer_cast<Dog>(sharedAnimalPtr);
    // cout << "using dynamic_pointer_cast with shared_ptr: " << endl;
    // if (sharedDogPtr)
    // {
    //     sharedDogPtr->sound(); // Outputs: Dog barks
    // }
    // else
    // {
    //     cout << "Dynamic cast with shared_ptr failed." << endl;
    // }

    // // Smart pointers (`dogUPtr`, `catUPtr`, `animalPtr`, `animalPtr1`) manage lifetime automatically.

    // // WorkingWithAbstractionClass Example
    // // Cannot create an object of abstract class
    // // WorkingWithAbstractionClass abstractionClassObj; // This will cause a compilation error
    // // Create an object of DerivedFromAbstraction and invoke display
    // DerivedFromAbstraction derivedAbstractionObj;
    // cout << "abstract concrete class example: " << endl;
    // derivedAbstractionObj.display();

    // WorkingWithBasicSyntaxandTypesinCPP Examples
    WorkingWithBasicSyntaxandTypesinCPP syntaxObj;
    syntaxObj.demonstrateBasics();
    syntaxObj.showAlias();
    syntaxObj.showTypedef();
    syntaxObj.compareTypedefAndUsing();
    syntaxObj.demonstrateMoreBasics();
    syntaxObj.demonstrateTypeCasting();
    syntaxObj.demonstrateConstCast();
    syntaxObj.demonstrateStaticCast();
    syntaxObj.demonstrateDecltypeWithExpressions();
    syntaxObj.demonstrateRangeBasedForLoop();
    syntaxObj.demonstrateStructuredBindings();
    syntaxObj.demonstrateStdArray();
    syntaxObj.demonstrateNullptrVsNULL();
    syntaxObj.demonstrateStringLiterals();
    syntaxObj.demonstrateReferences();
    syntaxObj.demonstrateConstReferences();
    syntaxObj.demonstrateMutableKeyword();
    syntaxObj.demonstrateInlineFunction();
    syntaxObj.demonstrateConstReferenceInFunction(500);
    syntaxObj.demonstrateMoveSemantics();
    syntaxObj.demonstrateInitializerLists();
    syntaxObj.demonstrateUniformInitialization();
    syntaxObj.demonstrateNestedTypes();
    syntaxObj.demonstrateDynamicCast();
    syntaxObj.convertUsingReinterpretCast();
    syntaxObj.upcastDowncastExample();
    syntaxObj.demonstrateEnum();

    return 0;
}