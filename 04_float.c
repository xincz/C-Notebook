#include <stdio.h>

int main() {
    // 默认 3.14 为双精度，写成 3.14f 为单精度
    float a_float = 3.14f;   // 单精度  6 (7~8) 位有效数字  -1e-37 ~ +1e^37
    printf("size of float: %d\n", sizeof(float));
    double a_double = 3.14;  // 双精度  15~16位有效数字
    printf("size of double: %d\n", sizeof(double));

    // 浮点型是科学计数法的数字
    // 32位怎么分割？
    // 8位用来表示指数
    // 23位表示尾数
    // 1位为隐含位 (e)
    float lat = 39.90815f;
    int lat06 = (int) (lat * 1e6);  // 运算技巧
    float money = 3.14f;  // 不能用浮点数来描述钱！精度不能丢失！
    printf("%f\n", 39.908156f - lat);  // 最后一位不准确
    printf("address of float: %#x\n", &a_float);  // # 可以打出 0x
    // 注：标识符 identifier 不能为关键字
    return 0;
}