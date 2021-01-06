#include <stdio.h>
#include "io_utils.h"

#define ARRAY_SIZE 10


// 数组一定要传长度
int SumInArray(int array[], int length) {
    int sum = 0;
    for (int i=0; i<length; i++) {
        sum += array[i];
    }
    return sum;
}

// VLA 变长数组
// 数组返回值
// 数组作为参数传递时只是 1D array, array 只是其起始地址
void SumInArray2d(int rows, int cols, int array[][cols], int result[]) {
    for (int i=0; i<rows; i++) {
        for (int j = 0; j < cols; ++j) {
            result[i] += array[i][j];
        }
    }
}

int main() {
    int array[ARRAY_SIZE];

    for (int i=0; i<ARRAY_SIZE; i++) {
        array[i] = i;
//        PRINT_INT(array[i]);
    }

    int array_2[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i=0; i<ARRAY_SIZE; i++) {
        PRINT_INT(array_2[i]);
    }

    // 默认为零
    double array_double[5] = {0.1, 2.3};
    for (int i=0; i<5; i++) {
        PRINT_DOUBLE(array_double[i]);
    }

    // C99 特性
    // 初始化为空
    // 从 2 之后依次赋值
    char array_char[5] = {[2] = 'o', 'l', 'l'};
    for (int i=0; i<5; i++) {
        PRINT_CHAR(array_char[i]);
    }

    // VLA
    int value = 2;
    int array_size_of_value[value];

    // 只读变量到底也是变量
    const int k_size = 5;
    int array_size_of_const[k_size];

    // 2D array
    int arr2d[5][2] = {
            0, 5, 1, [1][1] = 5, 6, 7, 8, 9
    };

    return 0;
}
