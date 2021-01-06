#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils.h"

// gcc  | typeof()
// msvc | decltype() in C++
#define SWAP(a, b, type) do { type temp = a; a = b; b = temp; } while (0)
#define SWAP_GCC(a, b) do { typeof(a) temp = a; a = b; b = temp; } while (0)


void SwapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Swap(void *first, void *second, size_t size) {
    void *temp = malloc(size);
    if (temp) {
        // memcpy 内存拷贝
        memcpy(temp, first, size);
        memcpy(first, second, size);
        memcpy(second, temp, size);
        free(temp);
    } else {
        // ...
    }
}


int main() {
    int a = 1;
    int b = 0;

    SwapInt(&a, &b);
    PRINT_INT(a);
    PRINT_INT(b);

    double c = 1.0;
    double d = 3.0;

//    SwapInt(&c, &d);
    PRINT_DOUBLE(c);
    PRINT_DOUBLE(d);

    Swap(&c, &d, sizeof(double));
    PRINT_DOUBLE(c);
    PRINT_DOUBLE(d);

    SWAP(a, b, int);
    SWAP_GCC(c, d);
    PRINT_INT(a);
    PRINT_INT(b);
    PRINT_DOUBLE(c);
    PRINT_DOUBLE(d);

    return 0;
}