#include <stdio.h>

/*
 * 1. #ifdef  如果定义了
 * 2. #ifndef 如果没定义
 * 3. #if     如果
 *
 * #elif
 * #endif
 *
 * defined(MACRO) == ifdef MACRO
 */

//#define DEBUG

// 常用于调试信息
void dump(char *message) {
#ifdef DEBUG
    puts(message);
#endif
}

#ifdef __cplusplus
extern "C" {
#endif
int Add(int left, int right);
#ifdef __cplusplus
extern };
#endif


int main() {
    dump("main start");
    dump("main end");

    printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__);
    return 0;
}
