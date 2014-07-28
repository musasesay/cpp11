// clang++ --std=c++11 thread_condition.cpp -o thread_condition
//
// use condition_variable to synchronize threads

#include <algorithm>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <mutex>
#include <queue>
#include <set>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

using TVint = vector<int>;

struct TMessage {
    enum class EAction {
        Sum,
        Product,
        Unique,
        Stop
    };
    EAction Action;
    TVint Data;
};

int Sum(const TVint& data) {
    int result {0};
    for(const auto& x : data) {
        result += x;
    }
    return result;
}

int Product(const TVint& data) {
    int result {1};
    for(const auto& x : data) {
        result *= x;
    }
    return result;
}

set<int> Unique(const TVint& data) {
    set<int> result {data.begin(), data.end()};
    return result;
}

ostream& operator<<(ostream& os, const TVint& values) {
    os << "vec: ";
    copy(values.begin(), values.end(), ostream_iterator<TVint::value_type> {os, " "});
    return os;
}

ostream& operator<<(ostream& os, const set<int>& values) {
    os << "set: ";
    copy(values.begin(), values.end(), ostream_iterator<int> {os, " "});
    return os;
}

struct TQueue {
    queue<TMessage> Messages; 
    mutex Mutex;
    condition_variable Condition;
};

class TLog {
public:
    virtual ~TLog() {}
    virtual void operator()(const string& message) = 0;
protected:
    mutex Mutex;
};

class TPrint : public TLog {
public:
    virtual void operator()(const string& message) {
        unique_lock<mutex> lock {Mutex};
        cout << this_thread::get_id() << " " << message << endl;
    }
};

class TError : public TLog {
public:
    virtual void operator()(const string& message) {
        unique_lock<mutex> lock {Mutex};
        cout << this_thread::get_id() << " " << "error: " << message << endl;
    }
};

TPrint print;
TError error;

class TConsumer {
public:
    TConsumer(TQueue& queue)
        : Queue {queue}
        , DoContinue(false)
    {}
    void operator()() {
        print("TConsumer::operator() start");
        DoContinue = true;
        while(DoContinue)
        try {
            unique_lock<mutex> lock {Queue.Mutex};
            while(Queue.Messages.empty()) {
                Queue.Condition.wait(lock);
            }
            TMessage message = Queue.Messages.front();
            Queue.Messages.pop();
            lock.unlock();
            Process(message);
        } catch(const invalid_argument& err) {
            error(err.what());
        }
        print("TConsumer::operator() end");
    }
private:
    void Process(const TMessage& message) {
        switch(message.Action) {
        case TMessage::EAction::Sum:
            SumAction(message);
            break;
        case TMessage::EAction::Product:
            ProductAction(message);
            break;
        case TMessage::EAction::Unique:
            UniqueAction(message);
            break;
        case TMessage::EAction::Stop:
            DoContinue = false;
            break;  // stop outter while
        default:
            throw invalid_argument("unsupported action");
        }
    }
    void SumAction(const TMessage& message) {
        auto result = Sum(message.Data);
        ostringstream oss;
        oss << "sum(" << message.Data << ") = " << result;
        print(oss.str());
    }
    void ProductAction(const TMessage& message) {
        auto result = Product(message.Data);
        ostringstream oss;
        oss << "prod(" << message.Data << ") = " << result;
        print(oss.str());
    }
    void UniqueAction(const TMessage& message) {
        auto result = Product(message.Data);
        ostringstream oss;
        oss << "uniq(" << message.Data << ") = " << result;
        print(oss.str());
    }
private:
    TQueue& Queue;
    bool DoContinue;
};

class TProducer {
public:
    TProducer(TQueue& queue)
        : Queue {queue}
    {}
    void operator()(const size_t& consumers) {
        print("TProducer::operator() begin");
        using EAction = TMessage::EAction;
        for(const auto& action : {
                EAction::Sum,
                EAction::Product,
                EAction::Unique
            }) {
            for(const TVint& data : {
                    TVint {1, 2, 3},
                    TVint {2, 4, 6},
                    TVint {1, 2, 4},
                    TVint {1, 3, 9},
                }) {
                SendMessage(TMessage {action, data});
            }
        }
        for(size_t i {0}; i < consumers; ++i) {
            SendMessage(TMessage {EAction::Stop, {}});
        }
        print("TProducer::operator() finish");
    }
private:
    void SendMessage(const TMessage& message) {
        unique_lock<mutex> lock {Queue.Mutex};
        Queue.Messages.push(message);
        Queue.Condition.notify_one();
    }
private:
    TQueue& Queue;
};


int main() {
    TQueue queue;
    thread consumers[] {
        thread {TConsumer {queue}},
        thread {TConsumer {queue}},
        thread {TConsumer {queue}},
        thread {TConsumer {queue}},
        thread {TConsumer {queue}},
        thread {TConsumer {queue}},
        thread {TConsumer {queue}}
    };
    thread producer {TProducer {queue}, sizeof(consumers) / sizeof(thread)};
    producer.join();
    for(auto& t : consumers) {
        t.join();
    }
    return 0;
}
