// clang++ --std=c++11 -Wpadded is_signed.cpp -o is_signed

#include <iostream>
#include <type_traits>

#define ANALYZE(T) Analyze<T>(#T)

template<typename T>
void Analyze(const char* type) {
    using namespace std;
    cout << type << " is " << (is_signed<T>::value ? "signed" : "unsigned") << endl;
}

int main(int, char* []) {
    ANALYZE(int);
    ANALYZE(signed int);
    ANALYZE(unsigned int);
    ANALYZE(char);
    ANALYZE(signed char);
    ANALYZE(unsigned char);
    return 0;
}
