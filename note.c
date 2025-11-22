#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>
#include <stdalign.h>
#include <assert.h>
#include <limits.h>

// ====================================

#include <time.h>

#if defined(_WIN32) || defined(_WIN64)

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>


#ifndef CLOCK_REALTIME
    #define CLOCK_REALTIME 0
    #define CLOCK_MONOTONIC 1
#endif


int clock_gettime(int clk_id, struct timespec* tp) {
    if (clk_id == CLOCK_REALTIME) {
        FILETIME ft;
        ULARGE_INTEGER li;
        GetSystemTimeAsFileTime(&ft);
        li.LowPart = ft.dwLowDateTime;
        li.HighPart = ft.dwHighDateTime;
        // Convert to Unix epoch
        li.QuadPart -= 116444736000000000ULL;
        tp->tv_sec = (time_t)(li.QuadPart / 10000000ULL);
        tp->tv_nsec = (long)((li.QuadPart % 10000000ULL) * 100);
        return 0;
    } else if (clk_id == CLOCK_MONOTONIC) {
        static LARGE_INTEGER freq;
        static BOOL initialized = FALSE;
        LARGE_INTEGER count;

        if (!initialized) {
            QueryPerformanceFrequency(&freq);
            initialized = TRUE;
        }

        QueryPerformanceCounter(&count);
        tp->tv_sec = (time_t)(count.QuadPart / freq.QuadPart);
        tp->tv_nsec = (long)(((count.QuadPart % freq.QuadPart) * 1000000000ULL) / freq.QuadPart);
        return 0;
    } else {
        return -1; // Unsupported clock
    }
}

#endif

int get_last_bit(int n) {
    return n & 1;
}

/**
 * @brief Get the first bit object
 * 
 * if first bit is 0. it is a postive number.
 * else is 1, it is a negative number.
 * 
 * @param n 
 * @return int 
 */
int get_first_bit(int n) {
    return -(n >> 31);
}

int get_last_n_bit(int n, int m) {
    if (m > 32) m = 32;
    int k = n & 1;
    for (int i = 0; i < m-1; i++) {
        n >>= 1;
        k = n & 1;
    }
    return k;
}

int get_first_n_bit(int n, int m) {
    if (m > 32) m = 32;
    int k = -(n >> 31);
    for (int i = 0; i < m-1; i++) {
        n <<= 1;
        k = -(n >> 31);
    }
    return k;
}

int main(void) {
    printf("%d\n", get_last_n_bit(INT_MAX, 32));
    printf("%d\n", get_first_n_bit(INT_MIN, 32));
    return 0;
}