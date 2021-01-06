#include <stdio.h>
#include "io_utils.h"


// Register
__int128 TestBigValue() {
    return 0;
}

// 函数的正确写法
void SumIntArray(int array[], int length, int *sum) {
    *sum = 0;
    for (int i = 0; i < length; ++i) {
        *sum += array[i];
    }
}

int main() {
    // left: storage
    // right: value
    int a;
    a = 2;

    int *p = &a;
    *p = 2;

    int b = *p;

    // 查看运算优先级：Ctrl + W
    // &a = p;  // ERROR 左边不能为值
    // *p + 1 = 3;  // ERROR
    int array[4] = {0};
    int *pa = array;
    *pa = 1;
    // *pa++ = 3;  // ++ 后计算
    *++pa = 5;    // ++ 先计算
    *(pa + 2) = 3;
    PRINT_INT_ARRAY(array, 4);

    // function calls
    __int128 big_int = TestBigValue();

    int sum;
    SumIntArray(array, 5, &sum);
    PRINT_INT(sum);

    return 0;
}
