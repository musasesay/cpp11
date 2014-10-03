---
title: Structures
categories: notes
layout: post
chapter: 8
tags:
    - struct
    - union 
    - enum
    - POD
    - trivial type
    - fields
    - integral
---

* most primitive user-defined types:
    - `struct` a set of elements of arbitrary types
    - `union` like a `struct` but holds the value of just one of its elements
    - `enum` a set of named constants (*enumerators*)
    - `enum class` scoped `enum` without implicit conversions

* `struct` can be initialized using `{}` notations

* members are allocated in memory in declaration order

* depending on a machine the structure may have different size depending on
  alignment requirements

* use of access specifiers: `public`, `protected`, `private` - may affect layout

* the name becomes available immediately when first seen and can be used inside
  the same `struct` but objects can not be declared (forwarding declaration):
  the compiler must know the size to allocate objects and can not do that
  without complete declaration

* the name of a `struct` can be used before the type is defined as long as that
  use does not require the name of a member of the size of the structure to be
  known

* the `struct` is an incomplete type until the completion of the declaration of
  it

* there is no need for a constructor if members are initialized in order

* `struct` may hold a c-style array which will be copied when `struct` is copied

* *POD* (*plain old data*) is a contiguous sequence of byes in memory

* POD is an object that can be manipulated as *just data*: no worries about
  class layout, user-defined semantics such as constructions, copy or move

* POD:
    - is of a *trivial type*:
        + trivial default constructor: no work - initialization only
        + no user-defined copy or move
    - has a *standard layout*
        + no virtual member
        + base has a *standard layout*
        + no reference members

* starting from C++11 non-default constructors do not affect layout or
  performance

* fields allow to specify number of bits the field takes

* there might be unnamed fields

* fields may be of integral or enumeration type

```
struct TContext {
    int Position : 4;  // [0-10]
    int : 4;  // unused
    bool Valid : 1;
    bool Expired : 1;
    bool : 6;  // unused
};
```

* fields will save data space but not code size: compiler will have to generate
  additional code to access fields
