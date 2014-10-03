// clang++ --std=c++11 enum_scope.cpp -o enum_scope

enum class ERainbow {
    Red,
    Green,
    Blue
};

enum class ELight {
    Red,
    Yellow,
    Green
};

namespace NTest {
    enum EAnimal {
        A_Cat,
        A_Dog,
        A_Lion
    };

    /*
     * plain enum shares the same scope with other enums: therefore enumerators
     * MUST have different names - see NLife::EAnother
     *
    enum EAnother {
        A_Cat,
        A_Dog
    };
    */
}

namespace NLife {
    enum EAnother {
        A_Cat,
        A_Dog
    };
}

int main(int, char* []) {
    return 0;
}
