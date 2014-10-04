// clang++ --std=c++11 initializer.cpp -o initializer

#include <iostream>

using namespace std;

void Print(int* array) {
    cout << "array has " << *array << " elements" << endl;
    for(int count {*array}; count; --count) {
        cout << *++array << endl;
    }
}

int main(int, char* []) {
    {
        int elements[] {sizeof(*elements), 1, 2, 3};
        *elements = sizeof(elements) / *elements - 1;
        Print(elements);
    }
    cout << "---" << endl;
    {
        int elements[] {sizeof(*elements)};
        *elements = sizeof(elements) / *elements - 1;
        Print(elements);
    }
    return 0;
}
