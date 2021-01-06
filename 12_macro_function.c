#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

#define IS_HEX_CHARACTER(ch) \
((ch) >= '0' && (ch) <= '9')

int main() {
    // MACRO 只是简单的替换
    // 函数则会求值后替换
    int max = MAX(1, 3);
    int max2 = MAX(1, MAX(3, 4));

    printf("max2: %d\n", max2);
    printf("hex? %d\n", IS_HEX_CHARACTER('1'));
    return 0;
}