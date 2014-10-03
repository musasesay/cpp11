// clang++ --std=c++11 -Wpadded struct.cpp -o struct

#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE(T) PrintSize<T>(#T)

template<typename T>
void PrintSize(const char* type) {
    T obj;
    cout << setw(20) << right << type << ": " << sizeof(obj) << " Bytes" << endl;
}

struct TStructure {
    bool Flag;
    char Character;
    int Number;
    long Measurement;
    double Pi;
    long double Exponent;
};

struct TSmallestStructure {
    long double Exponent;
    double Pi;
    long Measurement;
    int Number;
    char Character;
    bool Flag;
};

struct TLargestStructure {
    bool Flag;
    long double Exponent;
    char Character;
    double Pi;
    int Number;
    long Measurement;
};

int main(int, char*[]) {
    SIZE(TStructure);
    SIZE(TSmallestStructure);
    SIZE(TLargestStructure);
    return 0;
}
