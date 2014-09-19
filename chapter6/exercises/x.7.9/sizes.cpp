// clang++ --std=c++11 -Wpadded sizes.cpp -o sizes

#include <iostream>
#include <limits>

#define PROCESS(T) Analyze<T>(#T)

template<typename T>
void Analyze(const char* type) {
    using namespace std;
    static auto base = sizeof(char);
    cout << type << " has a size of " << sizeof(T) / base << " char(s)" << endl;
}

int main(int, char* []) {
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
