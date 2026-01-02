#include <iostream>
using namespace std;

class SampleClass {
public:
    SampleClass(): a(0), b(0.0), c('\0'), d(0.0f) {
        cout << "SampleClass Constructor called." << endl;
    }

    SampleClass(int x, double y, char z, float w): a(x), b(y), c(z), d(w) {
        cout << "SampleClass Parameterized Constructor called." << endl;
    }

    ~SampleClass() {
        cout << "SampleClass Destructor called." << endl;
    }   
    
    public: 
        int a;          // 4 bytes
        double b;       // 8 bytes
        char c;         // 1 byte
        // Padding of 7 bytes may be added here for alignment
        float d;        // 4 bytes
};