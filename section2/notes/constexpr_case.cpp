// clang++ -std=c++11 constexpr_case.cpp -o constexpr_case
//
// constexpr can be used in a switch-case construction

#include <iostream>
#include <sstream>

using namespace std;

constexpr int Square(const int &x) { return x * x; }
constexpr int Cube(const int &x) { return x * Square(x); }

string Message(const int &id) {
    ostringstream os;
    const int base {3};
    switch(id) {
    case Square(base):
        os << "square of " << base;
        break;
    case Cube(base):
        os << "cube of " << base;
        break;
    default:
        os << "don't know what to do";
        break;
    }
    return os.str();
}

int main() {
    cout << Message(1) << endl;
    cout << Message(9) << endl;
    cout << Message(8) << endl;
    cout << Message(27) << endl;

    return 0;
}
