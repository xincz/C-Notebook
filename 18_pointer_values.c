#include <stdio.h>
#include "io_utils.h"

int *pointer_at_large;

void DangerousPointer() {
    int a = 2;  // stack memory
    pointer_at_large = &a;  // 自动变量的地址！
    // ...
    pointer_at_large = NULL;  // 一定要把野指针设为 NULL
}

int main() {
    // 指针用 hard code 去赋值很危险
    int *p = 100;  // 拿 int 去初始化指针，不推荐
    int *q = (int *) 100;
    PRINT_INT(p);
    PRINT_INT(*p);  // 读指针会出问题 (100 地址不能访问)
    PRINT_HEX(&p);

    int *u = NULL; // 0 这个地址都可以访问
    // *p = 3;  // ERROR

    // 判断指针能否使用
    if (p) {

    }

    DangerousPointer();
    PRINT_INT(*pointer_at_large);  // 无法判断地址是否有效

    return 0;
}
