#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

class Clock
{
private:
    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;

public:
    void start()
    {
        m_start = std::chrono::steady_clock::now();
    }

    void stop()
    {
        m_end = std::chrono::steady_clock::now();
    }

    void printElapsed()
    {
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start) << '\n';
    }
};

int main()
{
    Clock clock;
    const int length = 10e5;
    std::vector<int> vector(length);

    clock.start();
    for (auto i = 0; i < length; ++i)
    {
        vector[i] = length - i;
    }
    clock.stop();
    clock.printElapsed();

    clock.start();
    std::sort(vector.begin(), vector.end());
    clock.stop();
    clock.printElapsed();

    return EXIT_SUCCESS;
}