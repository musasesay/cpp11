// clang++ --std=c++11 char_pointers.cpp -o char_pointers
//
// the three char types are distinct: pointers do not mix

int main(int, char* [])
{
    char c {'a'};
    unsigned char uc {'a'};
    signed char sc {'a'};

    char* pc {&c};
    char* puc {&uc};
    char* psc {&sc};

    unsigned char* upc {&c};
    unsigned char* upuc {&uc};
    unsigned char* upsc {&sc};

    signed char* spc {&c};
    signed char* spuc {&uc};
    signed char* spsc {&sc};

    return 0;
}
