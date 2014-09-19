// clang --std=c++11 declarations.cpp -o declarations

#include <complex>
#include <string>
#include <vector>

using namespace std;

// char ch;
char ch {'a'};

// string s;
string s {"C++"};

// auto count = 1;
extern int count;

// const double pi {3.14};
extern const double pi;

// extern int error_number;
int erro_number {10};

// const char* name = "Njal";
extern const char* name;

// const char* season[] = {"spring", "summer", "fall", "winter"};
extern const char* season[];

// vector<string> people {name, "Skarphedin", "Gunnar"};
extern vector<string> people;

// struct Date { int d, m, y; };
struct Date { int d, m, y; } date {1, 2, 3};

// int day(Date* p) { return p->d; }
int day(Date* p);

// double sqrt(double);
double sqrt(double value) { return value; }

// template<class T> T abs(T a) { return a < 0 ? -a : a; }
template<class T> T abs(T);

// constexpr int fac(int n) { return (n < 2) ? 1 : n * fac(n - 1); }
constexpr int fac(int);

// constexpr double zz {ii * fac(7) };
// constexpr can not be have separate declaration: it has to be defined right away

// using Cmplx = std::complex<double>;
using Cmplx = std::complex<double>;

// struct User;
struct User { string name; int age; };

// enum class Beer { Carlsberg, Tuborg, Thor };
enum class Beer;

// namespace NS { int a; }
namespace NS {
    int a {10};
}

int main(int, char* []) {
    return 0;
}
