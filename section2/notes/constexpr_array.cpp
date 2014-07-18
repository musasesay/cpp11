// clang++ -std=c++11 constexpr_array.cpp -o constexpr_array
//
// constexpr can be used to define array size

#include <iostream>

constexpr int Square(int x) { return x * x; }

int main() {
    using namespace std;

    int array[Square(3)];
    cout << sizeof(array) / sizeof(*array) << endl;

    return 0;
}
