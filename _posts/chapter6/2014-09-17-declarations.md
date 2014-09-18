---
title: Declarations
categories: notes
layout: post
chapter: 6
tags: declaration initialization auto list-initialization narrowing decltype
      rvalue lifetime
---

* `[prefix] type declarator [suffix] [initializer]`

* **prefix** specifier: `static`, `virtual`, `extern`, `constexpr`, `signed`,
  `unsigned`

* base **type**: `const int`, `char`

* **declarator**: `n`, `p[7]`, `* (*)[]`

* **suffix**: `const` or `noexcept`

* **initializer**: `= 10`, `{ return x; }`

* every declaration is terminated by a semicolon except for function and
  namespace definitions

* declarator consists of a name and one of the following declarator operator:

```
pre     *               pointer
pre     * const         const pointer
pre     * volatile      volatile pointer
pre     &               lvalue
pre     &&              rvalue
pre     auto            function with suffix return type
suf     []              array
suf     ()              function
suf     ->              function return type
```

* suffixes have stronger binding then prefixes, e.g. `int* p[]` is an array of
  pointers to `int`, while `int (*p) []` is a pointer to array of `int`'s

* non-local names starting from `_` and names matching `__\W` are reserved

* there are four ways to initialize a value:

```
int a {1};  // list-initialization: no narrowing
int b = {2};
int c = 3;
int d(4);
```

* use `=` with `auto` type declaration otherwise variable will be of
  `initializer_list` type, e.g. `auto x {10}`

* integral types are initialized to a suitable value of `0`, pointers to
  `nullptr`

* *global*, *namespace*, and *static* objects are initialized to `{}`

* *local* and *heap* objects are **not** initialized by default unless they are
  of user-defined types with a default constructor

* empty pair of parentheses `()` always means **function** in a declaration

```
int a ();  // function declaration
int b (1);  // initialize with 1
int c {2};  // initialize with 2  - prefer this
```

* there are two ways to deduce a type:
    - `auto`, e.g. deduce type from initialization
    - `decltype(EXPR)`, e.g. deduce type from expression

* one line declaration with initialization has two types if type is explicitly
  mentioned: declared type and the type of the initialization object, e.g.:

```
int a = 123;  // left:int right:int
int b = 'a';  // left:int right:char
int c {'d'};  // left:int right:char
```

* `auto` can only be used with suitable initializer

* `decltype(EXPR)` will deduce the type from the result of some expression,
  e.g.:

```
template<typename A, typename B>
auto Sum(const A&, const B&) -> decltype(A {} + B {});
```

* references are implicitly dereferenced in expressions

* **rvalue** is a *temporary* value

* every expression is either `lvalue` or `rvalue`, but not both

* *lifetime* of on object starts when its constructor completes until its
  destructor starts

* objects can be of the following types:

    - **automatic**: created on stack when its definition is met in a function
      until it goes out of scope, e.g. every function call gets a new call stack
      and object is newly created so its address changes

    - **static**: global, namespaced, or function/class static objects live
      until the program terminates and have the same address througout the
      program execution

    - **heap**: objects with dynamically controlled lifetime

    - **temporary**: intermediate computations

    - **thread_local**: created and destroyed with their thread

* type specifier can not be applied to aliases
