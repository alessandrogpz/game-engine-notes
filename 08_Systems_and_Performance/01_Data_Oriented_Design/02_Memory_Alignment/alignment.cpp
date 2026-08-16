#include <iostream>

struct BadLayout {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
}; // Total size: 12 bytes (due to automatic compiler alignment padding)

struct GoodLayout {
    int b;     // 4 bytes
    char a;    // 1 byte
    char c;    // 1 byte
}; // Total size: 8 bytes

int main()
{

    std::cout << "BadLayout size: " << sizeof(BadLayout) << std::endl;
    std::cout << "GoodLayout size: " << sizeof(GoodLayout) << std::endl;

    return 0;
}
