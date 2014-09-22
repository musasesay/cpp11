// clang++ --std=c++11 distance.cpp -o distance

#include <chrono>
#include <iostream>
#include <random>

using namespace std;

size_t Distance(int* p1, int* p2) {
    if (p1 < p2) {
        return p2 - p1;
    } else if (p2 < p1) {
        return p1 - p2;
    } else {
        return 0;
    }
}

template<size_t Size>
ostream& operator<<(ostream& os, int (&array)[Size]) {
    for(const auto& x : array) {
        os << x;
        if (&x != (array + Size - 1)) {
            os << ' ';
        }
    }
    return os;
}

int main(int, char* []) {
    int numbers[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int length {10};
    cout << "numbers: " << numbers << endl;
    cout << "         " << static_cast<const void*>(numbers) << endl;
    cout << " length: " << length << endl;
    cout << endl;
    default_random_engine Generator (chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> Distribution {0, length};
    int shift1 {Distribution(Generator)};
    int shift2 {Distribution(Generator)};
    int* p1 {numbers + shift1};
    int* p2 {numbers + shift2};
    cout << "     p1: " << static_cast<const void*>(p1) << " [" << shift1 << "]" << endl;
    cout << "     p2: " << static_cast<const void*>(p2) << " [" << shift2 << "]" << endl;
    cout << endl;
    cout << "Distance(p1,p2): " << Distance(p1, p2) << endl;
    cout << "Distance(p2,p1): " << Distance(p2, p1) << endl;
    cout << "Distance(p1,p1): " << Distance(p1, p1) << endl;
    cout << "Distance(p2,p2): " << Distance(p2, p2) << endl;
}
