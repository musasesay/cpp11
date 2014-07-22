// clang++ -std=c++11 range_for.cpp -o range_for
//
// demonstrate range-for-statement

#include <iostream>

int main() {
    using namespace std;

    int array[] {1, 2, 3, 4, 5};
    for(const auto &x: array)
        cout << x << ' ';
    cout << endl;

    for(const auto &x: {1, 2, 4, 9})
        cout << x << ' ';
    cout << endl;

    return 0;
}
