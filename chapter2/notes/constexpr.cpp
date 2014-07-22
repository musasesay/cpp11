// clang++ -std=c++11 constexpr.cpp -o constexpr
//
// demonstration of failing use of variable in a constexpr: the code will not
// compile.

constexpr int Square(int x) { return x * x; }

int main() {
    constexpr int a = 5;
    int b = 10;
    constexpr int c = Square(a);  // ok
    constexpr int d = Square(b);  // error: used in constexpr with var arg
    int e = Square(a);  // ok
    int f = Square(b);  // ok

    return 0;
}
