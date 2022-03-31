#include <algorithm>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <functional>
#include <fstream>

#include "../../Clock/Clock.hpp"

template < typename Iterator, typename T >
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result = std::accumulate(first, last, result); // !
    }
};

template < typename Iterator, typename T >
T parallel_accumulate(Iterator first, Iterator last, T init, size_t num_threads)
{
    const std::size_t length = std::distance(first, last);

    if (!length)
        return init;

    const std::size_t block_size = length / num_threads;

    std::vector < T > results(num_threads);
    std::vector < std::thread > threads(num_threads - 1);

    Iterator block_start = first;

    for (std::size_t i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);

        threads[i] = std::thread(
            accumulate_block < Iterator, T >(),
            block_start, block_end, std::ref(results[i])); // !

        block_start = block_end;
    }

    accumulate_block < Iterator, T >()(block_start, last, results[num_threads - 1]);

    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
    std::ofstream ofs;
    ofs.open("./Problem2/data.csv", std::ofstream::out | std::ofstream::trunc); // clean up file
    ofs << "N,time\n";
    ofs.close();

    std::vector < int > v1(200'000'000);
    std::iota(v1.begin(), v1.end(), 1);

    for (auto num_threads = 1; num_threads != 1000; ++num_threads)
    {
        Clock::start();
        parallel_accumulate(v1.begin(), v1.end(), 0, num_threads);
        Clock::stop();
        Clock::printElapsed();

        std::ofstream ofs;
        ofs.open("./Problem2/data.csv", std::ios::app);
        ofs << num_threads << "," << Clock::getDuration().count() << '\n';
        ofs.close();
    }

    return EXIT_SUCCESS;
}