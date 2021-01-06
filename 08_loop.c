#include <stdio.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define REM '%'

int main() {
    int left;
    int right;
    char operator;
    char command;

     do {
        printf("Please input an expression: \n");
        scanf("%d %c %d", &left, &operator, &right);

        int result;
        switch (operator) {
            case ADD:
                result = left + right;
                break;
            case SUB:
                result = left - right;
                break;
            case MUL:
                result = left * right;
                break;
            case DIV:
                result = left / right;
                break;
            case REM:
                result = left % right;
                break;
            default:
                printf("Unsupported operation: %c\n", operator);
        }
        printf("Result: %d\n", result);

        printf("Again? Type 'q' for quit: \n");
        getchar();
        command = getchar();
    } while (command != 'q');

    // continue break
    int res = 0;
    for (int i=0, j=0; i<=100, j<=100; ++i, ++j) {
        if (i == 2) continue;  // 跳过
        if (i == 8) break;     // 跳出
        res += i * (i + j);
    }

    // goto
    int i = 0;
    begin:
    printf("%d\n", i);
    if (i++ < 5) {
        goto begin;
    }

    return 0;
}