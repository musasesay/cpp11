// clang++ --std=c++11 -Wpadded chars.cpp -o chars

#include <iostream>
#include <iomanip>

using namespace std;

void PrintCharsInRange(char from, char to) {
    for(char ch {from}; ch <= to; ++ch) {
        int code {ch};
        cout << setw(3) << right << code << " (0x" << hex << code << dec << "): " << ch << endl;
    }
}

void Split() {
    cout << "---" << endl;
}

int main(int, char* []) {
    PrintCharsInRange('a', 'z');
    Split();
    PrintCharsInRange('0', '9');
    return 0;
}
