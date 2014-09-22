// clang++ --std=c++11 pairs.cpp -o pairs

#include <iostream>
#include <map>
#include <string>

using namespace std;

class TCounter {
public:
    TCounter(const char* str, size_t subStringLen=2)
        : String {str}
        , Length {subStringLen}
    {
        Init();
    }
    TCounter(const string& str, size_t subStringLen=2)
        : String {str}
        , Length {subStringLen}
    {
        Init();
    }
    string Str() const {
        return String;
    }
    size_t SubStrLength() const {
        return Length;
    }
    bool Has(const string& substr) const {
        return SubStrings.count(substr);
    }
    size_t operator[](const string& substr) const {
        return SubStrings.at(substr);
    }
private:
    void Init() {
        if (String.size() >= Length) {
            for(size_t pos {0}, end {String.size() - Length + 1}; pos < end; ++pos) {
                ++SubStrings[String.substr(pos, Length)];
            }
        }
    }
private:
    string String;
    size_t Length;
    map<string, size_t> SubStrings;
};

class TSubStrings {
public:
    class TIterator {
    public:
        TIterator()
            : SubStr {}
        {}
        TIterator(size_t len, char ch)
            : SubStr (len, ch)
        {}
        string& operator*() {
            return SubStr;
        }
        TIterator& operator++() {
            if (not SubStr.empty()) {
                for(size_t pos {SubStr.size()}; pos--; ) {
                    if (SubStr[pos] == 'z') {
                        SubStr[pos] = 'a';
                    } else {
                        ++SubStr[pos];
                        return *this;
                    }
                }
                SubStr.clear();
            }
            return *this;
        }
        bool operator!=(const TIterator& that) {
            return SubStr != that.SubStr;
        }
    private:
        string SubStr;
    };
public:
    TSubStrings(const size_t& len)
        : Length {len}
    {}
    TIterator begin() {
        return TIterator {Length, 'a'};
    }
    TIterator end() {
        return TIterator {};
    }
private:
    size_t Length;
};

void CountAllCombinations(const TCounter& counter) {
    cout << "str: " << counter.Str() << endl;
    cout << "len: " << counter.Str().size() << endl;
    cout << "sub str len: " << counter.SubStrLength() << endl;
    if (counter.SubStrLength() <= counter.Str().size()) {
        for(const string& subStr : TSubStrings {counter.SubStrLength()}) {
            if (counter.Has(subStr)) {
                cout << ' ' << subStr << ": " << counter[subStr] << endl;
            }
        }
    }
}

int main(int, char* []) {
    CountAllCombinations(TCounter {"xabaacbaxabb"});
    cout << "---" << endl;
    CountAllCombinations(TCounter {string {"xabaacbaxabb"}, 3});
    cout << "---" << endl;
    CountAllCombinations(TCounter {string {"xabaacbaxabb"}, 4});
    cout << "---" << endl;
    CountAllCombinations(TCounter {"xabaacbaxabb", 1});
    return 0;
}
