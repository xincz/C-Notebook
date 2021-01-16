#include "io_utils.h"
#include "time_utils.h"
#include <time.h>

int main() {
    time_t current_time;
    time(&current_time);
    PRINT_LLONG(current_time);
    struct tm *calendar_time = localtime(&current_time);
    PRINT_INT(calendar_time->tm_year);  // 121 -> 2021
    PRINT_INT(calendar_time->tm_mon);   // 0   -> 一月
    PRINT_INT(calendar_time->tm_mday);
    PRINT_INT(calendar_time->tm_hour);
    PRINT_INT(calendar_time->tm_min);
    PRINT_INT(calendar_time->tm_sec);

    calendar_time->tm_sec = 70;  // 不会完成进位
    // 为了进位，使用此方法
    time_t current_time2 = mktime(calendar_time);  // mktime 可以对时间规范化
    PRINT_LLONG(current_time2);
    PRINT_INT(calendar_time->tm_year);  // 121 -> 2021
    PRINT_INT(calendar_time->tm_mon);   // 0   -> 一月
    PRINT_INT(calendar_time->tm_mday);
    PRINT_INT(calendar_time->tm_hour);
    PRINT_INT(calendar_time->tm_min);
    PRINT_INT(calendar_time->tm_sec);

    struct tm *gmt = gmtime(&current_time);  // 格林威治时间，零时区
    PRINT_INT(gmt->tm_year);  // 121 -> 2021
    PRINT_INT(gmt->tm_mon);   // 0   -> 一月
    PRINT_INT(gmt->tm_mday);
    PRINT_INT(gmt->tm_hour);
    PRINT_INT(gmt->tm_min);
    PRINT_INT(gmt->tm_sec);

    return 0;
}