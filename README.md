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
- `CPPOopsBasics/Main.cpp`: runner that constructs and invokes the above examples; edit it to experiment.

**What the examples demonstrate**
- Construction / destruction messages for objects and classes.
- Correct member initialization order to avoid compiler warnings (`-Wreorder`).
- Use of `dynamic_cast` for safe downcasts and `dynamic_pointer_cast` for `shared_ptr`.
- Smart pointer usage (`unique_ptr`, `shared_ptr`) vs raw pointer ownership and pitfalls (double-delete, deleting stack-allocated objects).

**Notes & Tips**
- Use `bazel run` to see `std::cout` output. `bazel build` only compiles.
- If you see unexpected termination, check ownership of pointers in `CPPOopsBasics/Main.cpp` — prefer smart pointers to manage lifetime.
- To ensure deterministic flush of `cout`, use `std::endl` or `std::cout.setf(std::ios::unitbuf);` in `main()`.
