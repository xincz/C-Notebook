#include <stdio.h>


static char *next = NULL;

char *custom_strtoc(char *str) {
    if (!str) {  // when str is NULL
        str = next;
    }

    int index = 0;
    while (str[index]) {
        if (str[index] == '\t' || str[index] == '\n' || str[index] == ' ') {
            str[index] = '\0';
            if (str[0]) {
                next = str + index + 1;
                return str;
            } else {
                str = str + 1;
            }
        } else {
            index++;
        }
    }
    next = str + index;
    if (str[0] == '\0') {
        return NULL;
    }
    return str;
}


int main() {

    char a[] = "split me";
    char b[] = " split\t \nme\nagain";
    char c[] = "this \nis the third\ttime ";

    char z = '\0';
    char *zz = &z;

    if (zz) {
        puts("1");
    }

    if (zz[0] == '\0') {
        puts("aaa");
    }

    printf("%s\n", custom_strtoc(a));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));

    printf("%s\n", custom_strtoc(b));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));

    printf("%s\n", custom_strtoc(c));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));
    printf("%s\n", custom_strtoc(NULL));

    return 0;
}