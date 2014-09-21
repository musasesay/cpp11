// clang++ --std=c++11 declarations.cpp -o declarations

// declarations
extern char* p;  // a pointer to a char;
extern int heights[10];  // an array of 10 integers
extern int (&adults)[10];  // a reference to array of 10 ints
extern const char* (*strings)[10];  // a pointer to an array of character strings
extern char* (*q);  // a pointer to a pointer to a character
extern const int size;  // a constant integer
extern const int* documents;  // a pointer to a constant integer
extern int* const limit;  // a constant pointer to an integer

// Initializations
char* p {nullptr};
int heights[10];
int (&adults)[10] {heights};
const char* (*strings)[10] {nullptr};
char* (*q) {nullptr};
const int size {53};
const int* documents {&size};
int* const limit {nullptr};

int main(int, char* []) {
    return 0;
}
