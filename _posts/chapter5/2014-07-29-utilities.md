---
title: Utilities
categories: notes
chapter: 5
tags:
  - duration_cast
  - high_resolution_clock
  - pair
  - tuple
  - raw string
  - regex
  - smatch
  - bind
  - random engine
  - random distribution
  - valarray
---

* use `duration_cast(...)` to convert different unites of time

```c++
auto Start = chrono::high_resolution_clock::now();
// run calculation
auto End = chrono::high_resolution_clock::now();
auto Duration = start - end;
cout << chrono::duration_cast<milliseconds>(Duration).count() << endl;
```

* don't make statements about *efficiency* of code without first doing time
  measurements

* *type functions* are evaluated at compile-type and include:
  `numeric_limits(...)`, `sizeof(...)`, etc.

* use `pair` and `tuple` to exchange basic information, e.g. return values form
  a function: both are heterogeneous containers)

* *raw string* has a form `R"(...)"` and allow use of backslash `\`

* `smatch` in the `regex` library stand for *sub-match*

* a random number generator consists of two parts:
    - *engine* produces a sequence of pseudo-random values
    - *distribution* is a probability distribution function

* `bind(...)` invokes a first argument and passes the rest through arguments

* use `valarray` for arithmetic operations on vector
