1. `int a$name {10};`: use of `$` in the name

1. `int _int {10}`: names starting with `_` are reserved

1. `#define size_t std::string`: WTF?

1. `char ch {'ac'};`

1. what if the address is too long?

```
int *a {0x123456};
short b = reshorterpret_cast<short>(a);
int *c = reinterpret_cast<int*>(b);
```

1. `__cxa_demangle(...);`: defined in MSVC++

1. `system("weird_application");`: the `weird_application` may not be installed

1. `std::ifstream inputStream {"/absolute/path/to/file"};`

1. `int a {0xaabbcc119933};`: assume `sizeof(int) == 8`

1. `char c {160};`: rely on a symbol that depends on characters table
