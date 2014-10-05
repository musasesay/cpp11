// clang++ --std=c++11 while.cpp -o while

#include <iostream>

using namespace std;

size_t CountWithWhile(const char* str) {
    size_t counter {0};
    while(*str) {
        if (*str++ == '?') {
            ++counter;
        }
    }
    return counter;
}

class TIterable {
public:
    TIterable(const char* str)
        : String {str}
    {}
    const char* begin() {
        return String;
    }
    const char* end() {
        const char* str {String};
        while(*str) {
            ++str;
        }
        return str;
    }
private:
    const char* String;
};

size_t CountWithRangeFor(const char* str) {
    size_t counts {0};
    for(const auto& ch : TIterable {str}) {
        if (ch == '?') {
            ++counts;
        }
    }
    return counts;
}

int main(int, char* []) {
    const char* str {"hello! where am I? Do you know? Yes."};
    cout << str << endl;
    cout << "? is found " << CountWithWhile(str) << " times" << endl;
    cout << "? is found " << CountWithRangeFor(str) << " times" << endl;
    return 0;
}
