// clang++ --std=c++11 async.cpp -o async
//
// async automatically spans tasks depending on a number of available cores

#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& data) {
    copy(data.begin(), data.end(), ostream_iterator<int> {os, ","});
    return os;
}

int Sum(const vector<int>& data) {
    return accumulate(data.begin(), data.end(), 0);
}

int main() {
    vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 {10, 20, 30, 40, 50, 60, 70, 80, 90};
    auto f1 = async(Sum, v1);
    auto f2 = async(Sum, v2);
    auto result = f1.get() + f2.get();
    cout << "sum(" << v1 << ") + sum(" << v2 << ") = " << result << endl;
    return 0;
}
