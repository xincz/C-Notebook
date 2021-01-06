#include <stdio.h>

#define COLOR 0x112233

int main() {
    // Read only: const <type>
    // 只要是用了内存的，即可修改
    const int color = 0x112233;

    // 强制修改
    int *p_color = &color;
    *p_color = 0;
    printf("color: %d\n", color);

    // macro
    printf("COLOR: %d\n", COLOR);

    #undef COLOR
    // COLOR 不存在了！

    // 字面量 literal 才是常量
    3;
    3u;
    3l;
    3.f;
    3.9;
    'c';
    "cs";
    L'中';    // 宽字符
    L"中国";  // 宽字符串
    return 0;
}