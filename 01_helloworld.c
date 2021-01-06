#include <stdio.h>
#include <limits.h>

int main() {
    short int short_int = 0;
    long int long_int = 100;
    long long longlong_int = 0;
    unsigned int unsigned_int = 123;
    unsigned long unsigned_long = 111;
    size_t size_of_int = sizeof(int);  // this is alias!

    printf("int in hex: %x\n", long_int);  // 64
    printf("int in oct: %o\n", long_int);  // 144

    // %d: decimal
    // %hd: short decimal
    // %ld: long decimal
    // %lld: long long decimal
    // %hu: unsigned short decimal
    printf("short int: %d\n", sizeof(short int));
    printf("int: %d\n", sizeof(int));
    printf("long int: %d\n", sizeof(long int));
    printf("long long int: %lld\n", sizeof(long long int));

    printf("max int: %d, min int: %d\n", INT_MAX, INT_MIN);
    printf("max short int: %d, min short int: %d\n", SHRT_MAX, SHRT_MIN);
    printf("max long int: %d, min long int: %d\n", LONG_MAX, LONG_MIN);
    printf("max unsigned int: %u, min unsigned int: %u\n", UINT_MAX, 0);

    for (int i=0; i<5; i++) {
//        printf("Hello, World!\n");
    }
    return 0;
}
