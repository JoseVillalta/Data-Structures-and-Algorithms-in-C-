#pragma once
#include "Windows.h"


static LARGE_INTEGER GetTimeElapsed(LARGE_INTEGER startTime, LARGE_INTEGER endTime, LARGE_INTEGER freq)
{
    LARGE_INTEGER elapsedTime;
    elapsedTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
    elapsedTime.QuadPart *= 1000000;
    elapsedTime.QuadPart /= freq.QuadPart;
    return elapsedTime;

}