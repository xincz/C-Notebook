//
// Created by lxinp on 2021/1/16.
//

#ifndef HELLOWORDC_TIME_UTILS_H
#define HELLOWORDC_TIME_UTILS_H

#if defined(_WIN32)
#include <sys/timeb.h>
#elif defined(__unix__)
#include <sys/time.h>
#endif

typedef long long long_time_t;

long_time_t TimeInMillisecond(void) {
#if defined(_WIN32)
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * 1000LL + time_buffer.millitm;
#elif defined(__unix__)
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    return time_value.tv_sec * 1000LL + time_value.tv_usec / 1000;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L
    struct timespec timespec_value;
    timespec_get(&timespec_value, TIME_UTC);
    return timespec_value.tv_sec * 1000LL + timespec_value.tv_nsec / 1000000;
#else
    time_t current_time = time(NULL);
    return current_time * 1000LL;
#endif
}

#endif //HELLOWORDC_TIME_UTILS_H
