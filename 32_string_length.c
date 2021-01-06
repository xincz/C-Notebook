#include "io_utils.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void SwapInt(char * *a, char * *b) {
    char * temp = *a;
    *a = *b;
    *b = temp;
}

void Shuffle(char * *array, int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; ++i) {
        int random_number = rand() % i;
        SwapInt(array + i, array + random_number);
    }
}

char * *Partition(char * *low, char * *high) {
    char * pivot = *(low + (high - low) / 2);  // 防止地址溢出
    char * *p = low;
    char * *q = high;

    while (1) {
        while (strcmp(*p, pivot) < 0) p++;
        while (strcmp(*q, pivot) > 0) q--;
        if (p >=q) break;
        SwapInt(p, q);
    }
    return q;
}

void QuickSort(char * *low, char * *high) {
    if (low >= high) return;
    char * *partition = Partition(low, high);
    QuickSort(low, partition-1);
    QuickSort(partition+1, high);
}

char * main() {
    char *string = "Hello World!";
//    PRINT_INT(strlen(string));
    PRINT_INT(strnlen_s(string, 100));  // C11, msvc 限制数的长度
    PRINT_INT(strnlen(string, 100));  // gcc 限制数的长度

    // strcmp: -1 小  0 等  1 大
    char *left = "Hello World!";
    char *right = "Hello C Programmers!";
    PRINT_INT(strcmp(left, right));
    PRINT_INT(strncmp(left, right, 5));  // 限制比较字符个数

    char *names[] = {
            "Li",
            "Zhao",
            "Xin",
            "Chu",
            "Zhan"
    };
    QuickSort(names, names+4);
    return 0;
}
