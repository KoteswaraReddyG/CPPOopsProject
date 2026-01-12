#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class WorkingWithBasicSyntaxandTypesinCPP
{
public:
    WorkingWithBasicSyntaxandTypesinCPP()
    {
        cout << "WorkingWithBasicSyntaxandTypesinCPP Constructor called." << endl;
    }
    ~WorkingWithBasicSyntaxandTypesinCPP()
    {
        cout << "WorkingWithBasicSyntaxandTypesinCPP Destructor called." << endl;
    }
    void demonstrateBasics()
    {
        cout << "Demonstrating basic syntax and types in C++." << endl;

        // Basic data types
        int integerVar = 10;
        double doubleVar = 20.5;
        char charVar = 'A';
        bool boolVar = true;

        cout << "Integer: " << integerVar << endl;
        cout << "Double: " << doubleVar << endl;
        cout << "Character: " << charVar << endl;
        cout << "Boolean: " << boolVar << endl;

        // Control structures
        if (boolVar)
        {
            cout << "Boolean variable is true." << endl;
        }

        for (int i = 0; i < 5; ++i)
        {
            cout << "For loop iteration: " << i << endl;
        }
    }

    // typedef, alias example
    using IntegerAlias = int;
    void showAlias()
    {
        IntegerAlias aliasVar = 100;
        cout << "Alias variable value: " << aliasVar << endl;
    }

    typedef double DoubleType;
    void showTypedef()
    {
        DoubleType typedefVar = 99.99;
        cout << "Typedef variable value: " << typedefVar << endl;
    }

    // show what is the difference between typedef and using
    void compareTypedefAndUsing()
    {
        cout << "Both typedef and using create type aliases, but using is more versatile and can handle templates." << endl;
    }

    // You can add more basic syntax and type-related functionalities as needed.
    void demonstrateMoreBasics()
    {
        cout << "Demonstrating more basic syntax and types in C++." << endl;
        // Example: Arrays
        int arr[5] = {1, 2, 3, 4, 5};
        cout << "Array elements: ";
        for (int i = 0; i < 5; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Example: Strings
        string str = "Hello, C++!";
        cout << "String: " << str << endl;
    }

    // example function to demonstrate type casting
    void demonstrateTypeCasting()
    {
        int intVar = 10;
        double doubleVar = static_cast<double>(intVar);
        cout << "Type casting example: " << intVar << " -> " << doubleVar << endl;
    }

    // constexpr function example
    constexpr int square(int x)
    {
        return x * x;
    }

    // const_cast example
    void demonstrateConstCast()
    {
        int constVar = 50; // Removed const to allow modification
        cout << "Const variable value: " << constVar << endl;
        int &normalVar = const_cast<int &>(constVar); // Proper const_cast usage
        normalVar = 60;                               // This is allowed
        cout << "Normal variable after const_cast: " << normalVar << endl;
    }

    // static_cast example
    void demonstrateStaticCast()
    {
        double doubleVar = 9.99;
        int intVar = static_cast<int>(doubleVar);
        cout << "Static cast example: " << doubleVar << " -> " << intVar << endl;
    }

    // reinterpret_cast example
    void demonstrateReinterpretCast()
    {
        int intVar = 65;
        char *charPtr = reinterpret_cast<char *>(&intVar);
        cout << "Reinterpret cast example: " << *charPtr << endl;
    }

    // dynamic_cast example
    class Base
    {
    public:
        virtual ~Base() = default; // Ensure polymorphic behavior
        virtual void baseFunction() = 0;
    };
    class Derived : public Base
    {
    public:
        void baseFunction() override
        {
            cout << "Derived class function called." << endl;
        }
    };

    void demonstrateDynamicCast()
    {
        Base *basePtr = new Derived();
        Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
        if (derivedPtr)
        {
            derivedPtr->baseFunction();
        }
        delete basePtr;
    }

    // convert using reinterpret_cast from int pointer to char pointer
    void convertUsingReinterpretCast()
    {
        int intValue = 100;
        int *intPtr = &intValue;
        char *charPtr = reinterpret_cast<char *>(intPtr);
        cout << "Reinterpret cast from int* to char*: " << static_cast<void *>(charPtr) << endl;
    }

    // upcast and downcast example using reinterpret_cast
    void upcastDowncastExample()
    {
        Derived derivedObj;
        Base *basePtr = &derivedObj;                                // Upcasting
        Derived *derivedPtr = reinterpret_cast<Derived *>(basePtr); // Downcasting
        derivedPtr->baseFunction();
    }

    // example on enumerations
    enum Color
    {
        RED,
        GREEN,
        BLUE
    };
    void demonstrateEnum()
    {
        Color color = GREEN;
        switch (color)
        {
        case RED:
            cout << "Color is RED" << endl;
            break;
        case GREEN:
            cout << "Color is GREEN" << endl;
            break;
        case BLUE:
            cout << "Color is BLUE" << endl;
            break;
        default:
            cout << "Unknown Color" << endl;
            break;
        }
    }

    // enum class example with scoped enumerations
    // this is more type-safe than traditional enums
    enum class Direction
    {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    void demonstrateEnumClass()
    {
        Direction dir = Direction::EAST;
        switch (dir)
        {
        case Direction::NORTH:
            cout << "Direction is NORTH" << endl;
            break;
        case Direction::SOUTH:
            cout << "Direction is SOUTH" << endl;
            break;
        case Direction::EAST:
            cout << "Direction is EAST" << endl;
            break;
        case Direction::WEST:
            cout << "Direction is WEST" << endl;
            break;
        default:
            cout << "Unknown Direction" << endl;
            break;
        }
    }

    // enum class with underlying type
    enum class Status : uint8_t
    {
        SUCCESS = 1,
        FAILURE = 0
    };

    void demonstrateEnumClassWithUnderlyingType()
    {
        Status status = Status::SUCCESS;
        if (status == Status::SUCCESS)
        {
            cout << "Status is SUCCESS" << endl;
        }
        else
        {
            cout << "Status is FAILURE" << endl;
        }
    }

    // Enumeration with array mapping or vector mapping
    enum Fruit
    {
        APPLE,
        BANANA,
        ORANGE,
        FRUIT_COUNT
    };

    void demonstrateEnumWithArrayMapping()
    {
        const char *fruitNames[FRUIT_COUNT] = {"Apple", "Banana", "Orange"};
        for (int i = 0; i < FRUIT_COUNT; ++i)
        {
            cout << "Fruit " << i << ": " << fruitNames[i] << endl;
        }
    }
    // access array mapping using enum or vector mapping
    void demonstrateEnumWithVectorMapping()
    {
        vector<string> fruitNames = {"Apple", "Banana", "Orange"};
        for (size_t i = 0; i < fruitNames.size(); ++i)
        {
            cout << "Fruit " << i << ": " << fruitNames[i] << endl;
        }

        fruitNames[Fruit::BANANA] = "Yellow Banana";
        cout << "Updated Fruit BANANA: " << fruitNames[Fruit::BANANA] << endl;

        fruitNames[Fruit::ORANGE] = "Citrus Orange";
        cout << "Updated Fruit ORANGE: " << fruitNames[Fruit::ORANGE] << endl;
    }

    // demonstrate usage of nullptr
    void demonstrateNullptr()
    {
        int *ptr = nullptr;
        if (ptr == nullptr)
        {
            cout << "Pointer is null." << endl;
        }
        else
        {
            cout << "Pointer is not null." << endl;
        }
    }

    // demonstrate usage of auto keyword
    void demonstrateAutoKeyword()
    {
        auto intVar = 42;
        auto doubleVar = 3.14;
        auto strVar = string("Auto keyword in C++");
        cout << "Auto int: " << intVar << ", Auto double: " << doubleVar << ", Auto string: " << strVar << endl;
    }

    // demonstrate usage of decltype keyword
    void demonstrateDecltypeKeyword()
    {
        int x = 10;
        decltype(x) y = 20; // y is of type int
        cout << "Decltype variable y: " << y << endl;
    }

    // using decltype with expressions
    void demonstrateDecltypeWithExpressions()
    {
        int a = 5;
        double b = 6.7;
        decltype(a + b) c = a + b; // c is of type double
        cout << "Decltype with expression (a + b): " << c << endl;
    }

    // demonstrate usage of range-based for loop
    void demonstrateRangeBasedForLoop()
    {
        vector<int> numbers = {1, 2, 3, 4, 5};
        cout << "Range-based for loop output: ";
        for (const auto &num : numbers)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // demonstrate usage of structured bindings
    void demonstrateStructuredBindings()
    {
        pair<int, string> person = {1, "Alice"};
        auto [id, name] = person; // Structured bindings
        cout << "Structured Bindings - ID: " << id << ", Name: " << name << endl;
    }

    // demonstrate usage of std::array
    void demonstrateStdArray()
    {
        array<int, 5> arr = {10, 20, 30, 40, 50};
        cout << "std::array elements: ";
        for (const auto &elem : arr)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    // example to demonstrate nullptr vs NULL
    void demonstrateNullptrVsNULL()
    {
        int *ptr1 = nullptr; // C++11 nullptr
        int *ptr2 = NULL;    // Traditional NULL
        if (ptr1 == nullptr)
        {
            cout << "ptr1 is nullptr." << endl;
        }
        if (ptr2 == NULL)
        {
            cout << "ptr2 is NULL." << endl;
        }
    }

    // example to demonstrate string literals and raw string literals
    void demonstrateStringLiterals()
    {
        const char *regularString = "This is a regular string.\nNew line here.";
        const char *rawString = R"(This is a raw string.\nNo new line here.)";
        cout << "Regular String Literal: " << regularString << endl;
        cout << "Raw String Literal: " << rawString << endl;
    }

    // example to demonstrate sizeof operator
    void demonstrateSizeofOperator()
    {
        cout << "Size of int: " << sizeof(int) << " bytes" << endl;
        cout << "Size of double: " << sizeof(double) << " bytes" << endl;
        cout << "Size of char: " << sizeof(char) << " bytes" << endl;
        cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    }

    // example to demonstrate typeid operator
    void demonstrateTypeidOperator()
    {
        int intVar = 10;
        double doubleVar = 20.5;
        cout << "Type of intVar: " << typeid(intVar).name() << endl;
        cout << "Type of doubleVar: " << typeid(doubleVar).name() << endl;
    }

    // example to demonstrate nullptr_t type
    void demonstrateNullptrTType()
    {
        nullptr_t nullVar = nullptr;
        if (nullVar == nullptr)
        {
            cout << "nullptr_t variable is null." << endl;
        }
    }

    // example to demonstrate struct and union
    struct Person
    {
        string name;
        int age;
        Person(string n, int a) : name(n), age(a) {}
    };

    union Data
    {
        int intValue;
        float floatValue;
        Data() { intValue = 0; } // Constructor to initialize union
    };

    void demonstrateStructAndUnion()
    {
        Person person("Bob", 30);
        cout << "Struct Person - Name: " << person.name << ", Age: " << person.age << endl;

        Data data;
        data.intValue = 42;
        cout << "Union Data - intValue: " << data.intValue << endl;
        data.floatValue = 3.14f; // Overwrites intValue
        cout << "Union Data - floatValue: " << data.floatValue << endl;
    }

    // example to demonstrate pointer arithmetic
    void demonstratePointerArithmetic()
    {
        int arr[] = {10, 20, 30, 40, 50};
        int *ptr = arr;
        cout << "Pointer Arithmetic: ";
        for (int i = 0; i < 5; ++i)
        {
            cout << *(ptr + i) << " "; // Accessing array elements using pointer arithmetic
        }
        cout << endl;
    }

    // example to demonstrate references
    void demonstrateReferences()
    {
        int var = 100;
        int &refVar = var; // Reference to var
        cout << "Original var: " << var << endl;
        refVar = 200; // Modifying var through reference
        cout << "Modified var through reference: " << var << endl;
    }

    // example to demonstrate const references
    void demonstrateConstReferences()
    {
        const int var = 100;
        const int &refVar = var; // Const reference to var
        cout << "Const reference value: " << refVar << endl;
    }

    // example to demonstrate mutable keyword
    class MutableExample
    {
    public:
        mutable int mutableVar;
        MutableExample(int val) : mutableVar(val) {}
        void modifyMutableVar() const
        {
            mutableVar += 10; // Allowed due to mutable keyword
        }
    };

    void demonstrateMutableKeyword()
    {
        MutableExample example(50);
        cout << "Before modifying mutableVar: " << example.mutableVar << endl;
        example.modifyMutableVar();
        cout << "After modifying mutableVar: " << example.mutableVar << endl;
    }

    // example to demonstrate inline functions
    inline int add(int a, int b)
    {
        return a + b;
    }

    void demonstrateInlineFunction()
    {
        int sum = add(10, 20);
        cout << "Inline function add result: " << sum << endl;
    }

    // example to demonstrate const references in function parameters
    void demonstrateConstReferenceInFunction(const int &value)
    {
        cout << "Const reference parameter value: " << value << endl;
        // value += 10; // This will cause a compilation error
        int val = const_cast<int &>(value); // Using const_cast to modify
        val += 10;
        cout << "Modified value after const_cast: " << val << endl;
    }

    // example to demonstrate move semantics
    void demonstrateMoveSemantics()
    {
        string str = "Hello, Move Semantics!";
        cout << "Original string: " << str << endl;
        string movedStr = std::move(str); // Move str to movedStr
        cout << "Moved string: " << movedStr << endl;
        cout << "Original string after move: " << str << endl; // str is in valid state

        int &&rvalueRef = 100; // Rvalue reference
        cout << "Rvalue reference value: " << rvalueRef << endl;

        int &&anotherRvalueRef = std::move(rvalueRef);
        cout << "Another Rvalue reference value: " << anotherRvalueRef << endl;

        int normalVar = 200;
        // int &&invalidRvalueRef = normalVar; // This will cause a compilation error

        int &refVar = normalVar; // Lvalue reference
        cout << "Lvalue reference value: " << refVar << endl;

        refVar = 300;
        cout << "Modified normalVar through lvalue reference: " << normalVar << endl;

        refVar = anotherRvalueRef; // Assigning rvalue reference to lvalue reference
        cout << "Assigned rvalueRef to lvalueRef, normalVar: " << normalVar << endl;
        cout << "anotherRvalueRef remains: " << anotherRvalueRef << endl;
        cout << "rvalueRef remains: " << rvalueRef << endl;
        cout << "movedStr remains: " << movedStr << endl;
        cout << "refVar remains: " << refVar << endl;

        int &refToRvalue = rvalueRef; // Binding lvalue reference to rvalue reference
        cout << "Lvalue reference bound to rvalue reference: " << refToRvalue << endl;
    }

    // example to demonstrate initializer lists
    void demonstrateInitializerLists()
    {
        vector<int> vec = {1, 2, 3, 4, 5};
        cout << "Initializer list vector elements: ";
        for (const auto &elem : vec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    // example to demonstrate uniform initialization
    void demonstrateUniformInitialization()
    {
        int intVar{10};
        double doubleVar{20.5};
        string strVar{"Uniform Initialization in C++"};
        cout << "Uniformly initialized int: " << intVar << ", double: " << doubleVar << ", string: " << strVar << endl;
    }

    // example to demonstrate nested types
    class OuterClass
    {
    public:
        class InnerClass
        {
        public:
            void display() const
            {
                cout << "InnerClass display method called." << endl;
            }
        };
    };

    void demonstrateNestedTypes()
    {
        OuterClass::InnerClass innerObj;
        innerObj.display();
    }
};

// Note: This file is currently a placeholder for the WorkingWithBasicSyntaxandTypesinCPP class.
// You can implement more basic syntax and type-related functionalities here as per your project requirements.