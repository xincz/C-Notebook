#include "io_utils.h"
#include <string.h>
#include <stdlib.h>

int main() {
//    memcpy();
//    memchr();
//    memcmp();
    char *mem = malloc(10);  // 不能确保初始值为 0
    memset(mem, 0, 10);
    PRINT_INT_ARRAY(mem, 10);
    free(mem);

//    memmove();  // 使用场景：内存覆盖
    char src[] = "HelloWorld";
    char *dest = malloc(11);
    memset(dest, 0, 11);
    memcpy(dest, src, 11);
    puts(dest);
    // 内存重叠
    memmove(dest+3, dest+1, 4);
    puts(dest);
    free(dest);
    return 0;
}
