```
./restrictions
Alignment of different types
1: char
4: int
```

The above listing demonstrates that pointer to `char` should be divisible of 1,
e.g. `static_cast<char*>(pointer) mod 1 == 0` and pointer to `int` should be a
multiplier of 4: `static_cast<int*>(pointer) mod 4 == 0`.

Pointer to `void` has arbitrary alignment since it point to unknown part of
memory and should be `alignas(alignof(char)) void* pointer;`.
