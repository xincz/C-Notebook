#include <stdio.h>
#include "io_utils.h"

int main() {
    int a = 110;
    int *p = &a;
    PRINT_HEX(p);
    PRINT_HEX(&a);
    PRINT_INT(*p);
    PRINT_INT(a);
    // 一般指针对于 32 位的编译器是 4 字节，对应 64 位的是 8 字节
    PRINT_INT(sizeof(int*));

    int **pp = &p;
    // *pp => p
    int b;

    *p = 20;
    PRINT_INT(*p);
    PRINT_INT(a);

    // 规律：从后往前 //

    // 1
    // 只读指针
    // 一个 const 指针 指向 一个 int 变量
    int *const cp = &a;
    *cp = 2;  // 可以修改
    // cp = &b;  // ERROR 只读指针不能重指向

    // 2
    // 一个 const 指针 指向 一个 const int 变量
    int const *const ccp = &a;
    // *ccp = 2;  // ERROR 因为指向一个只读变量 所以不能修改
    // ccp = &b;  // ERROR 只读指针不能重指向

    // 3
    // 一个指针 指向 一个 const int 变量
    int const *cp2 = &a;  // 和第一种情况正好相反
    cp2 = &b;  // 自己可以重新指向
    // *cp2 = 2;  // ERROR 不能修改只读变量

    return 0;
}