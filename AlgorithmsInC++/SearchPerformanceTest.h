#pragma once
#include "Windows.h"
class SearchPerformanceTest
{
public:
    void DoTests(void);
    LARGE_INTEGER GetTimeElapsed(LARGE_INTEGER startTime, LARGE_INTEGER endTime, LARGE_INTEGER freq);
};

