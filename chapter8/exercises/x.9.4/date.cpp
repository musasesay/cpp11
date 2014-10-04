// clang++ --std=c++11 date.cpp -o date

#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

struct TDate {
    int Year;
    int Month;
    int Day;
    explicit TDate(int y=1970, int m=1, int d=1)
        : Year {y}
        , Month {m}
        , Day {d}
    {}
};

istream& operator>>(istream& is, TDate& date) {
    // accepted format YYYY MM DD - don't care about validity
    return is >> date.Year >> date.Month >> date.Day;
}

ostream& operator<<(ostream& os, const TDate& date) {
    struct TFill {
        TFill(ostream& stream, char ch)
            : OutputStream {stream}
            , FillChar {stream.fill(ch)}
        {}
        ~TFill() {
            OutputStream.fill(FillChar);
        }
        ostream& OutputStream;
        char FillChar;
    } fill {os, '0'};
    return os << setw(2) << right << date.Month << '/' << setw(2) << right << date.Day << '/' << setw(4) << right << date.Year;
}

using TDates = list<TDate>;

TDates ReadDates(const size_t SIZE) {
    TDates dates;
    for(TDate date; cin.good() and dates.size() < SIZE; ) {
        cin >> date;
        if (cin.good()) {
            dates.push_back(date);
            cout << "got it, " << SIZE - dates.size() << " date(s) to go" << endl;
        }
    }
    return dates;
}

int main(int, char* []) {
    TDate defaultDate;
    cout << "default date is " << defaultDate << endl;
    TDate date {1, 2, 3};
    cout << "some date is " << date << endl;
    cout << "---" << endl;
    const size_t MAX_DATES {3};
    cout << "Let's read several dates from input (max " << MAX_DATES << " dates)" << endl;
    cout << "Dates should have YYYY MM DD format" <<endl;
    cout << "(press Ctrl-D to exit)" << endl;
    TDates dates {ReadDates(MAX_DATES)};
    if (dates.empty()) {
        cout << "you didn't input any valid date" << endl;
    } else {
        cout << "---" << endl;
        for(const auto& date : dates) {
            cout << date << endl;
        }
    }
    return 0;
}
