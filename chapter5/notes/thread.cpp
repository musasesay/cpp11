// clang++ --std=c++11 thread.cpp -o thread
//
// thread is a system-representation of a task

#include <iostream>
#include <string>
#include <thread>

using namespace std;

struct TPrint {
    void operator()(const string& message) {
        unique_lock<mutex> lock {PrintMutex};
        cout << message << endl;
    }
private:
    mutex PrintMutex;
};

TPrint Print;

void Task() {
    Print("executing Task()");
}

struct TTask {
    void operator()() {
        Print("executing TTask::operator()");
    }
};

int main() {
    thread threads[] {
        thread{Task},
        thread{TTask{}}
    };
    for(auto& t : threads) {
        t.join();
    }
    return 0;
}
