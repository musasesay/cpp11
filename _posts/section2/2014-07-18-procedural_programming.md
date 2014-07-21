---
title: Procedural Programming
categories: notes
section: 2
tags: constexpr range-for-statement immutability
---

* `vim` > source | `compile` > object | `link` > executable

* statically typed language: the type of every entity (object, value, name, and
  expression) must be known to the compiler at its point of use

* type defines operations that may be performed on it

* a *declaration* is a statement that introduces a name into the program

* a *type* defines a set of possible values and a set of operations

* an *object* is some memory that holds a value of some type

* a *value* is a set of bits interpreted according to a type

* a *variable* is a named object

* size of type is *implementation-defined* (use `sizeof`)

* use `auto` unless:
    - the definition is in a large scope (explicitly state the type)
    - be explicit about variable's range of precision

* do not use `=` with `auto` because there is no type conversion involved

* *immutability* can be one of two type:
    - `const` is something that will not change
    - `constexpr` is to be evaluated at compile time

* `constexpr` is used in:
    - array boundaries
    - case labels
    - template arguments
    - `constexpr`

* `constexpr` function can be called for const and variable arguments but only
  former can be used in another `constexpr`, e.g.:

```c++
constexpr int a = 5;
int b = 10;
constexpr int square(int x) { return x * x; }
constexpr int c = square(a);  // ok
constexpr int d = square(b);  // error: used in constexpr with var arg
int e = square(a);  // ok
int f = square(b);  // ok
```

* the range-`for`-statement can be used for any sequence

* *declarator operators* are operators that are used in declaration (such as
  `&`, `*`, and `[]`)

* `nullptr` is a pointer to nothing (there is only one `nullptr` shared among
  all pointers)
