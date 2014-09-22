// clang++ --std=c++11 words.cpp -o words

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main(int, char* []) {
    using namespace std;
    list<string> words;
    for(string word; cin >> word and word != "Quit"; ) {
        if (words.end() == find(words.begin(), words.end(), word)) {
            words.push_back(word);
        }
    }
    cout << "---" << endl;
    for(const auto& word : words) {
        cout << word << endl;
    }
    cout << "--- sort" << endl;
    words.sort();
    for(const auto& word : words) {
        cout << word << endl;
    }
    return 0;
}
