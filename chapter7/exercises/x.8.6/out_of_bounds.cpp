// clang++ --std=c++11 out_of_bounds.cpp -o out_of_bounds

#include <memory>

void Test(int* array, int size) {
    // beyond and far beyond
    array[size] = 1;
    array[size + 10000] = 2;
    // before and far before
    *(array - 1) = 3;
    *(array - 10000) = 4;
}

int Global[] {1, 2, 3};

void Heap() {
    using namespace std;
    unique_ptr<int[]> Local {new int[3]};
    Test(Local.get(), 3);
}

class TMember {
public:
    void Test() {
        ::Test(Member, 5);
    }
private:
    int Member[5] {2, 4, 8, 16, 32};
};

int main(int, char* []) {
    Test(Global, 3);
    int Local[] {4, 5};
    Test(Local, 2);
    Heap();
    TMember obj;
    obj.Test();
    return 0;
}
