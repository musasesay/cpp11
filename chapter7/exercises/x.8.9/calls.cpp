// clang++ --std=c++11 calls.cpp -o calls

#include <iostream>

using namespace std;

void F1(char arg) {
    cout << __func__ << " arg:" << arg << endl;
}

void F2(char& arg) {
    cout << __func__ << " arg:" << arg << ' ' << static_cast<void*>(&arg) << endl;
}

void F3(const char& arg) {
    cout << __func__ << " arg:" << arg << ' ' << static_cast<const void*>(&arg) << endl;
}

void Split() {
    cout << "---" << endl;
}

int main(int, char* []) {
    // Illegal call are commented out
    F1('a');
    // F2('a');  // 'a' is an rvalue but F2 expects lvalue
    F3('a');  // temp variable
    Split();
    F1(49);
    // F2(49);  // implicit conversion int to char; F2 expect lvalue but rvalue is given
    F3(49);  // temp variable
    Split();
    // Implementation defined calls - possible compiler warnings
    F1(3300);
    // F2(3300);  // see above
    F3(3300);  // temp variable
    Split();
    {
        char ch {'c'};
        cout << "ch:" << ch << ' ' << static_cast<void*>(&ch) << endl;
        F1(ch);
        F2(ch);
        F3(ch);
    }
    Split();
    {
        unsigned char ch {'u'};
        cout << "ch:" << ch << ' ' << static_cast<void*>(&ch) << endl;
        F1(ch);
        // F2(ch);  F2 expects a char
        F3(ch);  // temp variable - implicit conversion - unsigned char to char
    }
    Split();
    {
        signed char ch {'s'};
        cout << "ch:" << ch << ' ' << static_cast<void*>(&ch) << endl;
        F1(ch);
        // F2(ch);  function expects char
        F3(ch);  // temp variable - implicit conversion - signed char to char
    }
    return 0;
}
