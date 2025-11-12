#if defined(_WIN32) || defined(_WIN64)

#include "win_time.h"

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