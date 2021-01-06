#include <stdio.h>
#include <stdbool.h>

int main() {
    // Bool
    // _Bool, bool
    _Bool is_enabled = true;  // 强制编译为 1 或 0
    is_enabled = 10;
    printf("is_enabled: %d\n", is_enabled);

    // macro of _Bool
    bool is_visible = false;

    // condition
#define MAGIC_NUMBER 10
    int user_input;
    scanf("%d\n", &user_input);  // 写到地址
    if (user_input > MAGIC_NUMBER) {
        printf("lol");
    }

    int is_open = is_enabled && is_visible ? 1 : 0;

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define REM '%'

    int left;
    int right;
    char operator;
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
    return 0;
}