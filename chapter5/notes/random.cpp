// clang++ --std=c++11 random.cpp -o random
//
// random generation consists of:
//      - engine
//      - distribution

#include <random>
#include <iostream>
#include <chrono>
#include <iomanip>

int main() {
    using namespace std;

    default_random_engine engine {static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count())};
    normal_distribution<float> normal {10, 2};
    for(auto& x : {1, 2, 3, 4, 5}) {
        cout << setw(2) << x << ": " << normal(engine) << endl;
    }

    return 0;
}
