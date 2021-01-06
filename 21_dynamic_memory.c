#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

#define COUNT 10

// ptr 会被销毁，跟外部无关
void InitPointer(int *ptr, int length, int default_value) {
    ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        ptr[i] = default_value;
    }
}

// 改进：pass in a pointer of a pointer
void InitPointerGood(int **ptr, int length, int default_value) {
    *ptr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        (*ptr)[i] = default_value;
    }
}

int main() {
    // Array is in stack
    // This is in heap
    // 因为在堆区域，函数释放时其也不会释放
    {
        int *some = malloc(sizeof(int) * COUNT);
        for (int i = 0; i < COUNT; ++i) {
            some[i] = i;
        }
        PRINT_INT_ARRAY(some, COUNT)
        PRINT_INT(*some);

        // 释放内存
        free(some);

        PRINT_INT(*some);
    }

    {   // 面试重难点！
        // 传递指针时要传递指针的指针
        int *players;  // 指针变量传递时被复制
        InitPointerGood(&players, COUNT, 0);
        for (int i = 0; i < COUNT; ++i) {
            PRINT_INT(players[i]);
            players[i] = i;
        }
        PRINT_INT_ARRAY(players, COUNT);
        free(players);
    }

    {   // 更好的选择
        // calloc 返回的内存会先被清空，设置为零
        int *players = calloc(COUNT, sizeof(int));
        for (int i = 0; i < COUNT; ++i) {
            PRINT_INT(players[i]);
            players[i] = i;
        }
        // 重新分配内存，但新追加的内存也不会被清空
        players = realloc(players, COUNT * 2 * sizeof(int));
        PRINT_INT_ARRAY(players, COUNT * 2);
        free(players);
    }

    return 0;
}
