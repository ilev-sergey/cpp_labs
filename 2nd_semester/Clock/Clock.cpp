#include "Clock.hpp"
#include <iostream>
#include <chrono>

std::chrono::steady_clock::time_point Clock::m_start = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point Clock::m_end = std::chrono::steady_clock::now();
std::chrono::milliseconds Clock::m_duration = std::chrono::milliseconds(0);

void Clock::start()
{
    m_start = std::chrono::steady_clock::now();
}

void Clock::stop()
{
    m_end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start);
    m_duration = duration;
}

void Clock::printElapsed()
{
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start) << '\n';
}

std::chrono::milliseconds Clock::getDuration()
{
    return m_duration;
}
