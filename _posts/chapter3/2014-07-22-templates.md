---
title: Templates
layout: post
categories: notes
chapter: 3
tags: range-for template functor policy variadic alias using
---

* there is no need to put space between template closing two `>` signs, e.g.:
  `std::vector<list<int>> a`

* define `begin(...)` and `end(...)` functions for certain type to be used in
  the range-for loop: functions should return an object that can be compared and
  incremented, e.g. acts as if it were an iterator:

```c++
template<typename T>
const T* begin(const vector<T>& collection) {
    return &collection[0]
}

template<typename T>
const T* end(const vector<T>& collection) {
    return begin(collection) + collection.size()
}

vector<int> x {1, 2, 3, 4, 5};
for(auto& x:collection) {
    // ...
}
```

* templates are a compile-time mechanism - there is no run-time overhead

* *function* object (or *functor*) is an object that can be called

* function objects used to specify the meaning of key operations of a general
  algorithm are often referred to as *policy objects*

* *variadic* template allows to specify variable number of arguments of
  arbitrary types:

```c++
template<typename T, typename... Tail>
void Process(const T& arg, Tail... tail) {
    Consume(arg);
    Process(tail...);
}
void Process() {}  // called when all args are exhausted
Process(1, 2, 3);
//
// Process(1, 2, 3); > Consume(1);
//                     Process(2, 3); > Consume(2);
//                                      Process(3); > Consume(3);
//                                                    Process();
```

* *alias* is synonym for a type or a template: `using new_name = old_name;`

* alias can also be parametrized with type like a template:

```c++
template<typename T>
using ElementType = typename T::value_type;

ElementType<vector<int>> a;  // equivalent to: int a;
```

### Advice

* return containers by value (rely on move for efficiency)

* never leak anything that you think of as a resource (use Resource Handler
  pattern which hides resource and never gives access to it)
