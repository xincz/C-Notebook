#include <stdio.h>
#include <stdarg.h>

void Printlnf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

// string"" 可以自动拼接字符串
// 如果不想传入参数，可以加上 ## 则逗号会被自动去掉
#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINTLND(format, ...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

// 加上 # 会替换为对应的变量名
#define PRINT_INT(value) PRINTLNF(#value": %d", value)

// MACRO 预定义值
// __FILE__
// __LINE__
// __FUNCTION__  编译时才有值

int main() {
    Printlnf("Hello %d", 1);
    PRINTLNF("Hello %d", 1);
    PRINTLNF("Hello %d");
    PRINTLND("Hello %d", 1);

    int value = 100;
    int x = 3;
    PRINT_INT(value);
    PRINT_INT(x);
    PRINT_INT(3 + 4);

    return 0;
}