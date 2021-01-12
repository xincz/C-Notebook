#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "io_utils.h"

int main() {
    // 宽字符串相应函数
    // support for wide string +w
    {
        PRINT_BOOL(iswalpha(L"A"));
        PRINT_BOOL(iswdigit(L"2"));

        // strlen => wcslen
        wchar_t *wcs = L"你好吗";
        size_t length = wcslen(wcs);
        PRINT_INT(length);

        wchar_t src[] = L"HelloWorld";
        wchar_t *dest = malloc(sizeof(wchar_t)*11);
        wmemset(dest, 0, 11);
        wmemcpy(dest, src, 11);
        wprintf(dest, src, 11);
        wprintf(dest);
        wmemcpy(dest + 3, dest + 1, 4);
        wprintf(dest);
        free(dest);
    }

    // encoding conversions
    char *new_locale = setlocale(LC_ALL, "zh_CN.utf8");
    if (new_locale) {
        puts(new_locale);
    }

    // mb multibytes 多字节 对应的是窄字符
    // mbs multibytes string 窄字符串
    // wc wide character 宽字符
    // wcs wide character string 宽字符串
    {
        char mbs[] = "你好";
        wchar_t wcs[10];
        mbstowcs(wcs, mbs, 10);
        wprintf(L"%s\n", wcs);
    }
    return 0;
}