// clang++ --std=c++11 move.cpp -o move
//
// Demonstrate constructor, destructor, copy, and move operators

#include <iostream>

using namespace std;

struct TContainer {
    TContainer(const int& value=0)
        : Value{value}
    {}
    int Value;
};

class TTest;
ostream& log(const TTest& obj);
ostream& err(const TTest& obj);

class TTest {
    // invariant: TTest object should have an existing container associated to it
public:
    using TValueType = decltype(TContainer::Value);

    // Constructor and Destructor
    TTest(const int& value)
        : Container{new TContainer{value}}
    {
        log(*this) << "Test constructor" << endl;
    }
    ~TTest() {
        log(*this) << "Test destructor" << endl;
        if (Container) {
            log(*this) << "  destroy Container" << endl;
            delete Container;
        }
    }

    // copy operators
    TTest(const TTest& that)
        : Container{new TContainer}
    {
        log(*this) << "Test copy constructor" << endl;
        if (that.IsValid()) {
            Container->Value = that.Container->Value;
        }
    }
    TTest& operator=(const TTest& that) {
        log(*this) << "Test copy assignment" << endl;
        if (this != &that) {
            TContainer* OldContainer {Container};
            if (that.IsValid()) {
                TContainer* NewContainer {new TContainer{that.Container->Value}};
                Container = NewContainer;
            } else {
                Container = nullptr;
            }
            if (OldContainer) {
                delete OldContainer;
            }
        }
        return *this;
    }

    // move operators
    TTest(TTest&& that)
        : Container(that.Container)
    {
        log(*this) << "Test move constructor" << endl;
        that.Container = nullptr;
    }
    TTest& operator=(TTest&& that) {
        log(*this) << "Test move assignment" << endl;
        if (this != &that) {
            TContainer* OldContainer {Container};
            Container = that.Container;
            that.Container = nullptr;
            if (OldContainer) {
                delete OldContainer;
            }
        }
        return *this;
    }

    bool IsValid() const { return static_cast<bool>(Container); }
    TValueType Value() const {
        if (not IsValid()) {
            throw runtime_error("failed to extract value - Container does not exist");
        }
        return Container->Value;
    }
    void SetValue(const TValueType& value) {
        if (IsValid()) {
            Container->Value = value;
        } else {
            Container = new TContainer {value};
        }
    }
private:
    TContainer* Container;
};

ostream& operator<<(ostream& os, const TTest& test) {
    return os << &test << ' ' << (test.IsValid() ? "valid" : "invalid") << ' ' << (test.IsValid() ? test.Value() : -1);
}

ostream& log(const TTest& obj) {
    return cout << obj << ' ';
}

ostream& err(const TTest& obj) {
    return cerr << "error: " << obj;
}

TTest CreateTest(const TTest::TValueType& value) {
    cout << "Create Test" << endl;
    return TTest {value};
}

void UseTest(TTest value) {
    cout << "Use Test " << value << endl;
}

int main()
try {
    TTest test1 {1};  // constructor
    log(test1) << "status" << endl;

    cout << "---" << endl;
    TTest test2 {test1};  // copy constructor
    test1.SetValue(2);
    log(test1) << "status" << endl;
    log(test2) << "status" << endl;

    cout << "---" << endl;
    test2 = test1;  // copy assignment
    log(test1) << "status" << endl;
    log(test2) << "status" << endl;

    cout << "---" << endl;
    TTest test30 {TTest{30}};  // constructor (optimization)
    log(test30) << "status" << endl;

    cout << "---" << endl;
    TTest test31 {move(TTest{31})};  // move constructor
    log(test31) << "status" << endl;

    cout << "---" << endl;
    TTest test3 {CreateTest(11)};  // constructor (optimization)
    log(test3) << "status" << endl;

    cout << "---" << endl;
    TTest test4 {move(CreateTest(12))};  // move constructor
    log(test4) << "status" << endl;

    cout << "---" << endl;
    test4 = CreateTest(13);  // move assignment
    log(test4) << "status" << endl;

    cout << "---" << endl;
    test4 = move(test1);  // move assignment: test1 is invalid
    log(test4) << "status" << endl;
    log(test1) << "status" << endl;

    cout << "---" << endl;
    UseTest(test2);  // copy constructor
    log(test2) << "status" << endl;

    cout << "---" << endl;
    UseTest(TTest{21});  // constructor (optimization)

    cout << "---" << endl;
    UseTest(move(TTest{22}));  // move constructor

    cout << "===" << endl;

    return 0;
}
catch(const exception& error) {
    cerr << "error: " << error.what() << endl;
    return 1;
}
