// clang++ --std=c++11 packaged_task.cpp -o packaged_task
//
// packaged task has an associated future

#include <future>
#include <iostream>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& arr) {
    copy(arr.begin(), arr.end(), ostream_iterator<int> {os, " "});
    return os;
}

int Sum(const vector<int>& data) {
    return accumulate(data.begin(), data.end(), 0);
}

int main() {
    using TSum = int (const vector<int>&);
    vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 {10, 20, 30, 40, 50, 60, 70, 80, 90};
    packaged_task<TSum> t1 {&Sum};
    packaged_task<TSum> t2 {&Sum};
    future<int> f1 {t1.get_future()};
    future<int> f2 {t2.get_future()};
    thread threads[] {
        thread {move(t1), v1},
        thread {move(t2), v2},
    };
    auto result {f1.get() + f2.get()};
    cout << "sum(" << v1 << ") + sum(" << v2 << ") = " << result << endl;
    for(auto& t : threads) {
        t.join();
    }
    return 0;
}
