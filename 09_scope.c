#include <stdio.h>

// 文件作用域 file scope
int global_var = 1;

void LocalStaticVar(void) {
    // 静态：具备文件作用域的性质
    // 会一直存在于内存中
    // 不会随函数退出而销毁
    static int static_var;
    // 自动变量 (不必写)
    // 函数和块作用域，随退出而销毁
    // 没有默认初值
    auto int non_static_var;

    // gcc 运行时两者完全一样
    // 每次调用完，没有做任何事情
    // 下次调用时仍然分配了相同的栈内存
    // 不然的话，第二行会打出 “烫烫烫”
    printf("static var: %d\n", static_var++);
    printf("non-static var: %d\n", non_static_var++);
}

void ClearMemory(void) {
    int eraser = -1;
}

// 表示不接受参数，最好写上 void
// puts 写到标准输出
void EmptyParamList() {
    puts("Hello");
}

// 写了函数签名就可以直接调用
void SomeFunc(void);

// 形参名不写也是可以的
// 函数返回值没写默认是 int
int Add(int, int);

// proto scope
double Sort(int size, int array[size]);

// 寄存器 register
// 比内存性能高很多
// 减少一次内存访问
void PassByMemory(int p) {
    printf("%d\n", p);
}
void PassByRegister(register int p) {
    printf("%d\n", p);
}

// function scope
int main(void) {
    // 仍然可以照常运行
    // C++ 中会报错
    EmptyParamList();
    EmptyParamList(1);
    EmptyParamList(1.f, "Hello");
//    SomeFunc();
    LocalStaticVar();
    ClearMemory();
    LocalStaticVar();
    ClearMemory();
    LocalStaticVar();

    // 块作用域 block scope
    // 自动变量
    // auto 自动内存的分配和销毁
    auto int value = 0;

    {  // 只能在里面访问
        auto int a = 0;
    }

    // if else 中即使不写括号也有作用域

    return 0;
}