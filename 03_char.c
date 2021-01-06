#include <stdio.h>

int main() {
    // *** 窄字符 ***
    // 字符集 ASCII
    // char 本质上是 int
    // 占用一个字节
    char a = 'a';  // 97
    char char_1 = '1';  // 49
    char char_0 = '0';  // 48

    char i = 0;  // Null char \0

    // 所有字符可以用 \ + 对应整数 来表示 (转译字符)
    // \ 后为 8 进制！
    char newline = '\n';  // newline
    char back = '\b';     // backspace
    char retn = '\r';     // return
    char tab = '\t';      // table 制表符
    char litc = '\'';     // char literal 字符字面量
    char lits = '\"';     // string literal 字符串字面量
    char char_a_escape_oct = '\141';
    char char_a_escape_hex = '\x61';

    printf("char a: %d\n", a);
    printf("char 1: %d\n", char_1);
    printf("char i: %d\n", i);

    printf("char 1: %c\n", char_1);
    printf("char 1: %x\n", &char_1);

    printf("char a oct: %c\n", char_a_escape_oct);
    printf("char a hex: %c\n", char_a_escape_hex);

    // *** 宽字符 ***
    // Unicode CJK  中日韩统一表意文字
    // 码点 code point
    // Windows 主要支持 GBK
    // C95
    // wchar_t 为 unsigned short  2 字节
    wchar_t zhong = L'中';
    wchar_t zhong_hex = L'\u4E2D';
    printf("中: %d\n", zhong);
    printf("中: %d\n", zhong_hex);
    return 0;
}
