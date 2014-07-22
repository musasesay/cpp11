---
title: Abstraction Mechanisms
categories: notes
layout: post
chapter: 3
tags: stack heap inline overload RAII concrete abstract polymorphic override
      base superclass derived subclass inheritance heap initializer_list new
      delete
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
