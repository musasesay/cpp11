// clang++ --std=c++11 -Wpadded loop.cpp -o loop

#include <iostream>

int main(int, char* []) {
    using namespace std;
    for(const auto& x : {4, 5, 9, 17, 12}) {
        cout << x << endl;
    }
    return 0;
}
