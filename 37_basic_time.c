#include <io_utils.h>
#include <time.h>

#include <sys/timeb.h>

#ifdef __unix__
#   include <sys/time.h>
#endif

int main() {
    // 表示时间的类型
    time_t;  // epoch 开始
    clock_t;  // 进程所消耗的处理器的时间
    struct tm;  // related to time zone
    struct timespec;  // C11; MSVC  nanoseconds
    struct timeb;  // milliseconds
#ifdef __unix__
    struct timeval;  // microseconds
#endif

    return 0;
}