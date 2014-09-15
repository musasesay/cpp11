// clang --std=c++11 -Wpadded alignas.cpp -o alignas

#include <cstddef>
#include <chrono>
#include <iostream>

template<class TClock>
class TTimer {
public:
    using TDuration = std::chrono::duration<double>;
    void Stop() {
        if (not Stopped) {
            StopTimepoint = TClock::now();
            Stopped = true;
        }
    };
    TDuration Duration() {
        if (not Stopped) {
            Stop();
        }
        return std::chrono::duration_cast<TDuration>(StopTimepoint - StartTimepoint);
    };
private:
    typename TClock::time_point StartTimepoint {TClock::now()};
    typename TClock::time_point StopTimepoint;
    bool Stopped {false};
};

using THRClock = std::chrono::high_resolution_clock;
using THighResolutionTimer = TTimer<THRClock>;

std::ostream& operator<<(std::ostream& os, const TTimer<THRClock>::TDuration& duration) {
    return os << duration.count() << 's';
}

struct TData {
    char A;
    char B;
    char C;
    char D;
    char E;
    char F;
    char G;
    char H;
};

template<size_t Size>
void Process(TData (&data)[Size]) {
    for(auto& x : data) {
        x.A = 'a';
        x.B = 'b';
        x.C = 'c';
        x.D = 'd';
        x.E = 'e';
        x.F = 'f';
        x.G = 'g';
        x.H = 'h';
    }
}

template<typename T>
void Run() {
    using namespace std;
    const size_t SIZE = 1e6;
    alignas(T) TData Data[SIZE];
    THighResolutionTimer timer;
    Process(Data);
    timer.Stop();
    cout << typeid(T).name() << " alignment: " << alignof(T) << " elapsed: " << timer.Duration() << endl;
}

int main(int, char* []) {
    Run<char>();
    Run<short>();
    Run<int>();
    Run<long>();
}
