#include <iostream>
using namespace std;

// working with expressions and bitwise operators
class WorkingWithExpressionsAndBitWiseOperators
{
public:
    WorkingWithExpressionsAndBitWiseOperators()
    {
        cout << "WorkingWithExpressionsAndBitWiseOperators Constructor called." << endl;
    }
    ~WorkingWithExpressionsAndBitWiseOperators()
    {
        cout << "WorkingWithExpressionsAndBitWiseOperators Destructor called." << endl;
    }

    // You can add methods to demonstrate expressions and bitwise operations here.

    // example method to demonstrate bitwise operations
    void demonstrateBitwiseOperations()
    {
        int a = 5; // 0101 in binary
        int b = 3; // 0011 in binary

        cout << "Bitwise AND (a & b): " << (a & b) << endl;   // Outputs 1 (0001)
        cout << "Bitwise OR (a | b): " << (a | b) << endl;    // Outputs 7 (0111)
        cout << "Bitwise XOR (a ^ b): " << (a ^ b) << endl;   // Outputs 6 (0110)
        cout << "Bitwise NOT (~a): " << (~a) << endl;         // Outputs -6 (inverts bits)
        cout << "Left Shift (a << 1): " << (a << 1) << endl;  // Outputs 10 (1010)
        cout << "Right Shift (a >> 1): " << (a >> 1) << endl; // Outputs 2 (0010)
    }

    // example method to demonstrate expressions
    void demonstrateExpressions()
    {
        int x = 10;
        int y = 20;
        int sum = x + y;
        int product = x * y;
        cout << "Sum of x and y: " << sum << endl;
        cout << "Product of x and y: " << product << endl;
    }

    // more demonstrations on bitwise and expressions can be added here
    void demonstrateMoreBitwiseOperations()
    {
        unsigned int x = 12; // 1100 in binary
        unsigned int y = 5;  // 0101 in binary

        cout << "Bitwise AND (x & y): " << (x & y) << endl;   // Outputs 4 (0100)
        cout << "Bitwise OR (x | y): " << (x | y) << endl;    // Outputs 13 (1101)
        cout << "Bitwise XOR (x ^ y): " << (x ^ y) << endl;   // Outputs 9 (1001)
        cout << "Left Shift (y << 2): " << (y << 2) << endl;  // Outputs 20 (10100)
        cout << "Right Shift (x >> 2): " << (x >> 2) << endl; // Outputs 3 (0011)
    }

    // demonstrate on bit setting and clearing
    void demonstrateBitSettingAndClearing()
    {
        unsigned int num = 0b00001111;                     // Initial number: 15
        unsigned int setBitMask = 0b00010000;              // Mask to set 5th bit
        unsigned int clearBitMask = 0b11101111;            // Mask to clear 5th bit
        num |= setBitMask;                                 // Set 5th bit
        cout << "After setting 5th bit: " << num << endl;  // Outputs 31
        num &= clearBitMask;                               // Clear 5th bit
        cout << "After clearing 5th bit: " << num << endl; // Outputs 15
    }

    // demonstrate on bit swapping
    void demonstrateBitSwapping()
    {
        unsigned int a = 29; // 0001 1101
        unsigned int b = 15; // 0000 1111
        cout << "Before swapping: a = " << a << ", b = " << b << endl;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        cout << "After swapping: a = " << a << ", b = " << b << endl;
    }

    // demonstrate on bit counting
    void demonstrateBitCounting()
    {
        unsigned int num = 29; // 0001 1101
        int count = 0;
        while (num)
        {
            count += num & 1;
            num >>= 1;
        }
        cout << "Number of set bits: " << count << endl; // Outputs 4
    }

    // demonstrate on bit masking
    void demonstrateBitMasking()
    {
        unsigned int num = 0b10101100;  // Initial number: 172
        unsigned int mask = 0b00001111; // Mask to extract lower 4 bits
        unsigned int result = num & mask;
        cout << "Result after applying mask: " << result << endl; // Outputs 12
    }

    // demonstrate on bit rotation
    void demonstrateBitRotation()
    {
        unsigned int num = 0b10010011; // Initial number: 147
        unsigned int leftRotated = (num << 2) | (num >> (8 - 2));
        unsigned int rightRotated = (num >> 2) | (num << (8 - 2));
        cout << "Left rotated by 2: " << leftRotated << endl;   // Outputs 147 rotated left
        cout << "Right rotated by 2: " << rightRotated << endl; // Outputs 147 rotated right
    }

    // demonstrate on bit parity check
    void demonstrateBitParityCheck()
    {
        unsigned int num = 0b10101100; // Initial number: 172
        int parity = 0;
        while (num)
        {
            parity ^= (num & 1);
            num >>= 1;
        }
        if (parity)
            cout << "Number has odd parity." << endl;
        else
            cout << "Number has even parity." << endl;
    }

    // demonstrate on bit field usage
    struct BitFieldExample
    {
        unsigned int field1 : 3; // 3 bits
        unsigned int field2 : 5; // 5 bits
    };

    void demonstrateBitFieldUsage()
    {
        BitFieldExample example;
        example.field1 = 5;  // Max value for 3 bits is 7
        example.field2 = 17; // Max value for 5 bits is 31
        cout << "BitFieldExample - field1: " << example.field1 << ", field2: " << example.field2 << endl;
    }

    // demonstrate on bitwise compound assignment
    void demonstrateBitwiseCompoundAssignment()
    {
        unsigned int num = 0b1100;                       // Initial number: 12
        num &= 0b1010;                                   // Bitwise AND assignment
        cout << "After AND assignment: " << num << endl; // Outputs 8
        num |= 0b0101;                                   // Bitwise OR assignment
        cout << "After OR assignment: " << num << endl;  // Outputs 13
        num ^= 0b0011;                                   // Bitwise XOR assignment
        cout << "After XOR assignment: " << num << endl; // Outputs 14
    }

