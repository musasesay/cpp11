// clang++ --std=c++11 duffs_device.cpp -o duffs_device

#include <iostream>

using namespace std;

// Duff’s device: http://en.wikipedia.org/wiki/Duff's_device
void Send(int* to, const int* from, int count) {
    int n = (count + 7) / 8;
    switch(count % 8) {
    case 0: do { *to++ = *from++;
    case 7: *to++ = *from++;
    case 6: *to++ = *from++;
    case 5: *to++ = *from++;
    case 4: *to++ = *from++;
    case 3: *to++ = *from++;
    case 2: *to++ = *from++;
    case 1: *to++ = *from++;
        } while(--n > 0);
    }
}

void Print(const int* array, const size_t size) {
    cout << *array;
    for(const int* end {array++ + size}; end > array; ++array) {
        cout << " " << *array;
    }
}

int main(int, char* []) {
    int numbers[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    const size_t size {sizeof(numbers) / sizeof(*numbers)};
    int buffer[size];
    cout << "str: ";
    Print(numbers, size);
    cout << endl;
    for(size_t i {0}; size >= i; ++i) {
        Send(buffer, numbers, i);
        Print(buffer, i);
        cout << endl;
    }
    return 0;
}
