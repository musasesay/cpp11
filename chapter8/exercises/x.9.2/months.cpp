// clang++ --std=c++11 months.cpp -o months

#include <iostream>

using namespace std;

struct TMonth {
    const char* Name;
    size_t Days;
};

ostream& operator<<(ostream& os, const TMonth& month) {
    return os << month.Name << " has " << month.Days << " days";
}

int main(int, char* []) {
    const char* monthNames[] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    size_t monthDays[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    size_t i {0};
    for(const auto& month : monthNames) {
        cout << month << " has " << monthDays[i] << " days" << endl;
        ++i;
    }
    cout << "---" << endl;
    TMonth months[] {{"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30}, {"May", 31}, {"Jun", 30}, {"Jul", 31}, {"Aug", 31}, {"Sep", 30}, {"Oct", 31}, {"Nov", 30}, {"Dec", 31}};
    for(const auto& month : months) {
        cout << month << endl;
    }
    return 0;
}
