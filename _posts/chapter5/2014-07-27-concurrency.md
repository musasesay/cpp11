---
title: Concurrency and Utilities
categories: notes
layout: post
chapter: 5
tags: resource unique_ptr shared_ptr task thread process mutex unique_lock lock
      future promise packaged_task async
---

* a *resource* is something that must be acquired and later released, e.g.
  memory, lock, socket, thread or file handle.

* `<memory>` module has two smart pointers:
    - `unique_ptr` - unique ownership
    - `shared_ptr` - shared ownership

* smart pointers solve resource management problems but not data race

* a *task* is a computation that can potentially be executed concurrently with
  other computations

* a *thread* is the system-level representation of a task in a program

* to run a task one needs to create a `thread` object and pass a task to its
  constructor in a form of a function or function object, e.g.:

```c++
void Task() {}
struct TTask() {
    void operator()() {}
};
thread t1 {Task};
thread t2 {TTask{}};
```

* use `thread::join()` to wait for thread to finish

* threads share a single address space while processes generally do not directly
  share data

* when defining tasks of a concurrent program, our aim is to keep tasks
  completely separate except where they communicate in simple and obvious ways;
  the simplest way of thinking of a concurrent task is as a function that
  happens to run concurrently with its caller: we just have to pass arguments,
  get a result back, and make sure that there is no use of shared data in
  between (prevent data races)

* pass arguments by non-const reference only if you expect function to modify
  the value

* use const reference arguments to pass input data to task and non-const
  reference to pass an argument that would be used as a task return value, e.g.:

```c++
void Sum(const vector<int>& input, int& result) {
    // sum input elements and store result in result
}
vector<int> input {1, 2, 3, 4, 5};
int result;
thread t {Sum, input, result};
t.wait();
cout << result << endl;
```

* a *mutex* is a *mutual exclusion object*

* use *unique_lock* to acquire unique lock on mutex (only one thread owns mutex
  at a given time)

* use `lock(...)` function to acquire several mutexes: it prevents a dead lock

```c++
void f() {
    unique_loc<mutex> l1 {m1, defer_lock};  // do not lock yet
    unique_loc<mutex> l2 {m2, defer_lock};
    lock(l1, l2);  // will only proceed when all mutexes are acquired
}
```

* locking and unlocking are relatively expensive operations

* `condition_variable` allows to synchronize threads: consumer acquires mutex and
  waits for a condition variable event by passing lock to it while producer
  acquires the same mutex and then asks the condition variable to notify
  consumer(s), e.g.:

```c++
mutex TheMutex;
condition_variable Condition;
void Consumer() {
    unique_lock<mutex> lock {TheMutex};  // acquire mutex
    while(Condition.wait(lock)) {
    }  // release mutex and wait for a notification
    // mutex is acquired again
}
void Producer() {
    unique_lock<mutex> lock {TheMutex};
    Condition.notify_one();  // send a notification event
}
```

* use `promise` and `future` to send and retrieve a value or exception between
  threads, e.g.:

```c++
promise<int> p;
future<int> f {p.get_future()};
void Consumer() {
    try {
        auto x = f.get();
        // use x - future can be used only once (!)
    } catch(...) {
        // future may also deliver an exception
    }
}
void Producer() {
    p.set_value(1000);
}
```

* `future` becomes invalid once the value is delivered

* instead of manipulating `promise` and `future` it is possible to wrap a task
  into a `packaged_task` and use associated future to retrieve result:

```c++
int Sum(const vector<int>& data) { 
    return accumulate(data.begin(), data.end(), 0);
}
using TTask = int (vector<int>);
packaged_task<TTask> t1 {&Sum};  // there only move constructor
packaged_task<TTask> t2 {&Sum};
future<int> f1 {t1.get_future()};
future<int> f2 {t2.get_future()};
thread threads [] {
    thread {move(t1), vector1},
    thread {move(t2), vector2}
};
int result {f1.get() + f2.get()};
for(auto& t : threads) {
    t.join();  // it is important to let threads finish
}
```

* `async` hides any use of `mutex`, `lock`, `future` or any other thread related
  objects and lets concentrate on the code

```c++
auto f1 = async(Sum, vector1);
auto f2 = async(Sum, vector2);
auto result = f1.() * f2();
```
