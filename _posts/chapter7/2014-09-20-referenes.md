---
title: References
categories: notes
layout: post
chapter: 7
tags: lvalue rvalue move overload
---

* a *reference* is an alias to an object and usually implemented through a
  pointer

* a reference is different from a pointer in the following ways:
    - there is no *null reference*
    - reference always references to the object it was initialized with
    - object access is done in exactly the same way as through the name of an
      object

* there are two types of references: `lvalue` and `rvalue`, e.g.:
    - `lvalue` refers an object whose value we want to use and it might be either
      const or non-const
    - `rvalue` revers an object whose value we do not need to preserve after its
      use, e.g. temporary object

* `lvalue` has a syntax `T&` and `const T&`

* reference **always** refer to some object, e.g. its declaration is definition

* references are always *dereferenced* each time it is used

* the initializer for non-const `lvalue` reference `T&` must be an lvalue of
  type T

* const `lvalue` reference `const T&` can be initialized with rvalue that can be
  implicitly cast to `T`, e.g.:

```
const double& rate {1};
// is equivalent to
double& temp {1};
const double& rate {temp};
```

* non-const `lvalue` can not be initialized with rvalue, e.g. temporary:

```
double& rate {1};  // invalid
```

* `rvalue` has a syntax `T&&`

* `rvalue` reference can only bind to another rvalue

* `rvalue` can bind to either const `lvalue` or another `rvalue`, e.g.:

```
const int& rate {1};
int&& distance {20};
```

* the difference between an `rvalue` and `const lvalue` is in their purposes:
    - `rvalue` is used to perform a *destructive read*
    - `const lvalue` is used to *prevent modification*  of an argument

* use either `std::move(obj)` or `static_cast<T&&>(obj)` to get an rvalue `T&&`

* reference to reference can only be achieved through aliases and `lvalue`
  always wins, e.g. if `rvalue` and `lvalue` are used in references to
  references the result would be an `lvalue`

* if you want to overload an operator that acts on something that refers to an
  object - use a reference because it is **impossible** to re-define an operator
  for built-in types (pointers):

```
T operator+(const T&, const T&);  // ok
T operator+(const T*, const T*);  // error: no user-defined type argument
```
