# CPPOopsProject

This repository contains small C++ examples demonstrating OOP concepts: classes, access specifiers, static/const/ref members, inheritance, polymorphism and ownership patterns.

**Prerequisites**
- **Bazel** (tested with Bazel 5+)
- A C++ compiler supporting C++11 or later (g++ / clang++)
- Git

**Clone**
- Clone the repository:

```
git clone <repository-url>
cd CPPOopsProject
```

**Build & Run**
- Build the main binary with Bazel:

```
bazel build //CPPOpsBasics:main
```

- Run the binary and see `cout` output:

```
bazel run //CPPOopsBasics:main
```

- Build and run tests with Bazel (examples included):

```
bazel test --test_output=all //CPPOpsBasics:all
bazel test --test_output=streamed //CPPOpsBasics:all
bazel test --test_output=errors //CPPOopsBasics:all
```

- You can also run the compiled test binary directly (path may vary):

```
./bazel-bin/CPPOopsBasics/cpp_test --gtest_filter=*
./bazel-bin/CPPOopsBasics/cpp_test --gtest_output=xml:report.xml
```

**Where to find examples**
- `CPPOopsBasics/SampleClass.hpp` and `CPPOopsBasics/SampleClass.cpp`: basic class with multiple member types and constructors.
- `CPPOopsBasics/StaticConstRefMembersExamples.hpp` and `.cpp`: examples of static, const and reference members.
- `CPPOopsBasics/WorkingWithAbsractionRules.hpp` and `.cpp`: examples of access specifiers, constructors and member initialization rules.
- `CPPOopsBasics/WorkingWithInheritance.hpp` and `.cpp`: inheritance examples including `DerivedClass`, `AnotherDerivedClass`, and `PrivateDerivedClass`.
- `CPPOopsBasics/WorkingWithPolymorphysim.hpp` and `.cpp`: polymorphism examples with base `Animal` and derived `Dog`/`Cat`, `dynamic_cast`, smart pointers and a `polymorphismExample` class demonstrating overloads.
- `CPPOopsBasics/WorkingWithAbstractionClass.hpp` and `.cpp`: abstract base class and a concrete derived implementation demonstrating pure virtual functions.
- `CPPOopsBasics/WorkingWithBasicSyntaxandTypesinCPP.hpp` and `.cpp`: comprehensive examples of basic C++ syntax, type casting, enumerations, and modern C++ keywords.
- `CPPOopsBasics/Main.cpp`: runner that constructs and invokes the above examples; edit it to experiment.

**What the examples demonstrate**

**Object-Oriented Programming**
- Construction / destruction messages for objects and classes.
- Correct member initialization order to avoid compiler warnings (`-Wreorder`).
- Access specifiers (`public`, `private`, `protected`) and encapsulation.
- Inheritance patterns (public, private, protected derivation).
- Polymorphism with virtual functions and pure virtual functions.
- Use of `dynamic_cast` for safe downcasts and `dynamic_pointer_cast` for `shared_ptr`.

**Type System & Advanced Features**
- Basic data types (int, double, char, bool) and control structures.
- `typedef` vs `using` for type aliases (using is more versatile for templates).
- Type casting: `static_cast`, `const_cast`, `reinterpret_cast`, `dynamic_cast`.
- `constexpr` for compile-time constant expressions.
- `nullptr` for null pointers (safer than NULL or 0).
- `auto` keyword for type deduction.
- `decltype` for deducing types from expressions at compile-time.
- Enumerations (`enum`) and scoped enums (`enum class`).
- Enums with underlying types (e.g., `enum class Status : uint8_t`).

**Memory Management & Smart Pointers**
- Smart pointer usage (`unique_ptr`, `shared_ptr`) vs raw pointer ownership.
- Pitfalls of raw pointers (double-delete, deleting stack-allocated objects).
- Reference counting with `shared_ptr` and exclusive ownership with `unique_ptr`.

**Code Examples**

