#include <stdio.h>
#include <stddef.h>
#include "io_utils.h"

// 全局对其设置
//#pragma pack(4)  // 设置对齐倍数为 2
int main() {
    typedef struct Person {
        char *name;  // 8 bytes
        int age;     // 8(4) bytes
        char *id;    // 8 bytes
    } Person;

    struct Person person = {.name="haha", .id="12223311"};

    // 各个类型地址对齐的位置 (倍数) 就是自己占用大小的位置

    // 合理布局，减少内存
    // 会有内存浪费；排序节约内存很重要
    typedef struct {
        char a;   // 1
        char b;   // 1
//        __attribute((aligned(2))) int c;    // 4 对齐到 2, gcc 支持 / msvc 不支持
//        _Alignas(8) int c;    // 4 对齐到 2, gcc 支持 / msvc 不支持
        int c;
        short d;  // 2
        double e; // 8
    } Align;

    typedef struct {
        char a;   // 1
        char b;   // 1
        short d;  // 2
        int c;    // 4
        double e; // 8
    } OptimizedAlign;


    Align align = {'a', 'b', 3, 4, 5.0};
//    PRINT_INT(_Alignof(align.c));  // gcc
    PRINT_INT(offsetof(Align, c));
    return 0;
}
