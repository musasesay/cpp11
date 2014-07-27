// clang++ --std=c++11 thread_args.cpp -o thread_args
//
// pass arguments to a task

#include <iostream>
#include <sstream>
#include <thread>
#include <thread>
#include <vector>

using namespace std;

struct TPrint {
    void operator()(const string& message) {
        unique_lock<mutex> lock {PrintMutex};
        cout << message << endl;
    }
private:
    mutex PrintMutex;
};

TPrint print;

using TVint = vector<int>;

void Sum(const TVint& array, const string& header) {
    typename TVint::value_type result;
    for(const auto& x : array) {
        result += x;
    }
    ostringstream os;
    os << header << ' ' << result;
    print(os.str());
}

struct TSum {
    TSum(const TVint& array)
        : Array{array}
    {}
    void operator()() const {
        return Sum(Array, "TSum::operator()");
    }
private:
    const TVint& Array;
};

struct TSmartSum {
    void operator()(const TVint& array) {
        return Sum(array, "TSmartSum::operator()");
    }
};

int main() {
    TVint array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    thread threads[] {
        thread{Sum, array, "Sum() result"},
        thread{TSum{array}},
        thread{TSmartSum{}, array}
    };
    for(auto& t : threads) {
        t.join();
    }
    return 0;
}
