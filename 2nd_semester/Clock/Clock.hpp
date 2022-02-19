#pragma once
#include <chrono>

class Clock
{
private:
    static std::chrono::steady_clock::time_point m_start;
    static std::chrono::steady_clock::time_point m_end;
    static std::chrono::milliseconds m_duration;

public:
    static void start();
    static void stop();
    static void printElapsed();
    static std::chrono::milliseconds getDuration();
};