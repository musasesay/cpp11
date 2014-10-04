---
title: Statements
categories: notes
layout: post
chapter: 9
tags: declaration expression statement static condition if switch case
      for-init-statement range-for goto
---

* a *declaration* is a statement

* an *expression* becomes a statements when you add a semicolon to its end

* expression has a value and statement does not

* statements are used to specify the order of execution

```c++
statement:
    declaration
    [expression] ;
    { [statement-list] }
    try { [statement-list] } handler-list

    case constant-expression : statement
    default : statement
    break ;
    continue ;

    return [expression] ;

    goto identifier ;
    identifier : statement

    selection-statement
    iteration-statement

selection-statement:
    if ( condition ) statement
    if ( condition ) statement else statement
    switch ( condition ) statement

iteration-statement:
    while( condition ) statement
    do statement while ( expression );
    for( for-init-statement [condition]; [expression] ) statement
    for( for-init-declaration : expression ) statement

statement-list:
    statement [statement-list]

condition:
    expression
    type-specifier declarator = expression
    type-specifier declarator { expression }

handler-list:
    handler [handler-list]

handler:
    catch( expression-declaration ) { [statement-list] }
```

* assignments and function calls are expressions

* unless a variable is `static`, its initializer is executed whenever the thread
  of control passes through the declaration

* condition is either expression or declaration

* a branch of an `if`-statement can not be just a declaration

* a *constant-expression* in the case lables must be of a constant expression of
  integral or enumeration type

* `switch` typically leads to the generation of better code because there is no
  reason to repeatedly check individual values; instead, a jump table can be
  used

* it's a good idea to comment the "rare" cases in which a fall-through is
  intentional in the `switch` so that an uncommented fall-through can be assumed
  to be an error

* do not use `default` case with enumerators - compiler will warn about missing
  enumerator cases - test for an *impossible* enumerator value separately

* a `switch`-block may have a declaration but not initialization: beware of
  baypass:

```c++
int i {CalculateAverageAgeOfCats()};
switch(i) {
case 0:
    int x;
case 1:
    Use(x);  // x is uninitialized if `i == 1`
}
```

* an `if`-condition might be a declaration and initialization of a single
  variable which would have a scope of if block with all else branches:

```c++
if (int age {CalculateAverageAgeOfCats()}) {
    cout << "cats live long, for " << age << " year(s)" << endl;
} else {
    cout << "ups, cats life is only " << age << " years" << endl;
}
// age went out of scope
```

* `for`-init-statement must be either a declaration or an *expresion-statement*:
  both end with a semicolon

* the range-`for` loop introduces a variable with a scope of the `for`-statement

* the expression after the colon (`:`) must yield a value for which it is
  possible to call either:
    - `v.begin()` and `v.end()`
    - `begin(v)` and `end(v)`

* the scope of a `goto`-label is the function it is in

* there is no way to jump with `goto` past an initializer or into an exception
  handler
