// clang++ --std=c++11 restrictions.cpp -o restrictions

#define ALIGNMENT(T) Alignment<T>(#T)

#include <iostream>

using namespace std;

template<typename T>
void Alignment(const char* type) {
    cout << alignof(T) << ": " << type << endl;
}

int main(int, char* []) {
    cout << "Alignment of different types" << endl;
    ALIGNMENT(char);
    ALIGNMENT(int);
    return 0;
}
