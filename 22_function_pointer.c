#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

// 1
int *f(int, double);  // 相当于
int *(f(int, double));

// 2
int (*g)(int, double);

// 3  返回一个 int 指针
int *(*h)(int, double);

// 4  不合法，不能返回数组
// int (*f)(int, double)[];

// 5
// 函数是独一无二的，不能定义为数组
// 函数指针可以
// f5 是个指针类型的数组，指针类型是 (int, double)
int (*f5[])(int, double);

// 定义太麻烦，使用 typedef 起别名
typedef int (*Func)(int, double);  // Func 即别名

int Add(int left, int right);

typedef int Boolean;
typedef int *IntPtr;
typedef int IntArr[];


void InitPointerGood(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        (*ptr)[i] = default_value;
    }
}

int main() {
    PRINT_HEX(&main);
    PRINT_HEX(&InitPointerGood);

    int a;
    int *p;
    IntPtr q;
    IntArr arr = {};
    // 任何变量，替换为指针就是其变量名加上 *
    // 同理，后面 (...) 是函数指针的类型
    // InitPointerGood 的指针，func 变量名
    void (*func)(int **ptr, int length, int default_value) = &InitPointerGood;

    {
        func(&p, 10, 0);
        PRINT_INT_ARRAY(p, 10);
        free(p);
    }
    {   // 也可以这样调用
        (*func)(&p, 10, 0);
        // 函数名其实也是函数的地址！类似数组！
        (*InitPointerGood)(&p, 10, 0);
    }

    {
        Func func1 = Add;
//        Func func1 = &Add;
    }

    return 0;
}