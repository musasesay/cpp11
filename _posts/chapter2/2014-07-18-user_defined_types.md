---
title: User-Defined Types
categories: notes
chapter: 2
layout: post
tags: new enum declaration interface definition implementation precondition
      invariant assert constexpr
---

* the `new` operator allocates memory from an area called *the free store* (or
  *dynamic memory* or *heap*)

* *built-int* types are fundamental types: `bool`, `char`, `int`, `float`, and
  `double`

* *user-defined* types are `struct`, `class`, and `enum`

* `enum class` is a *strongly* typed enumeration with *scoped* enumerators, e.g.
  values can not mix between enumerations:

```c++
// strongly typed enumerations will scope the same name enumerators
enum class RGB { red, green, blue };
enum class Rainbow { red, orange, yellow, green, blue, indigo, violet }
// you can not mix colors:
RGB light = RGB::red;
light = Rainbow::red;   // error: can not mix
// not even implicit casts
int RedLight = Rainbow::green;
```

* plain `enum` puts all enumerators into the same namespace (mixes values) and
  allows for conversions

* `enum class` has only initialization, assignment and comparison defined

* it is possible to define operators for `enum class` because it is a
  *user-defined* type

```cpp
RGB& operator++(RGB& light) {
    switch(light) {
        case RGB::red:
            light = RGB::green;
            break;
        case RGB::green:
            light = RGB::blue;
            break
        case RGB::blue:
            light = RGB::red;
            break;
        default:
            throw runtime_error("unsupported RGB light");
    }
    return light;
}
RGB light {RGB::green};
++light;  // make it blue
```

* always distinguish between the *interface* and
  *implementation*, or *declaration* and *definition*:

```c++
// declaration - interface
void print(const std::string &);
// ...
// defintion - implementation
void print(const std::string &) {
    // ...
}
```

* whenever we define a function, we should consider what its *precondition* is 
  and if feasible test them

* an *invariant* is an analogy of function's precondition but for a class: it is
  something that is assumed about class; constructor should establish invariant
  while member functions should maintain the invariant

* exceptions report run time errors

* use `static_assert(condition, message)` to check conditions at compile time
  and report errors through compiler (these are called *assertions* ); condition
  is any `constexpr`
