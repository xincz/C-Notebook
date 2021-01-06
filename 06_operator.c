#include <stdio.h>


int main() {
    int first = 0;
    int second = 0;
    int third = 0;

    // <- <-
    third = second = first;

    int a = 2;
    int b = 3;
    float res = 0.f;

    res = (float) a / (float) b;
    printf("res is: %f\n", res);

    // 必须在内存中才能自增或自减
    int i = 1;
    int j = i++;  // j=1, i=2
    int k = ++i;  // k=3, i=3
    printf("i is: %d\n", i);
    printf("j is: %d\n", j);
    printf("k is: %d\n", k);

    // 常量不能做自增，只能是变量
    // 1++;

    // bit operators 按位 & | ^ ~
    // 定义开关
#define FLAG_VISIBLE 0x1      // 0001
#define FLAG_TRANSPARENT 0x2  // 0010
#define FLAG_RESIZABLE 0x4    // 0100

    int window_flags = FLAG_RESIZABLE | FLAG_TRANSPARENT;  // 0110
    int resizable = window_flags & FLAG_VISIBLE;           // 0000

    // 移位运算 << >>
#define FLAG_1 1 << 0  // 0001
#define FLAG_2 1 << 1  // 0010
#define FLAG_3 1 << 2  // 0100

    int x = 1000;
    x *= 2;
    x <<= 1;  // CPU 执行效率更高
    x /= 2;
    x >>= 1;

    // , 运算符，取后面表达式的值？
    int z = 1;
    z = z * 2, z = z + 3;
    printf("z is: %d\n", z);
    return 0;
}