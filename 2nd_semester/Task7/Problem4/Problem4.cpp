#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <functional>
#include <fstream>
#include <execution>

#include "../../Clock/Clock.hpp"

template <typename Func, typename ... Args>
void seq_vs_par(std::string name, Func function, Args ... args)
{
    std::string path = "./Problem4/" + name;
    std::ofstream ofs;
    ofs.open(path, std::ofstream::out | std::ofstream::trunc); // clean up file
    ofs << "N,seq,par\n";
    ofs.close();

    for (auto size = 1'000'000; size < 10'000'000; size += 1'000'000)
    {
        std::vector<double> s_vector(size);
        std::iota(s_vector.begin(), s_vector.end(), 0.1);

        Clock::start();
        function(std::execution::seq, s_vector.begin(), s_vector.end(), args ...);
        Clock::stop();

        std::ofstream ofs;
        ofs.open("./Problem4/for_each.csv", std::ios::app);
        ofs << size << "," << Clock::getDuration().count();
        ofs.close();

        std::vector<double> p_vector(size);
        std::iota(p_vector.begin(), p_vector.end(), 0.1);

        Clock::start();
        function(std::execution::par, p_vector.begin(), p_vector.end(), args ...);
        Clock::stop();

        ofs.open("./Problem4/for_each.csv", std::ios::app);
        ofs << "," << Clock::getDuration().count() << '\n';
        ofs.close();
    }
}

int main()
{
    seq_vs_par(std::string{ "for_each.csv" }, [](auto x, auto y, auto z, auto p) { std::for_each(x, y, z, p); } /*static_cast<void()>(std::for_each)*/, [](auto x) { x = x * x; });

    return EXIT_SUCCESS;
}