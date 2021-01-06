#include "io_utils.h"
#include <string.h>

int main() {
    char *string = "Hello World!";
    char *result = strchr(string, 'l');
    char *resultr = strrchr(string, 'l');  // reversed query
    puts(result);
    puts(resultr);

    // string position break
    // query multiple strings
    char *string1 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
    char **break_set = ",;";

    int count = 0;
    char *p = string1;

    do {
        p = strpbrk(p, break_set);
        if (p) {
            puts(p);
            p++;
            count++;
        }
    } while (p);

    PRINTLNF("Found %d characters!", count);

    // query substring
    char *substring_position = strstr(string, "Wor");
    puts(substring_position);
    PRINT_INT(substring_position - string);
    return 0;
}
