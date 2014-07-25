// clang++ --std=c++11 back_inserter.cpp -o back_inserter
//
// back_inserter adds elements to the end

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& col) {
    for(const auto& x : col) {
        os << x << ' ';
    }
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const list<T>& col) {
    for(const auto& x : col) {
        os << x << ' ';
    }
    return os;
}

int main() {
    using Vint = vector<int>;

    Vint input {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "input: " << input << endl;

    // you may copy first N elements into a list that has exactly N elements
    cout << "-- copy into a list" << endl;
    Vint::iterator iter = input.begin();
    advance(iter, 5);
    {
        list<int> output (5);
        copy(input.begin(), iter, output.begin());
        cout << "output: " << output << endl;
    }

    // or use back_inserter to dynamically grow the list
    cout << "-- copy with back_inserter" << endl;
    {
        list<int> output;
        copy(iter, input.end(), back_inserter(output));
        cout << "output: " << output << endl;
    }

    return 0;
}
