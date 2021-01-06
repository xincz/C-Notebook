#include <stdio.h>
#include "io_utils.h"

int main() {
    {
        double a = 2.0;
        double *p = &a;
        double **pp = &p;

        // 移动类型对应的字节数
        PRINT_INT(pp);
        PRINT_INT(pp+1);
        PRINT_INT(sizeof(double *));
    }

    {
        // array 本身也是个地址，是个指针！
        int array[] = {0, 1, 2, 3, 4};
        int *p = array;  // array 是地址！
        PRINT_INT(*(p+3));  // 推荐
        PRINT_INT(*(array+3));
        PRINT_INT(array[3]);  // 推荐
        PRINT_INT(p[3]);
        PRINT_INT(*(3+array));
        PRINT_INT(3[array]);
        PRINT_INT(3[p]);

        // 但是 array 是个不能指向其他地址的指针
        // array = (int *) 100;  // ERROR
        // 相当于 const 只读指针
        int *const array_p = array;

        PRINT_BOOL(p+3 > p+1);
    }

    return 0;
}
