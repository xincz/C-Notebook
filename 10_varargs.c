#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...) {
    // 获取变长参数
    va_list args;
    // 开始遍历
    va_start(args, arg_count);
    for (int i=0; i<arg_count; i++) {
        // 去除对应参数：va_list, type
        int arg = va_arg(args, int);
        printf("%d: %d\n", i ,arg);
    }
    // 结束遍历
    va_end(args);
}

int main(void) {
    printf("Hello World\n");
    HandleVarargs(4, 1, 2, 3, 4);
    return 0;
}