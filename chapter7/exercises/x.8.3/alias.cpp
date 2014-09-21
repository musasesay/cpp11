// clang++ --std=c++11 alias.cpp -o alias

// aliases
using TUChar = unsigned char;
using TCUChar = const unsigned char;
using TPInt = int*;
using TPPChar = char**;  // pointer to pointer to char
using TPChars = char (*)[6];  // pointer to array of char
using TPInts = int* [7];  // array of 7 pointers to int
using TPPInts = int* (*)[7];  // pointer to an array of 7 pointers to int
using TMatrix = int* [7][8];  // array of 8 arrays of 7 pointers to int

// declarations (testing)
TUChar ch {'a'};
TCUChar anotherCh {'z'};
TPInt p {nullptr};
char str[] {"Hello"};
char* value {str};
TPPChar q {&value};
TPChars chars {&str};
TPInts numbers;
TPPInts heights {&numbers};
TMatrix matrix;

int main(int, char* []) {
    return 0;
}