*Type Casting Examples:*
```cpp
// Static cast: type conversion with compile-time checking
int intVar = 10;
double doubleVar = static_cast<double>(intVar);  // 10 -> 10.0

// Const cast: remove const/volatile qualifiers (use with caution)
int normalVar = 50;
int& ref = const_cast<int&>(normalVar);
ref = 60;  // Now modifiable through reference

// Reinterpret cast: low-level bit reinterpretation (dangerous)
int intValue = 65;
char* charPtr = reinterpret_cast<char*>(&intValue);

// Dynamic cast: safe downcasting in polymorphic hierarchies
Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr) {
    derivedPtr->derivedFunction();  // Safe downcast
}
```

*Auto & Decltype Examples:*
```cpp
// auto: type deduced from initializer
auto intVar = 42;           // int
auto doubleVar = 3.14;      // double
auto strVar = string("test");  // std::string

// decltype: type deduced from expression
int x = 10;
decltype(x) y = 20;  // y is int

int a = 5;
double b = 6.7;
decltype(a + b) c = a + b;  // c is double (int + double = double)
```

*Enumeration Examples:*
```cpp
// Traditional enum
enum Color { RED, GREEN, BLUE };
Color color = GREEN;

// Scoped enum (type-safe, prevents name collisions)
enum class Direction : uint8_t {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
};
Direction dir = Direction::EAST;

// Enum with array/vector mapping
enum Fruit { APPLE, BANANA, ORANGE, FRUIT_COUNT };
vector<string> fruitNames = {"Apple", "Banana", "Orange"};
cout << fruitNames[BANANA];  // Access by enum value
```

*Smart Pointer Examples:*
```cpp
// unique_ptr: exclusive ownership
unique_ptr<MyClass> ptr1(new MyClass());  // Automatically deleted when ptr1 goes out of scope

// shared_ptr: shared ownership with reference counting
shared_ptr<MyClass> ptr2 = make_shared<MyClass>();
shared_ptr<MyClass> ptr3 = ptr2;  // Reference count increases
// Objects deleted when last shared_ptr is destroyed

// dynamic_pointer_cast: safe casting for shared_ptr
shared_ptr<Base> basePtr = make_shared<Derived>();
shared_ptr<Derived> derivedPtr = dynamic_pointer_cast<Derived>(basePtr);
if (derivedPtr) {
    derivedPtr->derivedFunction();
}
```

**Key Concepts**

**Inheritance Types:**
- **Public inheritance**: derived class is a specialization of base class (IS-A relationship).
- **Private inheritance**: implementation detail (derived class reuses base class implementation).
- **Protected inheritance**: rarely used; similar to private but allows protected members in derived classes.

**Virtual Functions:**
- Enable polymorphic behavior and runtime method dispatch.
- Pure virtual functions (`virtual void func() = 0;`) create abstract base classes.
- Destructor should be virtual in polymorphic classes to ensure proper cleanup.

**Static Members:**
- Shared across all instances of a class.
- Must be defined and initialized outside the class definition.
- Useful for counters, caches, or class-level data.

**Const Members:**
- Cannot be modified after initialization.
- Must be initialized in the member initialization list of constructors.
- `constexpr` allows evaluation at compile-time for optimization.

**Notes & Tips**
- Use `bazel run` to see `std::cout` output. `bazel build` only compiles.
- If you see unexpected termination, check ownership of pointers in `CPPOopsBasics/Main.cpp` — prefer smart pointers to manage lifetime.
- To ensure deterministic flush of `cout`, use `std::endl` or `std::cout.setf(std::ios::unitbuf);` in `main()`.
- Use `enum class` instead of traditional `enum` for better type safety and to avoid name collisions.
- Prefer `auto` and `decltype` in modern C++ for cleaner, more maintainable code.
- Always use `virtual` destructors in base classes that may be deleted polymorphically.
- Use `make_unique()` and `make_shared()` instead of `new` for exception-safe pointer management.
