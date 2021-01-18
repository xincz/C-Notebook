#include <stdio.h>
#include <stdint.h>
#include <iostream.h>
#include "io_utils.h"


int main() {
    signed int a = 0x5b;
    int32_t b = 0x5b;

    printf("%d\n", sizeof(signed int));
    printf("%d\n", sizeof(int32_t));

    PRINT_HEX(a);
    PRINT_HEX(b);

    a = a << 20;
    b = b << 20;

    PRINT_HEX(a);
    PRINT_HEX(b);

    uint32_t c = 0x11111111;
    uint32_t d = 0x00000000;

    PRINT_HEX(((c * 512) & 0x1fff));
    PRINT_HEX(((d * 512) & 0x1fff));
    PRINT_HEX(((c >> 6) & 0x1));
    PRINT_HEX(((d >> 6) & 0x1));
    PRINT_HEX(((c & 0x40) / 64));
    PRINT_HEX(((d & 0x40) / 64));
    PRINT_HEX(((c << 9) & 0x8fff));
    PRINT_HEX(((d << 9) & 0x8fff));
    PRINT_HEX(((c & 0x40) / 2));
    PRINT_HEX(((d & 0x40) / 2));
    PRINT_HEX(((c << 10) & 0x1000));
    PRINT_HEX(((d << 10) & 0x1000));


    signed char x = 0xc4;
    int32_t y = x;

    PRINT_HEX(y);

    typedef struct g {
        uint64_t Y0;
        uint64_t a1;
        int16_t O2;
        short y3;
    } gg;

    gg ggg = {11, 12, 13, 14};

//    PRINT_INT(alignof(gg));
    PRINT_INT(sizeof(gg));

    return 0;
}