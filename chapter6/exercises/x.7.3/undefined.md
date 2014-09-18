* `int* a = new int {};`: what if `new` operator fails?

* `int* a = 0x123456; delete a;`: delete some random address?

* `int x = 10 / 0`

* `int b = i++ + a[i]`: does `a[i]` use new or old value of `i`?

* `int a[] {1, 2, 3}; a[10] = 0;`

* `int* a {0x654321}; *a += 1;`: access random address
