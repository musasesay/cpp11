// clang++ --std=c++11 distance.cpp -o distance

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

size_t Distance(const char* p1, const char* p2) {
    if (p1 < p2) {
        return p2 - p1;
    } else if (p2 < p1) {
        return p1 - p2;
    } else {
        return 0;
    }
}

int main(int, char* []) {
    using namespace std;
    const char* message {"Hello World"};
    size_t length {strlen(message)};
    cout << "message: " << message << endl;
    cout << "         " << static_cast<const void*>(message) << endl;
    cout << " length: " << length << endl;
    cout << endl;
    default_random_engine Generator (chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> Distribution {0, static_cast<int>(length)};
    int shift1 {Distribution(Generator)};
    int shift2 {Distribution(Generator)};
    const char* p1 {message + shift1};
    const char* p2 {message + shift2};
    cout << "     p1: " << static_cast<const void*>(p1) << " [" << shift1 << "]" << endl;
    cout << "     p2: " << static_cast<const void*>(p2) << " [" << shift2 << "]" << endl;
    cout << endl;
    cout << "Distance(p1,p2): " << Distance(p1, p2) << endl;
    cout << "Distance(p2,p1): " << Distance(p2, p1) << endl;
    cout << "Distance(p1,p1): " << Distance(p1, p1) << endl;
    cout << "Distance(p2,p2): " << Distance(p2, p2) << endl;
}
