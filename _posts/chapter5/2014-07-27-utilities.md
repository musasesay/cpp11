---
title: Concurrency and Utilities
categories: notes
layout: post
chapter: 5
tags: resource unique_ptr shared_ptr task thread process
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
