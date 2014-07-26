// clang --std=c++11 io_iter -o io_iter
//
// I/O iterators demo: print sorted unique strings

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <stdexcept>
#include <string>

#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
try {
    if (argc < 2) {
        throw runtime_error{"missing input file"};
    }
    ifstream is {argv[1]};
    if (not is.is_open()) {
        throw runtime_error{"failed to open input file"};
    }

    istream_iterator<string> ii {is};
    istream_iterator<string> eos;
    set<string> data {ii, eos};

    ostream_iterator<string> oi {cout, "\n"};
    copy(data.begin(), data.end(), oi);

    return !is.eof();
} catch(const exception &err) {
    if (isatty(fileno(stderr))) {
        cerr << "\033[0;31merror\033[0m: ";
    } else {
        cerr << "error: ";
    }
    cerr << err.what() << endl;
}
