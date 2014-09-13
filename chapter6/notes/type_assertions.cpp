// clang++ --std=C++11 type_assertions.cpp -o type_assertions

int main(int, char* []) {
    static_assert(sizeof(char) <= sizeof(short), "char should be <= than short");
    static_assert(sizeof(short) <= sizeof(int), "short should be <= than int");
    static_assert(sizeof(int) <= sizeof(long), "int should be <= than long");
    static_assert(sizeof(long) <= sizeof(long long), "long should be <= than long long");

    static_assert(sizeof(char) <= sizeof(bool), "char should be <= than bool");
    static_assert(sizeof(bool) <= sizeof(long), "bool should be <= than long");

    static_assert(sizeof(char) <= sizeof(wchar_t), "char should be <= than wchar_t");
    static_assert(sizeof(wchar_t) <= sizeof(long), "wchar_t should be <= than long");

    static_assert(sizeof(float) <= sizeof(double), "float should be <= than double");
    static_assert(sizeof(double) <= sizeof(long double), "double should be <= than long double");

    return 0;
}