    // demonstrate on bitwise NOT operation
    void demonstrateBitwiseNOTOperation()
    {
        unsigned int num = 0b00001111; // Initial number: 15
        unsigned int notNum = ~num;
        cout << "Bitwise NOT of num: " << notNum << endl; // Outputs 4294967280 (for 32-bit unsigned int)
    }

    // demonstrate on checking if a number is power of two using bitwise operations
    void demonstratePowerOfTwoCheck()
    {
        unsigned int num = 16; // Change this value to test
        if (num && !(num & (num - 1)))
            cout << num << " is a power of two." << endl;
        else
            cout << num << " is not a power of two." << endl;
    }

    // demonstrate on extracting specific bits from a number
    void demonstrateBitExtraction()
    {
        unsigned int num = 0b11011010;                                // Initial number: 218
        unsigned int extractedBits = (num >> 2) & 0b00001111;         // Extract bits 2 to 5
        cout << "Extracted bits (2 to 5): " << extractedBits << endl; // Outputs 13
    }

    // demonstrate on setting specific bits in a number
    void demonstrateBitSetting()
    {
        unsigned int num = 0b11000000;                                 // Initial number: 192
        unsigned int bitsToSet = 0b00001111;                           // Bits to set
        num |= bitsToSet;                                              // Set specific bits
        cout << "Number after setting specific bits: " << num << endl; // Outputs 207
    }

    // demonstrate on clearing specific bits in a number
    void demonstrateBitClearing()
    {
        unsigned int num = 0b11111111;                                  // Initial number: 255
        unsigned int bitsToClear = 0b00001111;                          // Bits to clear
        num &= ~bitsToClear;                                            // Clear specific bits
        cout << "Number after clearing specific bits: " << num << endl; // Outputs
        cout << "Number after clearing specific bits: " << num << endl; // Outputs 240
    }

    // demonstrate on toggling specific bits in a number
    void demonstrateBitToggling()
    {
        unsigned int num = 0b10101010;                                  // Initial number: 170
        unsigned int bitsToToggle = 0b00001111;                         // Bits to toggle
        num ^= bitsToToggle;                                            // Toggle specific bits
        cout << "Number after toggling specific bits: " << num << endl; // Outputs 185
    }

    // demonstrate on checking if specific bits are set in a number
    void demonstrateBitCheck()
    {
        unsigned int num = 0b11010010;         // Initial number: 210
        unsigned int bitsToCheck = 0b00010010; // Bits to check
        if ((num & bitsToCheck) == bitsToCheck)
            cout << "Specific bits are set." << endl;
        else
            cout << "Specific bits are not set." << endl;
    }

    // demonstrate on creating a bitmask
    void demonstrateBitmaskCreation()
    {
        unsigned int bitmask = 0;
        for (int i = 0; i < 4; ++i)
        {
            bitmask |= (1 << i); // Set first 4 bits
        }
        cout << "Created bitmask with first 4 bits set: " << bitmask << endl; // Outputs 15
    }

    // demonstrate on using bitwise operators in conditional statements
    void demonstrateBitwiseInConditionals()
    {
        unsigned int num = 0b10101010; // Initial number: 170
        if (num & 0b00000001)
        {
            cout << "Least significant bit is set." << endl;
        }
        else
        {
            cout << "Least significant bit is not set." << endl;
        }
    }

    // demonstrate on combining multiple bitwise operations
    void demonstrateCombinedBitwiseOperations()
    {
        unsigned int num = 0b11001100;                            // Initial number: 204
        num = (num & 0b11110000) | ((num & 0b00001111) << 4);     // Swap nibbles
        cout << "Number after swapping nibbles: " << num << endl; // Outputs 204 swapped
    }

    // demonstrate on using bitwise operators with enums
    enum class Fruits
    {
        APPLE = 1,
        BANANA = 2,
        ORANGE = 4,
        GRAPE = 8
    };

    void demonstrateBitwiseWithEnums()
    {
        unsigned int fruitSelection = static_cast<unsigned int>(Fruits::APPLE) | static_cast<unsigned int>(Fruits::ORANGE);
        cout << "Fruit selection (APPLE | ORANGE): " << fruitSelection << endl; // Outputs 5
    }

    // demonstrate on using enum class as bitmask
    enum class Fruit
    {
        APPLE = 0,
        BANANA = 1,
        ORANGE = 2,
        GRAPE = 3
    };
    void demonstrateEnumClassAsBitmask()
    {
        const size_t fruitCount = 4;
        string fruitNames[fruitCount];
        fruitNames[static_cast<size_t>(Fruit::APPLE)] = "Red Apple";
        fruitNames[static_cast<size_t>(Fruit::BANANA)] = "Yellow Banana";
        fruitNames[static_cast<size_t>(Fruit::ORANGE)] = "Orange";
        fruitNames[static_cast<size_t>(Fruit::GRAPE)] = "Purple Grape";
        for (size_t i = 0; i < fruitCount; ++i)
        {
            cout << "Fruit " << i << ": " << fruitNames[i] << endl;
        }
    }

    // demonstrate on using enum class with bitwise operators
    void demonstrateEnumClassWithBitwiseOperators()
    {
        enum class Color : uint8_t
        {
            RED = 1 << 0,   // 0001
            GREEN = 1 << 1, // 0010
            BLUE = 1 << 2   // 0100
        };

        uint8_t myColor = static_cast<uint8_t>(Color::RED) | static_cast<uint8_t>(Color::BLUE);
        cout << "My color (RED | BLUE): " << static_cast<int>(myColor) << endl; // Outputs 5
    }
};