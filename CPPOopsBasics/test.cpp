#include <gtest/gtest.h>
#include <tuple>
#include "SampleClass.hpp"
#include "StaticConstRefMembersExamples.hpp"
#include "WorkingWithInheritance.hpp"

// Tests for SampleClass
class SampleClassTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Initialization code that runs before each test
    }

    void TearDown() override
    {
        // Cleanup code that runs after each test
    }
};

TEST_F(SampleClassTest, DefaultConstructor)
{
    SampleClass obj;
    EXPECT_EQ(obj.a, 0);
    EXPECT_EQ(obj.b, 0.0);
    EXPECT_EQ(obj.c, '\0');
    EXPECT_EQ(obj.d, 0.0f);
}

TEST_F(SampleClassTest, ParameterizedConstructor)
{
    SampleClass obj(42, 3.14, 'A', 2.71f);
    EXPECT_EQ(obj.a, 42);
    EXPECT_DOUBLE_EQ(obj.b, 3.14);
    EXPECT_EQ(obj.c, 'A');
    EXPECT_FLOAT_EQ(obj.d, 2.71f);
}

TEST_F(SampleClassTest, MemberModification)
{
    SampleClass obj(10, 5.5, 'Z', 1.5f);
    obj.a = 100;
    obj.b = 9.99;
    obj.c = 'X';
    obj.d = 3.33f;

    EXPECT_EQ(obj.a, 100);
    EXPECT_DOUBLE_EQ(obj.b, 9.99);
    EXPECT_EQ(obj.c, 'X');
    EXPECT_FLOAT_EQ(obj.d, 3.33f);
}

// Parameterized tests for SampleClass
class SampleClassParamTest : public ::testing::TestWithParam<std::tuple<int, double, char, float>>
{
};

TEST_P(SampleClassParamTest, ConstructorSetsMembers)
{
    auto params = GetParam();
    int ai;
    double bd;
    char cc;
    float dd;
    std::tie(ai, bd, cc, dd) = params;

    SampleClass obj(ai, bd, cc, dd);
    EXPECT_EQ(obj.a, ai);
    EXPECT_DOUBLE_EQ(obj.b, bd);
    EXPECT_EQ(obj.c, cc);
    EXPECT_FLOAT_EQ(obj.d, dd);
}

INSTANTIATE_TEST_SUITE_P(
    SampleClassValues,
    SampleClassParamTest,
    ::testing::Values(
        std::make_tuple(0, 0.0, '\0', 0.0f),
        std::make_tuple(1, 1.1, 'a', 2.2f),
        std::make_tuple(42, 3.14, 'A', 2.71f)));

// Tests for StaticConstRefMembersExamples
class StaticConstRefMembersTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        StaticConstRefMembersExamples::staticMember = 0;
    }

    void TearDown() override
    {
        StaticConstRefMembersExamples::staticMember = 0;
    }
};

TEST_F(StaticConstRefMembersTest, ConstructorInitialization)
{
    int refValue = 50;
    StaticConstRefMembersExamples obj(10, refValue, 20);

    EXPECT_EQ(obj.constMember, 10);
    // The reference member should point to a valid value
    EXPECT_TRUE(&obj.refMember != nullptr);
    EXPECT_EQ(StaticConstRefMembersExamples::staticMember, 20);
}

TEST_F(StaticConstRefMembersTest, StaticMemberSharedAcrossInstances)
{
    int refValue1 = 100;
    int refValue2 = 200;

    StaticConstRefMembersExamples obj1(5, refValue1, 15);
    EXPECT_EQ(StaticConstRefMembersExamples::staticMember, 15);

    StaticConstRefMembersExamples obj2(10, refValue2, 25);
    EXPECT_EQ(StaticConstRefMembersExamples::staticMember, 25);

    // Static member should be 25 for both objects
    EXPECT_EQ(StaticConstRefMembersExamples::staticMember, 25);
}

TEST_F(StaticConstRefMembersTest, ConstMemberImmutable)
{
    int refValue = 30;
    StaticConstRefMembersExamples obj(42, refValue, 99);

    // Const member should be immutable, only checking its value
    EXPECT_EQ(obj.constMember, 42);
}

// Tests for WorkingWithInheritance
class WorkingWithInheritanceTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Initialization code that runs before each test
    }
};

