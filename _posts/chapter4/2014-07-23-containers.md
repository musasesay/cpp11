---
title: STL Containers
categories: notes
layout: post
chapter: 4
tags: concatenate string
---

* you may concatenate a string, a string literal, a char, or a C-style string

* every standard-library container provides the functions `begin()` and `end()`,
  which return an iterator to the first and to one-past-the-last element,
  respectively

* a *sequence* is represented by a pair of iterators specifying the first
  element and the one-beyond-the-last

* *typename* is used to inform the compiler that something is supposed to be a
  type and not a value of some type, e.g.:

```c++
// a.h
class A {
public:
    class B;
    static int C;
};
// main.cpp
// ...
using B = typename A::B;
int C = A::C;
```

* iterators are used to separate algorithms and containers
