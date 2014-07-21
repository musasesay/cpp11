---
title: Introduction to C++11
categories: notes
section: 1
tags: lvalue rvalue
---

* the fundamental object in C++ has identity: it is located in a specific
  location in memory and can be distinguished from other objects with the same
  value by comparing addresses; expressions denoting such objects are called
  `lvalues`

* there are also objects without identity, e.g. objects for which an address
  cannot be safely stored for later use; these are `rvalues`

* C++ was designed to operate within a single address space

* the task of learning a language should focus on mastering the native and
  natural styles for that language - not on understanding of every little detail
  of every language feature
