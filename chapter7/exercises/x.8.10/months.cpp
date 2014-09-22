// clang++ --std=c++11 months.cpp -o months

#include <iostream>

using namespace std;

template<size_t SIZE>
void Print(const char* (&months)[SIZE]) {
    cout << "size: " << SIZE << endl;
    for(const char* month : months) {
        cout << month << endl;
    }
}

int main(int, char* []) {
    const char* months[] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cout << "len: " << sizeof(months) / sizeof(months[0]) << endl;
    for(const char* month : months) {
        cout << month << endl;
    }
    cout << "---" << endl;
    Print(months);
    return 0;
}
