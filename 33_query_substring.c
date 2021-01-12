#include "io_utils.h"
#include <string.h>
#include <stdlib.h>

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

    // Tokenize
    char string2[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";

    typedef struct {
        char *name;
        int year;
    } Language;

    const char *language_break = ";";
    const char *field_break = ",";

    int language_capacity = 3;
    int language_size = 0;
    Language *languages = malloc(sizeof(Language) * language_capacity);
    if (!languages) {
        abort();
    }

    char *next = strtok(string, field_break);

    while (next) {
        Language language;
        language.name = next;
        next = strtok(NULL, language_break);  // 状态是保存的，NULL 代表可以继续拆分之前的字符串
        if (next) {
            language.year = atoi(next);
            if (language_size + 1 >= language_capacity) {
                language_capacity *= 2;
                languages = realloc(languages, sizeof(Language) * language_capacity);
                if (!languages) {
                    abort();
                }
            }
            languages[language_size++] = language;
            next = strtok(NULL, field_break);
        }
    }

    PRINTLNF("languages: %d", language_size);
    PRINTLNF("languages capacity: %d", language_capacity);

    for (int i=0; i<language_size; i++) {
        PRINTLNF("Language[name=%s, year=%d]",
                  languages[i].name,
                  languages[i].year);
    }

    free(languages);

    // string concatenation
    char src[] = "HelloWorld";
    char dest[20] = "C said: ";
    strcat(dest, src);  // 追加
    strcpy(dest + strlen(dest), src);  // 也可以
    puts(dest);
    return 0;
}
