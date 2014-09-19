// clang++ --std=c++11 -Wpadded alignment.cpp -o alignment

#include <iomanip>
#include <iostream>

#define PROCESS(T) Analyze<T>(#T)

using namespace std;

template<typename T>
void Analyze(const char* type) {
    static auto base = sizeof(char);
    cout << setw(2) << alignof(T) / base << " " << type << endl;
}

int main(int, char* []) {
    cout << "Alignment of different types in size of char" << endl;
    PROCESS(bool);
    PROCESS(char);
    PROCESS(short);
    PROCESS(int);
    PROCESS(long);
    PROCESS(long long);
    PROCESS(float);
    PROCESS(double);
    PROCESS(long double);
    PROCESS(unsigned);
    PROCESS(unsigned long);
    return 0;
}