TEST_F(WorkingWithInheritanceTest, ParameterizedConstructor)
{
    WorkingWithInheritance obj(10, 20, 30);
    EXPECT_EQ(obj.getExampleMember(), 10);
    EXPECT_EQ(obj.getProtectedMember(), 20);
    EXPECT_EQ(obj.getPrivateMember(), 30);
}

TEST_F(WorkingWithInheritanceTest, SettersAndGetters)
{
    WorkingWithInheritance obj(0, 0, 0);

    obj.setExampleMember(100);
    EXPECT_EQ(obj.getExampleMember(), 100);

    obj.setProtectedMember(200);
    EXPECT_EQ(obj.getProtectedMember(), 200);

    obj.setPrivateMember(300);
    EXPECT_EQ(obj.getPrivateMember(), 300);
}

TEST_F(WorkingWithInheritanceTest, DisplayMethod)
{
    WorkingWithInheritance obj(50, 60, 70);
    // Just verify that display() can be called without errors
    obj.display();
    EXPECT_EQ(obj.getExampleMember(), 50);
}

// Parameterized tests for WorkingWithInheritance constructors
class WorkingWithInheritanceParamTest : public ::testing::TestWithParam<std::tuple<int, int, int>>
{
};

TEST_P(WorkingWithInheritanceParamTest, ConstructorSetsMembers)
{
    int ex, prot, priv;
    std::tie(ex, prot, priv) = GetParam();
    WorkingWithInheritance obj(ex, prot, priv);
    EXPECT_EQ(obj.getExampleMember(), ex);
    EXPECT_EQ(obj.getProtectedMember(), prot);
    EXPECT_EQ(obj.getPrivateMember(), priv);
}

INSTANTIATE_TEST_SUITE_P(
    WorkingWithInheritanceCtorValues,
    WorkingWithInheritanceParamTest,
    ::testing::Values(
        std::make_tuple(0, 0, 0),
        std::make_tuple(5, 10, 15),
        std::make_tuple(100, 200, 300)));

// Parameterized tests for setters/getters
class WorkingWithInheritanceSetterTest : public ::testing::TestWithParam<std::tuple<int, int, int>>
{
};

TEST_P(WorkingWithInheritanceSetterTest, SettersUpdateMembers)
{
    int exSet, protSet, privSet;
    std::tie(exSet, protSet, privSet) = GetParam();
    WorkingWithInheritance obj(0, 0, 0);
    obj.setExampleMember(exSet);
    obj.setProtectedMember(protSet);
    obj.setPrivateMember(privSet);

    EXPECT_EQ(obj.getExampleMember(), exSet);
    EXPECT_EQ(obj.getProtectedMember(), protSet);
    EXPECT_EQ(obj.getPrivateMember(), privSet);
}

INSTANTIATE_TEST_SUITE_P(
    WorkingWithInheritanceSetterValues,
    WorkingWithInheritanceSetterTest,
    ::testing::Values(
        std::make_tuple(1, 2, 3),
        std::make_tuple(10, 20, 30),
        std::make_tuple(-5, -10, -15)));

// Tests for DerivedClass
class DerivedClassTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Initialization code that runs before each test
    }
};

TEST_F(DerivedClassTest, DerivedParameterizedConstructor)
{
    DerivedClass obj(50, 60, 70);
    EXPECT_EQ(obj.getExampleMember(), 50);
    EXPECT_EQ(obj.getProtectedMember(), 60);
    EXPECT_EQ(obj.getPrivateMember(), 70);
}

TEST_F(DerivedClassTest, DerivedInheritsMethods)
{
    DerivedClass obj(15, 25, 35);

    obj.setExampleMember(150);
    EXPECT_EQ(obj.getExampleMember(), 150);

    obj.setProtectedMember(250);
    EXPECT_EQ(obj.getProtectedMember(), 250);

    obj.setPrivateMember(350);
    EXPECT_EQ(obj.getPrivateMember(), 350);
}

TEST_F(DerivedClassTest, DerivedInheritsDisplay)
{
    DerivedClass obj(100, 110, 120);
    // Just verify that display() can be called (inherited from base)
    obj.display();
    EXPECT_EQ(obj.getExampleMember(), 100);
}

// Main function to run all tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
