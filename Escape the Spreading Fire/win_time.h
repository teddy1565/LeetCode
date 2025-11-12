#define _CRT_SECURE_NO_WARNINGS

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#include <time.h>

#ifndef CLOCK_REALTIME
    #define CLOCK_REALTIME 0
    #define CLOCK_MONOTONIC 1
#endif

int clock_gettime(int clk_id, struct timespec* tp);