#define _XOPEN_SOURCE

#include "io_utils.h"
#include "time_utils.h"
#include <time.h>

int main() {
    long_time_t current_time_ms = TimeInMillisecond();
    int current_time_millisecond = current_time_ms % 1000;
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

    // 字符串可读性强的时间
    puts(asctime(calendar_time));
    puts(ctime(&current_time));

    // 中国人习惯的时间
    char current_time_s[20];
    size_t size = strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
//    size_t size = strftime(current_time_s, 20, "%F %T", calendar_time);
    PRINT_INT(size);
    puts(current_time_s);

    // 全接起来用做文件名
    size_t size1 = strftime(current_time_s, 20, "%Y%m%d%H%M%S", calendar_time);
    // 追加毫秒
    sprintf(current_time_s + 14, "%03d", current_time_millisecond);
    PRINT_INT(size1);
    puts(current_time_s);

    // Parse time
    char *time = "2021-01-16 93:97:30.123";  // 需要进位
    struct tm parsed_time;
    int millisecond;
//    char *unparsed_string = strptime(current_time_s, "%F %T", &parsed_time);
    scanf(time, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
          &parsed_time.tm_year,
          &parsed_time.tm_mon,
          &parsed_time.tm_mday,
          &parsed_time.tm_hour,
          &parsed_time.tm_min,
          &parsed_time.tm_sec,
          &millisecond);
    parsed_time.tm_year -= 1900;
    parsed_time.tm_mon -= 1;

    mktime(&parsed_time);

//    PRINT_INT(parsed_time->tm_year);  // 121 -> 2021
//    PRINT_INT(parsed_time->tm_mon);   // 0   -> 一月
//    PRINT_INT(parsed_time->tm_mday);
//    PRINT_INT(parsed_time->tm_hour);
//    PRINT_INT(parsed_time->tm_min);
//    PRINT_INT(parsed_time->tm_sec);

//    puts(unparsed_string);
//
//    sscanf(unparsed_string, ",%3d", &millisecond);
    PRINT_INT(millisecond);



    return 0;
}