#include <io_utils.h>

#define OP_PRINT_INT 0
#define OP_PRINT_DOUBLE 1
#define OP_PRINT_STRING 2

typedef union Operand {  // 名字
    int int_operand;
    double double_operand;
    char *string_operand;
} Operand;  // 类型

typedef struct Instruction {
    int operator;
    Operand operand;
} Instruction;

void Process(struct Instruction *instruction) {
    switch (instruction->operator) {
        case OP_PRINT_INT: PRINT_INT(instruction->operand.int_operand);
            break;
        case OP_PRINT_DOUBLE: PRINT_DOUBLE(instruction->operand.double_operand);
            break;
        case OP_PRINT_STRING: puts(instruction->operand.string_operand);
        default:
            fprintf(stderr, "Unsupported operator: %d\n", instruction->operator);
    }
}

int main() {
    PRINT_INT(sizeof(Operand));

    // 共享内存，前面的 int 被覆盖了
    // 互斥使用场景
    Operand operand = {.int_operand=5, .double_operand=2.0};
    PRINT_INT(operand.int_operand);
    PRINT_DOUBLE(operand.double_operand);

    Instruction instruction = {
        .operator = OP_PRINT_STRING,
        .operand = {
            .string_operand = "Hello World!"
        }
    };

    Process(&instruction);
    return 0;
}