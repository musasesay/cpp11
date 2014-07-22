// clang++ -std=c++11 nullptr.cpp -o nullptr
//
// nullptr points to nothing and there should be only one nullptr that is
// shared among all pointers

int main() {
    int *a {nullptr};
    int *b {nullptr};

    return a == b ? 0 : 1;
}
