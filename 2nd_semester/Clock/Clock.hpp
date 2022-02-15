#pragma once
#include <chrono>

class Clock
{
private:
    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;

public:
    void start();
    void stop();
    void printElapsed();
};