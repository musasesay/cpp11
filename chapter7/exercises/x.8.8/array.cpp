// clang++ --std=c++11 array.cpp -o array

#include <iostream>

int main(int, char* []) {
    using namespace std;
    char str[] {"a short string"};
    cout << " str: " << str << endl;
    cout << "size: " << sizeof(str) << endl;  // len + trailing \0
    cout << " len: " << strlen(str) << endl;
    return 0;
}
