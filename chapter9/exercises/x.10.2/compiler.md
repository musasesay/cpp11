```bash
$ clang++ --std=c++11 compiler.cpp -o compiler
compiler.cpp:4:11: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
    if (a = 3) {
        ~~^~~
compiler.cpp:4:11: note: place parentheses around the assignment to silence this warning
    if (a = 3) {
          ^
        (    )
compiler.cpp:4:11: note: use '==' to turn this assignment into an equality comparison
    if (a = 3) {
          ^
          ==
compiler.cpp:6:11: warning: & has lower precedence than ==; == will be evaluated first [-Wparentheses]
    if (a & 077 == 0) {
          ^~~~~~~~~~
compiler.cpp:6:11: note: place parentheses around the '==' expression to silence this warning
    if (a & 077 == 0) {
          ^
            (       )
compiler.cpp:6:11: note: place parentheses around the & expression to evaluate it first
    if (a & 077 == 0) {
          ^
        (      )
compiler.cpp:8:8: error: expected expression
    a := b + 1;
       ^
2 warnings and 1 error generated.
```
