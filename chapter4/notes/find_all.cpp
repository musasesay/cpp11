// clang++ --std=c++11 find_all.cpp -o find_all
//
// find all occurence each char of a string
//
// usage: find_all <string>

#include <iomanip>
#include <iostream>
#include <list>
#include <string>

#include <unistd.h>

using namespace std;


template<class C>
using TValue = typename C::value_type;

template<class C>
using TConstIterator = typename C::const_iterator;

template<class C>
using TResults = list<TConstIterator<C>>;


template<class T>
struct TCmp {
    virtual ~TCmp() {}
    virtual bool operator()(const T&) const = 0;
};

template<class T>
struct TEqual : TCmp<T> {
    TEqual(const T& val)
        : Value(val)
    {}
    virtual bool operator()(const T& val) const {
        return val == Value;
    }
private:
    const T& Value;
};


struct TCaseNonSensitiveEqual : TCmp<char> {
    TCaseNonSensitiveEqual(const char& value)
        : VALUE(tolower(value))
    {}

    virtual bool operator()(const char& val) const {
        return tolower(val) == VALUE;
    }
private:
    const char VALUE;
};

template<class C>
TResults<C> FindAll(const C& col, const TValue<C>& value) {
    return FindAll(col, TEqual<TValue<C>>{value});
}

template<class C>
TResults<C> FindAll(const C& col, const TCmp<TValue<C>>& cmp=TEqual<TValue<C>>{}) {
    TResults<C> result;
    for(TConstIterator<C> iter {col.begin()}; col.end() != iter; ++iter) {
        if (cmp(*iter)) {
            result.push_back(iter);
        }
    }
    return result;
}


const bool IS_TTY = isatty(fileno(stdout));

template<class C>
void Print(const TResults<C>& res, const C& col, const size_t indent=0) {
    if (IS_TTY) {
        TConstIterator<C> iter {col.begin()};
        for(TConstIterator<TResults<C>> pos {res.begin()}; pos != res.end() and iter != col.end(); ++iter) {
            if (iter == *pos) {
                ++pos;
                cout << "\033[0;32m" << *iter << "\033[0m";
            } else {
                cout << *iter;
            }
        }
        for(; iter != col.end(); ++iter) {
            cout << *iter;
        }
    } else {
        for(const auto& x : col) {
            cout << x;
        }
        cout << endl;
        TConstIterator<C> iter {col.begin()};
        if (indent) {
            cout << setw(indent) << ' ';
            for(const auto& x : res) {
                cout << setw(distance(iter, x)) << '*';
                iter = x;
            }
        } else {
            for(const auto& x : res) {
                cout << setw(distance(iter, x) + (iter == col.begin() ? 1 : 0)) << '*';
                iter = x;
            }
        }
    }
    cout << endl;
}

int main(int argc, char* argv[])
try
{
    if (argc < 2) {
        throw runtime_error("missing an argument string");
    }
    string str;
    bool insertSpace = false;
    for(size_t i {1}; i < argc; ++i) {
        if (insertSpace) {
            str += ' ';
        } else {
            insertSpace = true;
        }
        str += argv[i];
    }
    cout << "-- Case Sensitive Search" << endl;
    for(const auto& ch : str) {
        if (iscntrl(ch) or isspace(ch)) {
            continue;
        }
        if (IS_TTY) {
            cout << "[\033[0;35m" << ch << "\033[0m] ";
        } else {
            cout << '[' << ch << "] ";
        }
        const auto result = FindAll(str, ch);
        Print(result, str, 4);
    }
    cout << "-- Case non-Sensitive Search" << endl;
    for(const auto& ch : str) {
        if (iscntrl(ch) or isspace(ch)) {
            continue;
        }
        if (IS_TTY) {
            cout << "[\033[0;35m" << ch << "\033[0m] ";
        } else {
            cout << '[' << ch << "] ";
        }
        const auto result = FindAll(str, TCaseNonSensitiveEqual{ch});
        Print(result, str, 4);
    }
    return 0;
} catch(const runtime_error& err) {
    if (isatty(fileno(stderr))) {
        cout << "\033[0;31merror\033[0m: ";
    } else {
        cout << "error: ";
    }
    cout << err.what() << endl;
}
