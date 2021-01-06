#include <stdio.h>
#include "io_utils.h"


int main() {
    // 字符串本质上就是数组
//    char string[11] = "Hello World";  // 最后其实有 \0 字符
    char string[12] = "Hello World";  // 最后其实有 \0 字符
    for (int i=0; i<11; i++) {
        PRINT_CHAR(string[i]);
    }

    // short %hd
    // %s 对应的 C 语言中的字符串跟字符数组有区别
    // C 语言中的字符串必须以 NULL 结尾 \0
    PRINTLNF("%s", string);

    // 中文
    char string_zh[] = "你好，中国";
    // wchar_t 存储码点，最后也是以 \000 结尾
    wchar_t ws[] = L"你好，中国";

    return 0;
}
