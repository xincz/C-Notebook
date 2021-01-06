#include "io_utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    // 查表更效率
    PRINT_INT(isdigit('0'));
    PRINT_INT(isspace(' '));
    PRINT_INT(isalpha('a'));  // alphabet
    PRINT_INT(isalnum('f'));  // alphanumeric
    PRINT_INT(isalnum('1'));
    PRINT_INT(ispunct(','));

    // a: alphabet
    // atoX: 使用简单，适用于简单、要求不高的场景
    // Char conversion to int
    PRINT_INT(atoi("1234"));  // 1234
    PRINT_INT(atoi("-1234"));  // -1234
    PRINT_INT(atoi("    1234abcd"));  // 1234
    PRINT_INT(atoi("0x1234"));  // 0

    // Char conversion to double (MSVC)
    PRINT_DOUBLE(atof("12.34"));  // 12.34
    PRINT_DOUBLE(atof("-12e34"));  // -12e+35
    PRINT_DOUBLE(atof("  12.34abcd"));  // 12.34
    PRINT_DOUBLE(atof("0x10"));  // 16  MinGW 不支持
    PRINT_DOUBLE(atof("0x10p3.9"));  // 科学计数 16 * 2^3 = 128  MinGW 不支持

    // 可重复解析，更安全，功能更强大
    // strtol, strtoll => 有符号整型
    // strtoul, strtoull => 无符号整型
    // strtof, strtod, strtold => 浮点型
    // strtoimax, strtoumax => 所在环境中表示范围最大的整型 intmax_t / 无符号整型 uintmax_t || 在 stdint.h 中

    char const *const kInput = "1 200000000000000000000000000000 3 -4 5abcd bye";
    PRINTLNF("Parse: %s", kInput);

    char const *start = kInput;
    char *end;

    while (1) {
        errno = 0;  // 清空错误
        const long i = strtol(start, &end, 10);

        if (start == end) {
            break;
        }

        printf("'%.*s'\t ==> %ld.", (int)(end - start), start, i);

        if (errno == ERANGE) {
            perror("");
        }

        putchar('\n');
        start = end;
    }

    PRINTLNF("Left: %s", end);
    return 0;
}