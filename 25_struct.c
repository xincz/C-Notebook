#include <stdio.h>
#include "io_utils.h"

int main() {
    /*
     * struct <name> {
     *   <member type> <member name>;
     *   ...
     * } <struct var>;
     */

    // 重复使用时需要定义变量名
    struct Person {
        char *name;
        int age;
        char *id;
    };  // person;  // 定义结构体的同时也定义了变量
    // . 成员选择运算符
    struct Person person = {.name="haha", .id="12223311"};
    person.age = 30;

    PRINT_HEX(person);

    struct {  // 结构体名字非必须
        char *name;
        int age;
        char *id;
    } anonymous_person;

    struct Person *person_ptr = &person;
    puts(person_ptr->name);

    PRINT_INT(sizeof(struct Person));
//    PRINT_INT(sizeof(person));

    // typedef 方便使用结构体类型！
    typedef struct Person Person;

    Person person1 = {};

    // 结合起来：更好的方式
    typedef struct Company {
        char *name;
        char *id;
        char *location;
    } Company;

    typedef struct CoolPerson {
        char *name;
        int age;
        char *id;
        Company *company;
        Company company1;
        struct {
            int extra;
            char *extra_ptr;
        } extra_value;
        Person *partner;
    } CoolPerson;

    Company c = {"imooc"};
    CoolPerson p = {"aoligei", 10, "11223344"};
//    p.company->name
//    p.extra_value.extra;
    p.company = &c;
    p.company1 = c;

    return 0;
}