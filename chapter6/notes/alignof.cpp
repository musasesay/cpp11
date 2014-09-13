// clang++ --std=c++11 -Wpadded alignof.cpp -o alignof

#include <iostream>

using namespace std;

struct TBadAlignment {
    char a;
    int* p;
    char c;
    int e;
    short d;
} Data1;

struct TGoodAlignment {
    int* p;
    int e;
    short d;
    char a;
    char c;
} Data2;

template<typename T>
void Print(const T& object) {
    cout << "---" << endl;
    cout << "    class: " << typeid(T).name() << endl;
    cout << "alignment: " << alignof(T) << endl;
    cout << "     size: " << sizeof(object) << endl;
}

template<typename T1, typename T2>
void Compare(const T1& obj1, const T2& obj2) {
    Print(obj1);
    Print(obj2);
    cout << "===" << endl;
    cout << "size reduce: " << 100 - 100 * sizeof(obj2) / sizeof(obj1) << '%' << endl;
}

int main(int, char* []) {
    cout << "---" << endl;
    cout << " char: " << sizeof(char) << endl;
    cout << "  int: " << sizeof(int) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << " int*: " << sizeof(int*) << endl;
    Compare(Data1, Data2);
    return 0;
}
