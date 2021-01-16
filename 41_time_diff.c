#include "io_utils.h"
#include "time_utils.h"
#include <time.h>

#define PI 3.1415926

void DoHardWork() {
    double sum = 0;
    for (int i=0; i<1000000; i++) {
        sum += i * i / PI;
    }
    PRINT_DOUBLE(sum);
}

int main() {
    // clock() 返回的时处理器消耗的时间，更真实地反应程序运行时间
    // time() 返回的是系统时间，更适合描述真实世界

    long_time_t start_time = TimeInMillisecond();
    DoHardWork();
    long_time_t end_time = TimeInMillisecond();

//    double diff = difftime(start_time, end_time);

    PRINT_LLONG(end_time - start_time);

    // 处理器时间
    clock_t start_time_c = clock();
    DoHardWork();
    clock_t end_time_c = clock();
    PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);

    return 0;
}