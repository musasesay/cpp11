// clang++ --std=c++11 -Wpadded sizeof.cpp -o sizeof

#include <iostream>

using namespace std;

void Split() {
    cout << "---" << endl;
}

#define GET_SIZE(T) Analyze<T>(#T)

template<typename T>
void Analyze(const char* type=nullptr) {
    cout << type << ": " << sizeof(T) << endl;
}

enum class EBool {
    B_No,
    B_Yes
};

enum class ELight {
    L_Red,
    L_Yellow,
    L_Green
};

int main(int, char* []) {
    GET_SIZE(bool);
    Split();
    GET_SIZE(char);
    GET_SIZE(wchar_t);
    Split();
    GET_SIZE(short);
    GET_SIZE(int);
    GET_SIZE(long);
    GET_SIZE(long long);
    Split();
    GET_SIZE(float);
    GET_SIZE(double);
    GET_SIZE(long double);
    Split();
    GET_SIZE(char*);
    GET_SIZE(int*);
    Split();
    GET_SIZE(EBool);
    GET_SIZE(ELight);
    return 0;
}
