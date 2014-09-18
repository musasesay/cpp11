* `char c = 300;`: outside of boundaries

* `char c;`: signed or unsigned?

* `sizeof(int)`: 2B, 4B, or 8B?

* `struct TStructure {...}; sizeof(TStructure);`: size depends on built-in types

* `alignof(int)`: 2B, 4B, or 8B?

* `int Sum(int a, int b) { return a + b; }; Sum(i++, ++i);`
