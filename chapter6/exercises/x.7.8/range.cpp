// clang++ --std=c++11 -Wpadded range.cpp -o range

#include <iostream>
#include <limits>

#define PROCESS(T) Analyze<T>(#T)

template<typename T>
void Analyze(const char* type) {
    using namespace std;
    using TLimits = numeric_limits<T>;
    cout << type << " " << sizeof(T) << "B min:" << TLimits::min() << " max:" << TLimits::max() << " lowest:" << TLimits::lowest() << endl;
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
