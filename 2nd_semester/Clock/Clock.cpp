#include "Clock.hpp"
#include <iostream>
#include <chrono>

void Clock::start()
{
    m_start = std::chrono::steady_clock::now();
}

void Clock::stop()
{
    m_end = std::chrono::steady_clock::now();
}

void Clock::printElapsed()
{
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start) << '\n';
}
