---
title: Abstraction Mechanisms
categories: notes
layout: post
chapter: 3
tags:
  - stack
  - heap
  - inline
  - overload
  - RAII
  - concrete
  - abstract
  - polymorphic
  - override
  - base
  - superclass
  - derived
  - subclass
  - inheritance
  - heap
  - initializer_list
  - new
  - delete
  - copy
  - resource handle
  - copy
  - move
---

* *stack* is a statically allocated memory

* *free store* is a dynamic memory or heap

* representation of *conctrete* class is part of definition and ideally they
  should behave just like built-in types

* *inlined* functions are those that are implemented without function calls in
  the generated machine code

* functions defined in a class are **inlined** by default

* default constructor has no arguments

* define functions that need access to representation as members and all others
  separately from the class definition

* *overloaded* operators are user-defined operators, e.g. `operator+`

* *RAII* - Resource Acquisition Is Initialization - acquire resources in
  constructor and release them in destructor

* naked `new` or `delete` is when these operators are used in general code
  instead of balanced constructor/destructor pair

* `std::initializer_list` is a standard-library type known to the compiler

* *abstract* class completely insulates a user from implementation details

* *polymorphic* type is a class that provides interface to a variety of other
  classes

* methods may *override* those that are virtual and defined in the base class

* *base* is a *superclass*, *child* is a *subclass*

* *interface inheritance* is when base is a pure abstract class and derived
  classes override interface

* *implementation iheritance* is when base class provides representation and
  interface which simplifies implementation of derived classes

* default copy is a member wise copy

* *resource handle* is a class that is responsible for an object accessed
  through a pointer

* there are two copying members: *copy constructor* and *copy assignment*

* move semantic complements copy:

```c++
class Handler {
public:
    Handler(const Handler&);    // copy constructor
    Handler& operator=(const Handler&);  // copy assignment

    Handler(const Handler&&);   // move constructor
    Handler& operator=(const Hanlder&&); // move assignment
};
```

* compiler chooses move constructor for return values if one exists

* roughly, *rvalue* is a value that you can't assign to while *lvalue* is the
  opposite: something that can appear on the left-hand side of an assignment

* move operators have non-constant argument because its value is being stolen

* a move operation is applied when rvalue reference is used as an initializer or
  as the right-hand side of an assignment

* leave a moved-from object in a state that allows destructor and assignment to
  be run

* in certain cases compiler will not detect move semantic; use `std::move` to
  force it (`move` returns an rvalue):

```c++
Handler a;
Handler b;
Handler c;
b = a;              // get a copy
c = std::move(a);   // get a move
```

* complete control of the lifetime of a resource is handled by *constructor*,
  *destructor*, *copy*, and *move* operations

* copy and move operations are not virtual and therefore may lead to wrong copy
  in class hierarchies: use `clone` method and disable above operations by
  deleting them from the base class:

```c++
class Base {
public:
    Base(const Base&) =delete;  // no copy
    Base& operator=(const Base&) =delete;

    Base(Base&&) =delete;  // no move
    Base& operator=(Base&&) =delete;
};
```

* move operations are automatically generated unless there is a destructor
