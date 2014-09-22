// clang++ --std=c++11 swap.cpp -o swap

#include <iostream>

void Swap(int& a, int& b) {
    int tmp {static_cast<int&&>(b)};
    b = static_cast<int&&>(a);
    a = static_cast<int&&>(tmp);
}

void Swap(int* a, int* b) {
    Swap(*a, *b);
}

int main(int, char* []) {
    using namespace std;
    int a {1};
    int b {2};
    cout << "a:" << a << " b:" << b << endl;
    Swap(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    Swap(a, b);
    cout << "a:" << a << " b:" << b << endl;
    return 0;
}
