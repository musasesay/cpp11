// clang++ --std=c++11 promise_future.cpp -o promise_future
//
// future can be used only once: it becomes invalid after that

#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <vector>

using namespace std;

enum class EStatus {
    S_Ready
};

using TVint = vector<int>;
using TP2CPromise = promise<TVint>;
using TC2PPromise = promise<EStatus>;
using TP2CFuture = future<TVint>;
using TC2PFuture = future<EStatus>;

struct TPrint {
    void operator()(const string& message) {
        unique_lock<mutex> lock {Mutex};
        cout << this_thread::get_id() << " " << message << endl;
    }
private:
    mutex Mutex;
};

TPrint print;

ostream& operator<<(ostream& os, const TVint& data) {
    copy(data.begin(), data.end(), ostream_iterator<int> {os, " "});
    return os;
}

int Sum(const TVint& data) {
    int result {0};
    for(const auto& x : data) {
        result += x;
    }
    return result;
}

void Consumer(TC2PPromise& promise, TP2CFuture& future) {
    print("Consumer - start");
    promise.set_value(EStatus::S_Ready);
    auto data = future.get();
    if (data.empty()) {
        return;
    }
    ostringstream os;
    os << "sum(" << data << ") = " << Sum(data);
    print(os.str());
    print("Consumer - end");
}

void Producer(TP2CPromise& promise, TC2PFuture& future) {
    print("Producer - begin");
    auto status = future.get();
    if (status == EStatus::S_Ready) {
        ostringstream os;
        TVint data {1, 2, 3, 4, 5, 6, 7, 8, 9};
        os << "Producer - send: " << data;
        print(os.str());
        promise.set_value(data);
        print("Producer - finish");
    }
}

int main() {
    TP2CPromise P2CPromise;
    TP2CFuture P2CFuture {P2CPromise.get_future()};
    TC2PPromise C2PPromise;
    TC2PFuture C2PFuture {C2PPromise.get_future()};
    thread threads[] {
        thread {Consumer, ref(C2PPromise), ref(P2CFuture)},
        thread {Producer, ref(P2CPromise), ref(C2PFuture)}
    };
    for(auto& t : threads) {
        t.join();
    }
    return 0;
}
